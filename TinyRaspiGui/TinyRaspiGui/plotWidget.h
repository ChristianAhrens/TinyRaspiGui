#pragma once

#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QtWidgets/QWidget>
#include <QList>

class CPlotWidget : public QWidget
{
	Q_OBJECT

public slots:
	void addValue(int value=50);

public:
	CPlotWidget(QWidget *parent = Q_NULLPTR);

	void SetMax(int max);
	void SetMin(int min);
	
	void paintEvent(QPaintEvent* e);
	void resizeEvent(QResizeEvent* e);

private:
	int			m_plotWidth;
	int			m_plotMax;
	int			m_plotMin;
	QList<int>	m_plotValues;
	bool		m_showGrid;
	bool		m_boldCenterline;
};
#endif //PLOTWIDGET_H
