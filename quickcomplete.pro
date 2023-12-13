TEMPLATE = lib
CONFIG += plugin
QT += core widgets

INCLUDEPATH += $$PWD/plugininterface \
        $$PWD
HEADERS = plugininterface/plugininterface.h \
        quickcomplete.h
SOURCES = plugininterface/plugininterface.cpp \
        quickcomplete.cpp
TRANSLATIONS = quickcomplete_zh_CN.ts \
        quickcomplete_en_US.ts
RESOURCES = quickcomplete.qrc

TARGET = $$qtLibraryTarget(quickcomplete)

unix:{
    QMAKE_RPATHDIR=$ORIGIN
}
