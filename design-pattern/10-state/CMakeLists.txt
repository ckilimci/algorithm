cmake_minimum_required(VERSION 3.10)
project(StateMachine)

set(CMAKE_CXX_STANDARD 11)

add_executable(StateMachine main.cpp State.h OpenState.cpp OpenState.h Machine.cpp Machine.h CloseState.cpp CloseState.h)
