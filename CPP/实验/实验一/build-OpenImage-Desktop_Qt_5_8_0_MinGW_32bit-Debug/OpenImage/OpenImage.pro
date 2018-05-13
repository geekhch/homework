#-------------------------------------------------
#
# Project created by QtCreator 2018-04-25T18:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OpenImage
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\opencv\out\include
LIBS     +=  -LC:\opencv\out\lib  \
        -llibopencv_calib3d341   \
        -llibopencv_core341   \
        -llibopencv_dnn341   \
        -llibopencv_features2d341   \
        -llibopencv_flann341   \
        -llibopencv_highgui341   \
        -llibopencv_imgcodecs341   \
        -llibopencv_imgproc341   \
        -llibopencv_ml341   \
        -llibopencv_objdetect341   \
        -llibopencv_photo341   \
        -llibopencv_shape341   \
        -llibopencv_stitching341   \
        -llibopencv_superres341   \
        -llibopencv_video341   \
        -llibopencv_videoio341   \
        -llibopencv_videostab341
