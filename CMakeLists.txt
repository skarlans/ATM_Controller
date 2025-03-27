cmake_minimum_required(VERSION 3.10)
project(ATM_CONTROLLER CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/src)

add_executable(ATMController
    src/main.cpp
    src/Account.cpp
    src/Hardware.cpp
    src/ATMController.cpp
    src/BankServer.cpp)

