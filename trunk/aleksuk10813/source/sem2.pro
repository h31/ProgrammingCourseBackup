TEMPLATE = app
CONFIG += console
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x

SOURCES += main.cpp \
    test_receiver.cpp \
    rss_receiver.cpp

HEADERS += \
    receivers.h \
    dispatcher.h \
    remote_control.h \
    senders.h

