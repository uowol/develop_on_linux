#include <Dungeon/Dungeon/Dungeon.hpp>
#include <Dungeon/Util/Input.hpp>
#include <Dungeon/Util/Output.hpp>


using namespace std;
using namespace LinuxGame;


int iInput();
void Init();

Player p = {};

int main(){

    Init();

    while(int arrow = iInput()){
        if (arrow==KEY_ENTER) break;
        remove(p);
        switch(arrow){
            case LEFT:
                if(IsWall(--p.x, p.y)){
                    p.x++;
                };
            break;
            case RIGHT:
                if(IsWall(++p.x, p.y)){
                    p.x--;
                };
            break;
            case UP:
                if(IsWall(p.x, --p.y)){
                    p.y++;
                };
            break;
            case DOWN:
                if(IsWall(p.x, ++p.y)){
                    p.y--;
                };
            break;
        }
        move(p);
        LinuxGame::DrawMap();
    }


    return 0;
} 

void Init(){
    p.x = 1;
    p.y = 1;
    move(p);
    LinuxGame::DrawMap();

}

int iInput(){
    int iArrow = getch();
    // cout << iArrow;

    return iArrow;
}
