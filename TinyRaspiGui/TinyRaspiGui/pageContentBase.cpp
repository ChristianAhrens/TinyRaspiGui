#include "pageContentBase.h"

#include "plotWidget.h"

#include <QtWidgets/QBoxLayout>


APageContentBase::APageContentBase(QWidget *parent)
{
	m_layout = new QVBoxLayout;
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


}
