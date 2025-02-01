QT = core network

CONFIG += c++17 cmdline

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
        main.cpp \
        server.cpp
        win32: {
            debug: {
                LIBS += -L$$PWD/debug -lffile
                INCLUDEPATH += $$PWD/debug/ffile
            } else: {
                LIBS += -L$$PWD/release -lffile
                INCLUDEPATH += $$PWD/release/ffile

            }
        }
     QMAKE_SPEC = win32-g++  # или win32-msvc2022

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    server.h
