#-------------------------------------------------
#
# Project created by QtCreator 2019-04-28T21:33:43
#
#-------------------------------------------------

VERSION = 1.0.2

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dictionary_filler
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

DEFINES += PROGRAM_VERSION=\\\"$${VERSION}\\\"

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        Gui/mainwindow.cpp \
    Gui/GuiInterface/guiinterface.cpp \
    Gui/GuiInterface/guicommandsinterface.cpp \
    WordsFinder/abstractwordsfinder.cpp \
    WordsFinder/wordsfindereventsinterface.cpp \
    WordsDictionary/abstractwordsdictionary.cpp \
    WordsDictionaryModel/WordsDictionaryModel.cpp \
    AppFabric/AbstractAppFabric.cpp \
    AppFabric/WinWidgetsAppFabric.cpp \
    WordsDictionary/WordsDictionary1.cpp \
    WordsFinder/WordsFinder1/wordsfinder1.cpp \
    AppController.cpp \
    WordsFinder/cfindererrortype.cpp \
    WordsFinder/WordsFinder1/findwords1worker.cpp \
    CBasicErrorType.cpp \
    AppInfo/capplicationinfo.cpp \
    Gui/aboutwindow.cpp \
    Gui/Delegates/SpeachPartsDelegate.cpp \
    Gui/Delegates/speachpartswidget.cpp

HEADERS += \
        Gui/mainwindow.h \
    Gui/GuiInterface/guiinterface.h \
    Gui/GuiInterface/guicommandsinterface.h \
    WordsFinder/abstractwordsfinder.h \
    WordsFinder/wordsfindereventsinterface.h \
    WordsDictionary/abstractwordsdictionary.h \
    WordsDictionaryModel/WordsDictionaryModel.h \
    AppFabric/AbstractAppFabric.h \
    AppFabric/WinWidgetsAppFabric.h \
    WordsDictionary/WordsDictionary1.h \
    WordsFinder/WordsFinder1/wordsfinder1.h \
    appconfig.h \
    AppController.h \
    CBasicErrorType.h \
    WordsFinder/cfindererrortype.h \
    WordsFinder/WordsFinder1/findwords1worker.h \
    AppInfo/capplicationinfo.h \
    Gui/aboutwindow.h \
    Gui/Delegates/SpeachPartsDelegate.h \
    Gui/Delegates/speachpartswidget.h

FORMS += \
        Gui/mainwindow.ui \
    Gui/aboutwindow.ui \
    Gui/Delegates/speachpartswidget.ui

RESOURCES += \
    resources.qrc

