cmake_minimum_required(VERSION 3.10)

project(RhythmGame)
find_package(Threads REQUIRED)
add_definitions("-std=c++17")


set(RhythmGame_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/Includes)
set(RhythmGame_SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/Sources)
set(CMAKE_CXX_FLAGS "-O3")
set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR}/bin)

add_executable(RhythmGame
	src/main.cpp
	${RhythmGame_SOURCE_DIR}/Utils/input.cpp
	${RhythmGame_SOURCE_DIR}/Utils/output.cpp
	${RhythmGame_SOURCE_DIR}/Utils/timer.cpp
)

target_include_directories(RhythmGame PUBLIC ${RhythmGame_INCLUDE_DIR})
target_link_libraries(RhythmGame PRIVATE pthread)