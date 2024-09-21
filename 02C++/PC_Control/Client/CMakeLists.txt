cmake_minimum_required(VERSION 3.16)

project(Client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(PROJECT_SOURCES
        App.cpp
        Client.cpp
        App.hpp
        Client.hpp
)

add_executable(Client ${PROJECT_SOURCES})