#include "plotWidget.h"

#include <QPainter>
#include <QPaintEvent>


CPlotWidget::CPlotWidget(QWidget *parent)
{

}

void CPlotWidget::paintEvent(QPaintEvent* e)
{
	QWidget::paintEvent(e);

	QRect r = e->rect();

	QPainter painter(this);
	painter.setBrush(palette().brush(QPalette::ColorRole::Dark));
	painter.drawRect(r);
}
