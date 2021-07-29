#ifndef LINUX_GAME_Dungeon_CPP
#define LINUX_GAME_Dungeon_CPP

#include <Dungeon/Dungeon/Dungeon.hpp>

using namespace LinuxGame;

int map[HEIGHT+2][WIDTH+2] = {
    {TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_WALL},
    {TT_WALL, TT_WALL, TT_NONE, TT_NONE, TT_NONE, TT_NONE, TT_NONE, TT_WALL, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_WALL, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_WALL, TT_NONE, TT_WALL, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_WALL, TT_WALL},
    {TT_WALL, TT_NONE, TT_NONE, TT_NONE, TT_WALL, TT_NONE, TT_NONE, TT_NONE, TT_WALL},
    {TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL, TT_WALL},
};

void LinuxGame::DrawMap(){
    system("clear");
    
    std::string strMap = "";
    for(int i=0; i<HEIGHT+2; i++){
        for(int j=0; j<WIDTH+2; j++){
            switch(map[i][j]){
                case TT_NONE:
                    strMap += "  ";
                break;
                case TT_WALL:
                    strMap += " #";
                break;
                case TT_PLAYER:
                    strMap += " @";
                break;
            }
        }
        strMap += "\n";
    }
    std::cout << strMap;

    return;
}

bool LinuxGame::IsWall(int x, int y){
    if(map[y][x] == LinuxGame::TT_WALL) return true;
    return false;
}

void LinuxGame::remove(Player p){
    map[p.y][p.x] = TT_NONE;
    return;
}

void LinuxGame::move(Player p){
    map[p.y][p.x] = TT_PLAYER;
    return;
}

#endif