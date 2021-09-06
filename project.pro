QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    configWindow/static_text.cpp \
    configWindow/text_interface.cpp \
    main.cpp \
    configWindow/mainwindow.cpp \
    configWindow/mode.cpp \
    read_class.cpp \
    test.cpp

HEADERS += \
    configWindow/mainwindow.h \
    configWindow/mode.h \
    read_class.h \
    test.h

FORMS += \
    configWindow/mainwindow.ui \
    configWindow/mode.ui

VERSION = 1.0.0.0
QMAKE_TARGET_COMPANY = Group of companies Energoskan
QMAKE_TARGET_PRODUCT = On-board computer programm configurator
QMAKE_TARGET_DESCRIPTION = Configurator software
QMAKE_TARGET_COPYRIGHT = Group of companies Energoskan
RC_ICONS = "icon.ico"

#QMAKE_CXXFLAGS += "C:\Users\lario\Downloads\heob-3.1\include"  (my)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
