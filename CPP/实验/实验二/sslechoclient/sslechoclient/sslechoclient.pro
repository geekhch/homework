QT       += core websockets gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sslechoclient
#CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    sslechoclient.cpp \
    dialog.cpp \
    createclient.cpp

HEADERS += \
    sslechoclient.h \
    dialog.h \
    createclient.h

target.path = $$[QT_INSTALL_EXAMPLES]/websockets/sslechoclient
INSTALLS += target

FORMS += \
    dialog.ui \
    createclient.ui
