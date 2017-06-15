#include "pageContentBase.h"

#include "plotWidget.h"
#include "procReader.h"

#include <QtWidgets/QBoxLayout>
#include <QTimer>


APageContentBase::APageContentBase(QWidget *parent)
    : QWidget(parent)
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

#ifdef QT_OS_WIN
	QString LoadAvgName = "../testFiles/proc/loadavg";
	QString NetStatName = "../testFiles/proc/net/netstat";
#else
	QString LoadAvgName = "/proc/loadavg";
	QString NetStatName = "/proc/net/netstat";

#endif

    CProcReader* proc1 = new CProcReader(LoadAvgName, LoadAvg);
    CProcReader* proc2 = new CProcReader(NetStatName, NetStat);

	connect(proc1, SIGNAL(valuesRead(const QList<double>&)), plot1, SLOT(addReading(const QList<double>&)));
	connect(proc2, SIGNAL(valuesRead(const QList<double>&)), plot2, SLOT(addReading(const QList<double>&)));

	QTimer* t = new QTimer;
	t->setInterval(500);
	connect(t, SIGNAL(timeout()), proc1, SLOT(update()));
	connect(t, SIGNAL(timeout()), proc2, SLOT(update()));
	t->start();
}
