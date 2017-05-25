#pragma once

#ifndef TINYRASPIGUI_H
#define TINYRASPIGUI_H

#include <QtWidgets/QWidget>
#include "ui_TinyRaspiGui.h"

class QHBoxLayout;

class TinyRaspiGui : public QWidget
{
	Q_OBJECT

public:
	TinyRaspiGui(QWidget *parent = Q_NULLPTR);

private:
	void customizeStyle();

	Ui::TinyRaspiGuiClass ui;

	QHBoxLayout*	m_layout;
};
#endif //TINYRASPIGUI_H
