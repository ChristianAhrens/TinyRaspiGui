#pragma once

#ifndef TINYRASPIGUI_H
#define TINYRASPIGUI_H

#include <QtWidgets/QWidget>

class QHBoxLayout;

class TinyRaspiGui : public QWidget
{
	Q_OBJECT

public:
	TinyRaspiGui(QWidget *parent = Q_NULLPTR);

private:
	void customizeStyle();

	QHBoxLayout*	m_layout;
};
#endif //TINYRASPIGUI_H
