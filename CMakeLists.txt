cmake_minimum_required(VERSION 4.1)
project(Cplusplus_BugGame_Silver)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Cplusplus_BugGame_Silver
        board/Board.cpp
        board/Board.h
        bugs/Bug.cpp
        bugs/Bug.h
        crawler/Crawler.cpp
        crawler/Crawler.h
        hopper/Hopper.cpp
        hopper/Hopper.h)
