cmake_minimum_required(VERSION 3.20)
project(Cplusplus_BugGame_Silver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Cplusplus_BugGame_Silver
        board/Board.cpp
        Menu.cpp
        bugs/Bug.cpp
        bugs/Bug.h
        crawler/Crawler.cpp
        crawler/Crawler.h
        hopper/Hopper.cpp
        hopper/Hopper.h
)

target_include_directories(Cplusplus_BugGame_Silver PRIVATE
        board
        bugs
        crawler
        hopper
)