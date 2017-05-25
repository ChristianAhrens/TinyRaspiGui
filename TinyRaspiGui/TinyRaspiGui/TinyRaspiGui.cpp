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
	m_layout->setContentsMargins(0,0,0,0);
	m_layout->setSpacing(0);

	m_layout->addWidget(new CPageContentPlotting, 8);
	m_layout->addWidget(new APageControlBase, 2);

	setLayout(m_layout);

	setMinimumSize(320, 240);
}

void TinyRaspiGui::customizeStyle()
{
	QPalette palette;
	palette.setColor(QPalette::Window, QColor(53, 53, 53));
	palette.setColor(QPalette::WindowText, Qt::white);
	palette.setColor(QPalette::Base, QColor(15, 15, 15));
	palette.setColor(QPalette::AlternateBase, QColor(7, 7, 7));
	palette.setColor(QPalette::ToolTipBase, Qt::white);
	palette.setColor(QPalette::ToolTipText, QColor(216,191,216)); //thistle
	palette.setColor(QPalette::Text, QColor(230, 230, 250)); //lavender
	palette.setColor(QPalette::Button, QColor(53, 53, 53));
	palette.setColor(QPalette::ButtonText, QColor(221, 160, 221)); //plum
	palette.setColor(QPalette::BrightText, QColor(238, 130, 238)); //violet
	palette.setColor(QPalette::Highlight, QColor(142, 45, 197).lighter());
	palette.setColor(QPalette::HighlightedText, QColor(255,0,255)); //magenta
	qApp->setPalette(palette);
}
