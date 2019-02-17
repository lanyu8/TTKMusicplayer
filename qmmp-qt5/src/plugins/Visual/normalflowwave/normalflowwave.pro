include(../../plugins.pri)

TARGET=$$PLUGINS_PREFIX/Visual/normalflowwave
QMAKE_CLEAN =$$PLUGINS_PREFIX/Visual/libnormalflowwave.so

include(../common/Visual.pri)

HEADERS += normalflowwave.h \
           visualnormalflowwavefactory.h

SOURCES += normalflowwave.cpp \
           visualnormalflowwavefactory.cpp

win32:{
    HEADERS += ../../../../src/qmmp/visual.h
    INCLUDEPATH += ./
}

unix{
    target.path = $$LIB_DIR/qmmp/Visual
    INSTALLS += target
}
