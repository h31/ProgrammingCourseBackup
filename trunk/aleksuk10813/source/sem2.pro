TEMPLATE = app
CONFIG += console
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++0x -lpthread  -lpugixml -pthread
QMAKE_LFLAGS += -std=c++0x -lpthread -lpugixml -pthread

SOURCES += main.cpp \
    test_receiver.cpp \
    rss_receiver.cpp \
    dispatcher.cpp \
    test_sender.cpp \
    tests.cpp \
    shared.cpp \
    remote_control.cpp \
    smtp_sender.cpp \
    3rdparty/base64.cpp \
    3rdparty/pugixml.cpp

HEADERS += \
    receivers.h \
    dispatcher.h \
    remote_control.h \
    senders.h \
    tests.h \
    shared.h \
    3rdparty/base64.h \
    3rdparty/pugixml.hpp

OTHER_FILES += \
    test_xml.txt

