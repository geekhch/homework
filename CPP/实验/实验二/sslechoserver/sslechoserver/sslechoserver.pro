QT       += core websockets gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sslechoserver
#CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    sslechoserver.cpp \
    dialog.cpp

HEADERS += \
    sslechoserver.h \
    dialog.h

EXAMPLE_FILES += sslechoclient.html

RESOURCES += securesocketclient.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/websockets/sslechoserver
INSTALLS += target

FORMS += \
    dialog.ui
