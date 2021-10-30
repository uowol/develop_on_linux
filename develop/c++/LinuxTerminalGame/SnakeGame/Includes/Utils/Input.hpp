#ifndef INPUT_HPP

#define UP      65
#define DOWN    66
#define RIGHT   67
#define LEFT    68

#include <termios.h>
#include <unistd.h>
#include <iostream>

namespace LinuxGame{
    void initTermios();
    void terminalTermios();
    char getch();
}

#endif