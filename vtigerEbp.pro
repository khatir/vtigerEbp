#-------------------------------------------------
#
# Project created by QtCreator 2012-12-12T09:52:32
#
#-------------------------------------------------

QT      += core
QT      += network
QT       -= gui

TARGET = vtigerEbp
# CONFIG   += console
# CONFIG   -= app_bundle

TEMPLATE = lib
DEFINES += VTIGEREBP_LIBRARY

SOURCES += entity.cpp \
    operation.cpp \
    vtigerebp.cpp
SOURCES += httpcrm.cpp
SOURCES += json/json_reader.cpp
SOURCES += json/json_value.cpp
SOURCES += json/json_writer.cpp

HEADERS += \
    httpcrm.h \
    entity.h \
    operation.h \
    vtigerEbp_global.h \
    vtigerebp.h

HEADERS += json/value.h
HEADERS += json/reader.h


# DEFINES += MYDLL_LIBRARY

# SOURCES += mydll.cpp

# HEADERS += mydll.h\
#        myDll_global.h
