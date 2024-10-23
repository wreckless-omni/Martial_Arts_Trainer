QT       += core gui charts printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chartmethods.cpp \
    fileMethods.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    chartmethods.h \
    fileMethods.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Kick_Form \
    Kick_Iso \
    Kick_Lift \
    Kick_Stretch \
    Punch_Form \
    Punch_Iso \
    Punch_Push \
    Punch_Stretch
