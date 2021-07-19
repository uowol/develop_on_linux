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
    Dungeon dungeon(Dungeons::BSP, 48, 48, 4);
    bool s = dungeon.generateDungeon();
    if(s){
        save(dungeon.getStringMap());
    }
    return 0;
}