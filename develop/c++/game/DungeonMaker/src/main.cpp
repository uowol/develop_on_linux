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

// 버퍼를 왼쪽화면에 덮어씌웁니다.
void writeLeft(Dungeon& dungeon, OutputBuffer& output, const string& buffer) {
    int windowWidth = (dungeon.getWidth()+2 +1) * 2;
    int windowHeight = dungeon.getHeight()+2;
    for(int i=0; i<windowHeight; i++){
        string _buffer = "";
        for(int j=0; j<=dungeon.getWidth()+1; j++){
            output(i*windowWidth + j) = buffer[i*(dungeon.getWidth()+2+1) + j];
            _buffer += buffer[i*(dungeon.getWidth()+2+1) + j];
        }
    }
}


int main(){
    Dungeon dungeon(Dungeons::BSP, 48, 48, 4); // Dungeon 객체를 생성합니다.

    // 던전의 생성
    bool s = dungeon.generateDungeon();
    string ori = dungeon.getStringMap();
	// int px =0,py = 0; // padding 
	// const int sight_x=10,sight_y=5,zoom=3;
    
    // 플레이어 생성
    int x, y;
    do{
        x = rand() % dungeon.getWidth();
        y = rand() % dungeon.getHeight();
    }while(dungeon(x, y) != ROOM);
    dungeon.setPlayer(x, y);
    Point player = dungeon.getPlayerPosition();

    // 화면 초기화
    int windowWidth = (dungeon.getWidth()+2 +1) * 2;
    int windowHeight = dungeon.getHeight()+2;
    OutputBuffer output(windowWidth * windowHeight, 'B');           // 화면을 출력할 버퍼를 'B'로 초기화 합니다.
    for(int i = 0;i<windowHeight; i++){
		output(i*windowWidth + dungeon.getWidth()+2)= ' ';
		output(i*windowWidth + (dungeon.getWidth()+2)*2+1)= '\n';	// 레이아웃을 나타냅니다.
	}

    std::string buffer =  dungeon.getStringMap();
    writeLeft(dungeon, output, buffer);
    output.print();

    // 플레이어 이동
    int ch = 0;
    while(1){
        ch = getch();
        switch(ch){
            case UP:
                dungeon.movePlayer(0,-1);
                buffer =  dungeon.getStringMap();
                writeLeft(dungeon, output, buffer);
                output.print();
                break;
            case DOWN:
                dungeon.movePlayer(0,1);
                buffer =  dungeon.getStringMap();
                writeLeft(dungeon, output, buffer);
                output.print();
                break;
            case LEFT:
                dungeon.movePlayer(-1,0);
                buffer =  dungeon.getStringMap();
                writeLeft(dungeon, output, buffer);
                output.print();
                break;
            case RIGHT:
                dungeon.movePlayer(1,0);
                buffer =  dungeon.getStringMap();
                writeLeft(dungeon, output, buffer);
                output.print();
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