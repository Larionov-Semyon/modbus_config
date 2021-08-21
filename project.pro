QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    file.cpp \
    main.cpp \
    mainmenu.cpp \
    infoWindow/infomessage.cpp \
    infoWindow/infowindow.cpp \
    configWindow/mainwindow.cpp \
    configWindow/mode.cpp \
    test.cpp

HEADERS += \
    file.h \
    mainmenu.h \
    infoWindow/infomessage.h \
    infoWindow/infowindow.h \
    configWindow/mainwindow.h \
    configWindow/mode.h \
    test.h

FORMS += \
    mainmenu.ui \
    infoWindow/infomessage.ui \
    infoWindow/infowindow.ui \
    configWindow/mainwindow.ui \
    configWindow/mode.ui

#QMAKE_CXXFLAGS += "C:\Users\lario\Downloads\heob-3.1\include"  (my)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
