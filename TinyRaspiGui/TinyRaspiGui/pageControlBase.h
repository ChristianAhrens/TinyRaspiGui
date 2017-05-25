#pragma once

#ifndef PAGECONTROLBASE_H
#define PAGECONTROLBASE_H

#include <QtWidgets/QWidget>
#include "ui_TinyRaspiGui.h"

class QPushButton;
class QVBoxLayout;

class APageControlBase : public QWidget
{
	Q_OBJECT

public:
	APageControlBase(QWidget *parent = Q_NULLPTR);

	bool			SetButtonText(int index, const QString& text);
	bool			SetButtonIcon(int index, const QIcon& icon);
	bool			SetButton(int index, QPushButton* button);
	QPushButton*	GetButton(int index);

private:
	QPushButton*	m_button1;
	QPushButton*	m_button2;
	QPushButton*	m_button3;
	QPushButton*	m_button4;

	QVBoxLayout*	m_layout;
};
#endif //PAGECONTROLBASE_H
