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
    pugixml.cpp \
    logger.cpp \
    tests.cpp \
    shared.cpp

HEADERS += \
    receivers.h \
    dispatcher.h \
    remote_control.h \
    senders.h \
    logger.h \
    tests.h \
    shared.h

OTHER_FILES += \
    test_xml.txt
