#-------------------------------------------------
#
# Project created by QtCreator 2017-02-15T10:53:50
#
#-------------------------------------------------

QT       -= gui

TARGET = MobileApp
TEMPLATE = lib

DEFINES += APP_LIBRARY APP_DEBUG

unix:!macx: LIBS += -L$$PWD/../../../../NIO/libs -lDataService
INCLUDEPATH += $$PWD/../../../Inc/comm
INCLUDEPATH += $$PWD/../../../PL/Inc/Middleware


SOURCES += \
    MobileApp.cpp \
    LogicModuleAbstractClass.cpp \
    DataConfigClass.cpp \
    BatteryClass.cpp \
    BatteryControllerClass.cpp \
    ChargerClass.cpp \
    ChargerControllerClass.cpp \
    SwitchClass.cpp \
    SwitchControllerClass.cpp \
    DeviceAbstractClass.cpp \
    ExceptionClass.cpp \
    TR4A.cpp

HEADERS +=\
        app_global.h \
    MobileApp.h \
    LogicModuleAbstractClass.h \
    DataConfigClass.h \
    BatteryClass.h \
    BatteryControllerClass.h \
    ChargerClass.h \
    ChargerControllerClass.h \
    SwitchClass.h \
    SwitchControllerClass.h \
    DeviceAbstractClass.h \
    ExceptionClass.h \
    TR4A_if.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
