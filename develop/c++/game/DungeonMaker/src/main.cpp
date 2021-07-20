#include <Util/Input.hpp>
#include <Util/Output.hpp>
#include <Dungeon/Dungeon.hpp>

using namespace std;
using namespace LinuxGame;


void save(const string& output) {
    ofstream writeFile; // output file system
    writeFile.open("../bin/map.txt");
    cout << output << endl;
    writeFile.write(output.c_str(), output.size()); // c_str(): string의 시작 주소 리턴
    writeFile.close();
}


int main(){
    Dungeon dungeon(Dungeons::BSP, 48, 48, 4); // Dungeon 객체를 생성합니다.

    // 던전의 생성
    bool s = dungeon.generateDungeon();
    string ori = dungeon.getStringMap();
    
    // 플레이어 생성
    int x, y;
    do{
        x = rand() % dungeon.getWidth();
        y = rand() % dungeon.getHeight();
    }while(dungeon(x, y) != ROOM);
    dungeon.setPlayer(x, y);
    Point player = dungeon.getPlayerPosition();

    // 화면 출력
    system("clear");
    cout << dungeon.getStringMap() << endl;

    // 플레이어 이동
    while(1){
        char ch = getch();
        switch(ch){
            case UP:
                dungeon.movePlayer(0,-1);
                system("clear");
                cout << dungeon.getStringMap() << endl;
                break;
            case DOWN:
                dungeon.movePlayer(0,1);
                system("clear");
                cout << dungeon.getStringMap() << endl;
                break;
            case LEFT:
                dungeon.movePlayer(-1,0);
                system("clear");
                cout << dungeon.getStringMap() << endl;
                break;
            case RIGHT:
                dungeon.movePlayer(1,0);
                system("clear");
                cout << dungeon.getStringMap() << endl;
                break;
            default:
                break;
        }
    }
    
    // 던전 출력
    // if(s){
    //     save(dungeon.getStringMap());
    // }
    return 0;
}