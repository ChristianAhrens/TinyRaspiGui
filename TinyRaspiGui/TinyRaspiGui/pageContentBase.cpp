#include "pageContentBase.h"

#include "plotWidget.h"

#include <QtWidgets/QBoxLayout>
#include <QTimer>


APageContentBase::APageContentBase(QWidget *parent)
{
	m_layout = new QVBoxLayout;
	m_layout->setContentsMargins(4, 4, 4, 4);
	m_layout->setSpacing(4);
	setLayout(m_layout);
}


CPageContentPlotting::CPageContentPlotting(QWidget *parent)
	: APageContentBase(parent)
{
	CPlotWidget* plot1 = new CPlotWidget;
	CPlotWidget* plot2 = new CPlotWidget;

	Q_ASSERT(qobject_cast<QVBoxLayout*>(layout()));
	qobject_cast<QVBoxLayout*>(layout())->addWidget(plot1, 2);
	qobject_cast<QVBoxLayout*>(layout())->addWidget(plot2, 2);

	QTimer* t = new QTimer;
	t->setInterval(500);
	connect(t, SIGNAL(timeout()), plot1, SLOT(addValue()));
	connect(t, SIGNAL(timeout()), plot2, SLOT(addValue()));
	t->start();
}
