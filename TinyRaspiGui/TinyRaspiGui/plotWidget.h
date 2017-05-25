#pragma once

#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QtWidgets/QWidget>


class CPlotWidget : public QWidget
{
	Q_OBJECT

public:
	CPlotWidget(QWidget *parent = Q_NULLPTR);
	
	void paintEvent(QPaintEvent* e);

private:

};
#endif //PLOTWIDGET_H
