#include "plotWidget.h"

#include <QPainter>
#include <QPaintEvent>


CPlotWidget::CPlotWidget(QWidget *parent)
    : QWidget(parent)
{
	m_plotWidth = 0;
    m_plotMax = 1;
	m_plotMin = 0;
	m_showGrid = true;
	m_boldCenterline = false;
}

void CPlotWidget::addReading(const QList<double>& value)
{
	if (m_plotValues.isEmpty() || m_plotValues.back() != value)
		m_plotValues.push_back(value);
	else
		m_plotValues.replace(m_plotValues.size() - 1, value);

	while (m_plotValues.size() > m_plotWidth)
		m_plotValues.pop_front();

	update();
}

void CPlotWidget::SetMax(double max)
{
	m_plotMax = max;
}

void CPlotWidget::SetMin(double min)
{
	m_plotMin = min;
}

void CPlotWidget::paintEvent(QPaintEvent* e)
{
	QWidget::paintEvent(e);

	QRect r = e->rect();

	QPainter painter(this);
	QVector<QPoint> points;
	
	points = QVector<QPoint>() << r.topLeft() << r.topRight() << r.topRight() << r.bottomRight() << r.bottomRight() << r.bottomLeft() << r.bottomLeft() << r.topLeft();
    painter.setBrush(palette().brush(QPalette::Base));
	painter.drawLines(points);

	if (m_showGrid)
	{
		points.clear();
		points << QPoint(r.left(), r.top() + r.height()*0.5) << QPoint(r.right(), r.top() + r.height()*0.5);
		if (m_boldCenterline)
		{
            painter.setPen(QPen(palette().brush(QPalette::ToolTipText), 2, Qt::DashDotLine));
			painter.drawLines(points);
			points.clear();
		}
		points << QPoint(r.left(), r.top() + r.height()*0.25) << QPoint(r.right(), r.top() + r.height()*0.25)
				<< QPoint(r.left(), r.top() + r.height()*0.75) << QPoint(r.right(), r.top() + r.height()*0.75);
        painter.setPen(QPen(palette().brush(QPalette::ToolTipText), 1, Qt::DashDotDotLine));
		painter.drawLines(points);
	}

	Q_ASSERT((m_plotMax - m_plotMin)!=0);
	for (int i = 1; i <= m_plotWidth; ++i)
	{
		if (m_plotValues.size() >= i)
		{
			int valueIndex = m_plotValues.size() - i;

			Q_ASSERT(m_plotValues.front().size() == m_plotValues[valueIndex].size());

            double px = r.right() - i;
			for (int curveIndex = 0; curveIndex<m_plotValues[valueIndex].size(); ++curveIndex)
			{
				double sample = m_plotValues[valueIndex][curveIndex];

				if (sample > m_plotMax)
					m_plotMax = sample;
				if (sample < m_plotMin)
					m_plotMin = sample;

                double py = double(r.bottom()) - sample / (m_plotMax - m_plotMin)*double(r.height());
				if (points.size() && points.back().y() != py)
					points.push_back(QPoint(px, py));

				int valueIndex_next = valueIndex + 1;
				double sample_next = valueIndex_next < m_plotValues.size() ? m_plotValues[valueIndex_next][curveIndex] : m_plotValues[valueIndex][curveIndex];

				if (sample_next > m_plotMax)
					m_plotMax = sample_next;
				if (sample_next < m_plotMin)
					m_plotMin = sample_next;

				double py_next = double(r.bottom()) - sample_next / (m_plotMax - m_plotMin)*double(r.height());
				if (points.size() && points.back().y() != py_next)
					points.push_back(QPoint(px + 1, py_next));
			}
		}
	}
    painter.setPen(QPen(palette().brush(QPalette::Text), 1, Qt::SolidLine));
    painter.drawLines(points);
}

void CPlotWidget::resizeEvent(QResizeEvent* e)
{
	m_plotWidth = e->size().width();

	return QWidget::resizeEvent(e);
}
