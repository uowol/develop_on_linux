#ifndef LINUX_GAME_Dungeon_HPP
#define LINUX_GAME_Dungeon_HPP


#include <iostream>
#include <cstdlib>      // ?
#include <ctime>        // ?
#include <string>       // 문자열 처리?
#include <algorithm>    // ?
#include <vector>       // ?


#define WIDTH 7
#define HEIGHT 7


namespace LinuxGame{
    enum TILE_TYPE{
        TT_NONE,
        TT_WALL,
        TT_PLAYER
    };

    typedef struct PLAYER{
        int x;
        int y;
    } Player;

    void remove(Player);
    void move(Player);
    bool IsWall(int, int);
    void DrawMap();
}


#endif