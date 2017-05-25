#include "TinyRaspiGui.h"

#include "pageContentBase.h"
#include "pageControlBase.h"

#include <qstylefactory.h>
#include <QtWidgets/QBoxLayout>

TinyRaspiGui::TinyRaspiGui(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	qApp->setStyle(QStyleFactory::create("fusion"));

	customizeStyle();

	m_layout = new QHBoxLayout;

	m_layout->addWidget(new CPageContentPlotting, 8);
	m_layout->addWidget(new APageControlBase, 2);

	setLayout(m_layout);
}

void TinyRaspiGui::customizeStyle()
{
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(53, 53, 53));
	palette.setColor(QPalette::WindowText, Qt::white);
	palette.setColor(QPalette::Base, QColor(15, 15, 15));
	palette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
	palette.setColor(QPalette::ToolTipBase, Qt::white);
	palette.setColor(QPalette::ToolTipText, Qt::white);
	palette.setColor(QPalette::Text, Qt::white);
	palette.setColor(QPalette::Button, QColor(53, 53, 53));
	palette.setColor(QPalette::ButtonText, Qt::white);
	palette.setColor(QPalette::BrightText, Qt::red);

	palette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
	palette.setColor(QPalette::HighlightedText, Qt::black);
	qApp->setPalette(palette);
}
