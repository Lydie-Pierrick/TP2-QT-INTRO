#-------------------------------------------------
#
# Project created by QtCreator 2018-02-10T11:27:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TPQtIntroduction
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialogidentification.cpp \
    dialogaddclient.cpp \
    dialogabout.cpp \
    dialogaddemployee.cpp \
    client.cpp \
    appointment.cpp \
    employee.cpp \
    controller_employee.cpp \
    controller_client.cpp \
    c_init_bd.cpp \
    accesdb.cpp

HEADERS += \
        mainwindow.h \
    dialogidentification.h \
    dialogaddclient.h \
    dialogabout.h \
    dialogaddemployee.h \
    client.h \
    appointment.h \
    employee.h \
    controller_employee.h \
    controller_client.h \
    c_init_bd.h \
    accesdb.h

FORMS += \
        mainwindow.ui \
    dialogidentification.ui \
    dialogaddclient.ui \
    dialogabout.ui \
    dialogaddemployee.ui

RESOURCES += \
    pictures.qrc

QT += sql
