#pragma once

#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QtWidgets/QWidget>
#include <QList>

class CPlotWidget : public QWidget
{
	Q_OBJECT

public slots:
	void addReading(const QList<double>& value);

public:
	CPlotWidget(QWidget *parent = Q_NULLPTR);

    void SetMax(double max);
    void SetMin(double min);
	
	void paintEvent(QPaintEvent* e);
	void resizeEvent(QResizeEvent* e);

private:
    double                  m_plotWidth;
    double                  m_plotMax;
    double                  m_plotMin;
	QList<QList<double>>	m_plotValues;
	bool					m_showGrid;
	bool					m_boldCenterline;
};
#endif //PLOTWIDGET_H
