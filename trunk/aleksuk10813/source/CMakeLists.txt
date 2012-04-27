cmake_minimum_required(VERSION 2.6)
project(sem2)

set (SOURCES dispatcher.h
receivers.h
remote_control.h
senders.h
shared.h
tests.h
config_handler.h
dispatcher.cpp
main.cpp
remote_control.cpp
rss_receiver.cpp
shared.cpp
smtp_sender.cpp
test_receiver.cpp
test_sender.cpp
tests.cpp
xmpp_sender.cpp
config_handler.cpp
3rdparty/base64.cpp
3rdparty/pugixml.cpp)

set (CMAKE_CXX_FLAGS "-std=c++11 -lpthread -lpugixml")

add_executable(sem2 ${SOURCES})