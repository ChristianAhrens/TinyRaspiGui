#include "pageControlBase.h"

#include <QtWidgets/QPushButton>
#include <QtWidgets/QBoxLayout>


APageControlBase::APageControlBase(QWidget *parent)
{
	m_layout = new QVBoxLayout;
	m_layout->setContentsMargins(2, 2, 2, 2);
	m_layout->setSpacing(2);
	setLayout(m_layout);

	SetButton(0, new QPushButton);
	SetButtonIcon(0, this->style()->standardIcon(QStyle::SP_MediaSeekForward));
	SetButton(1, new QPushButton);
	SetButtonIcon(1, this->style()->standardIcon(QStyle::SP_MediaPlay));
	SetButton(2, new QPushButton);
	SetButtonIcon(2, this->style()->standardIcon(QStyle::SP_MediaStop));
	SetButton(3, new QPushButton);
	SetButtonIcon(3, this->style()->standardIcon(QStyle::SP_MediaPause));
}

bool APageControlBase::SetButtonText(int index, const QString& text)
{
	switch (index)
	{
	case 0:
		m_button1->setText(text);
		return true;
	case 1:
		m_button2->setText(text);
		return true;
	case 2:
		m_button3->setText(text);
		return true;
	case 3:
		m_button4->setText(text);
		return true;
	default:
		return false;
	}
}

bool APageControlBase::SetButtonIcon(int index, const QIcon& icon)
{
	switch (index)
	{
	case 0:
		m_button1->setIcon(icon);
		return true;
	case 1:
		m_button2->setIcon(icon);
		return true;
	case 2:
		m_button3->setIcon(icon);
		return true;
	case 3:
		m_button4->setIcon(icon);
		return true;
	default:
		return false;
	}
}

bool APageControlBase::SetButton(int index, QPushButton* button)
{
	switch (index)
	{
	case 0:
		m_button1 = button;
		break;
	case 1:
		m_button2 = button;
		break;
	case 2:
		m_button3 = button;
		break;
	case 3:
		m_button4 = button;
		break;
	default:
		return false;
	}

	button->setSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);

	m_layout->insertWidget(index, button, 2);

	return true;
}

QPushButton* APageControlBase::GetButton(int index)
{
	switch (index)
	{
	case 0:
		return m_button1;
	case 1:
		return m_button2;
	case 2:
		return m_button3;
	case 3:
		return m_button4;
	default:
		return 0;
	}
}