#pragma once

#ifndef PAGECONTENTBASE_H
#define PAGECONTENTBASE_H

#include <QtWidgets/QWidget>

class QVBoxLayout;

class APageContentBase : public QWidget
{
	Q_OBJECT

public:
	APageContentBase(QWidget *parent = Q_NULLPTR);

private:
	QVBoxLayout*	m_layout;
};


class CPageContentPlotting : public APageContentBase
{
	Q_OBJECT

public:
	CPageContentPlotting(QWidget *parent = Q_NULLPTR);

private:

};
#endif //PAGECONTENTBASE_H
