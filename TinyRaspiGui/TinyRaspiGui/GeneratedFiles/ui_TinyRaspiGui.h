/********************************************************************************
** Form generated from reading UI file 'TinyRaspiGui.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TINYRASPIGUI_H
#define UI_TINYRASPIGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TinyRaspiGuiClass
{
public:

    void setupUi(QWidget *TinyRaspiGuiClass)
    {
        if (TinyRaspiGuiClass->objectName().isEmpty())
            TinyRaspiGuiClass->setObjectName(QStringLiteral("TinyRaspiGuiClass"));
        TinyRaspiGuiClass->resize(600, 400);

        retranslateUi(TinyRaspiGuiClass);

        QMetaObject::connectSlotsByName(TinyRaspiGuiClass);
    } // setupUi

    void retranslateUi(QWidget *TinyRaspiGuiClass)
    {
        TinyRaspiGuiClass->setWindowTitle(QApplication::translate("TinyRaspiGuiClass", "TinyRaspiGui", 0));
    } // retranslateUi

};

namespace Ui {
    class TinyRaspiGuiClass: public Ui_TinyRaspiGuiClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TINYRASPIGUI_H
