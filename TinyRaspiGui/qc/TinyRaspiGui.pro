#-------------------------------------------------
#
# Project created by QtCreator 2017-05-25T19:51:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TinyRaspiGui
TEMPLATE = app

INCLUDEPATH += ../include

SOURCES += ../src/main.cpp\
        ../src/TinyRaspiGui.cpp\
		../src/pageContentBase.cpp\
		../src/pageControlBase.cpp\
		../src/plotWidget.cpp\
		../src/procReader.cpp\
		
HEADERS  += ../include/TinyRaspiGui.h\
		../include/pageContentBase.h\
		../include/pageControlBase.h\
		../include/plotWidget.h\
		../include/procReader.h\

RESOURCES += ../src/TinyRaspiGui.qrc