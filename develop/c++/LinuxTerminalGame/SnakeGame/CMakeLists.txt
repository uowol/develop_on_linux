cmake_minimum_required(VERSION 3.10)

project(SnakeGame)


set(SnakeGame_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/Includes)
set(SnakeGame_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/Sources)
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/bin)

add_executable(
    SnakeGame
	src/Main.cpp
	${SnakeGame_SOURCE_DIR}/Utils/Input.cpp
	${SnakeGame_SOURCE_DIR}/Snake.cpp
)

target_compile_options(SnakeGame PUBLIC -Wall -Werror -lncurses)
target_include_directories(SnakeGame PUBLIC ${SnakeGame_INCLUDE_DIR})