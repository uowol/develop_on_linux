#include <iostream>
#include <stdio.h> 
using namespace std;

#define WIDTH 7
#define HEIGHT 7

#define KEY_UP 65
#define KEY_DOWN 66
#define KEY_LEFT 68
#define KEY_RIGHT 67
#define KEY_ENTER 13

enum TILE_TYPE{
    TT_NONE,
    TT_WALL,
    TT_PLAYER
};


typedef struct PLAYER{
    int x;
    int y;
} Player;

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

int iInput();
bool IsWall(int, int);
void Init();
void End();
void DrawMap();

Player p = {};

int main(){
    Init();

    while(int arrow = iInput()){
        if (arrow==KEY_ENTER) break;
        map[p.y][p.x] = TT_NONE;
        switch(arrow){
            case KEY_LEFT:
                if(IsWall(--p.x, p.y)){
                    p.x++;
                };
            break;
            case KEY_RIGHT:
                if(IsWall(++p.x, p.y)){
                    p.x--;
                };
            break;
            case KEY_UP:
                if(IsWall(p.x, --p.y)){
                    p.y++;
                };
            break;
            case KEY_DOWN:
                if(IsWall(p.x, ++p.y)){
                    p.y--;
                };
            break;
        }
        map[p.y][p.x] = TT_PLAYER;
        DrawMap();
    }

    End();

    return 0;
}

void Init(){
    system("stty raw");
    p.x = 1;
    p.y = 1;
    map[p.y][p.x] = TT_PLAYER;
    DrawMap();
}

void End(){
    system("stty cooked");
}

void DrawMap(){
    system("clear");
    system("stty cooked");
    
    string strMap = "";
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
    cout << strMap;

    system("stty raw");
    return;
}

int iInput(){
    int iArrow = getchar();
    // cout << iArrow;

    return iArrow;
}

bool IsWall(int x, int y){
    if(map[y][x] == TT_WALL) return true;
    return false;
}