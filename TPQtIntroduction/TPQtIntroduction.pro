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
    view/mainwindow.cpp \
    view/dialogidentification.cpp \
    view/dialogaddclient.cpp \
    view/dialogabout.cpp \
    view/dialogaddemployee.cpp \
    view/dialogmodifyemployee.cpp \
    model/client.cpp \
    model/appointment.cpp \
    model/employee.cpp \
    controller/controller_employee.cpp \
    controller/controller_client.cpp \
    c_init_bd.cpp \
    dao/dao_client.cpp \
    dao/dao_employee.cpp \
    dao/singletondb.cpp

HEADERS += \
        view/mainwindow.h \
    view/dialogidentification.h \
    view/dialogaddclient.h \
    view/dialogabout.h \
    view/dialogaddemployee.h \
    view/dialogmodifyemployee.h \
    model/client.h \
    model/appointment.h \
    model/employee.h \
    controller/controller_employee.h \
    controller/controller_client.h \
    c_init_bd.h \
    dao/dao_client.h \
    dao/dao_employee.h \
    dao/singletondb.h

FORMS += \
    mainwindow.ui \
    dialogidentification.ui \
    dialogaddclient.ui \
    dialogabout.ui \
    dialogaddemployee.ui

RESOURCES += \
    pictures.qrc

QT += sql

DISTFILES += \
    dialogmodifyemployee.ui
