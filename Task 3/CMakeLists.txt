cmake_minimum_required(VERSION 3.26)
project(test_task2)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_task2 main.cpp
        GameManager.cpp
        X_0_Board.cpp
        Player.cpp
        Radom_Player.cpp
        )
