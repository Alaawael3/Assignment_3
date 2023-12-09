cmake_minimum_required(VERSION 3.26)
project(task_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(task_2 main.cpp
        Board.h
        Random_player.h
        Xo_board.h
        Player.h
        GameManager.h
        GameManager.cpp
        Player.cpp
        Random_player.cpp
        Xo_board.cpp)
