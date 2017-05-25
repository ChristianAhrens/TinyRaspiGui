#include "plotWidget.h"

#include <QPainter>
#include <QPaintEvent>


CPlotWidget::CPlotWidget(QWidget *parent)
{
	m_plotWidth = 0;
	m_plotMax = 100;
	m_plotMin = 0;
	m_showGrid = true;
	m_boldCenterline = false;
}

void CPlotWidget::addValue(int value)
{
	m_plotValues.push_back(value);

	while (m_plotValues.size() > m_plotWidth)
		m_plotValues.pop_front();

	update();
}

void CPlotWidget::SetMax(int max)
{
	m_plotMax = max;
}

void CPlotWidget::SetMin(int min)
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
	painter.setBrush(palette().brush(QPalette::ColorRole::Base));
	painter.drawLines(points);

	if (m_showGrid)
	{
		points.clear();
		points << QPoint(r.left(), r.top() + r.height()*0.5) << QPoint(r.right(), r.top() + r.height()*0.5);
		if (m_boldCenterline)
		{
			painter.setPen(QPen(palette().brush(QPalette::ColorRole::ToolTipText), 2, Qt::DashDotLine));
			painter.drawLines(points);
			points.clear();
		}
		points << QPoint(r.left(), r.top() + r.height()*0.25) << QPoint(r.right(), r.top() + r.height()*0.25)
				<< QPoint(r.left(), r.top() + r.height()*0.75) << QPoint(r.right(), r.top() + r.height()*0.75);
		painter.setPen(QPen(palette().brush(QPalette::ColorRole::ToolTipText), 1, Qt::DashDotDotLine));
		painter.drawLines(points);
	}

	Q_ASSERT((m_plotMax - m_plotMin)!=0);
	for (int i = 1; i <= m_plotWidth; ++i)
	{
		if (m_plotValues.size() >= i)
		{
			int px = r.right() - i;
			int py = r.top() + double(m_plotValues[m_plotValues.size() - i]) / double(m_plotMax - m_plotMin)*double(r.height());
			points.push_back(QPoint(px, py));
		}
	}
	painter.setPen(QPen(palette().brush(QPalette::ColorRole::Text), 3, Qt::SolidLine));
	painter.drawPoints(points);
}

void CPlotWidget::resizeEvent(QResizeEvent* e)
{
	m_plotWidth = e->size().width();

	return QWidget::resizeEvent(e);
}