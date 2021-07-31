#ifndef LINUX_GAME_INPUT_HPP

#include <termios.h>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>

#define UP      65
#define DOWN    66
#define RIGHT   67
#define LEFT    68

namespace LinuxGame{
    static struct termios setting;
    static bool init = false;

    void initTermios(void);
    int kbhit(void);
    char getch(void);
}

#endif