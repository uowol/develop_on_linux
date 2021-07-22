#include <Util/Input.hpp>
#include <Util/Output.hpp>
#include <Dungeon/Dungeon.hpp>

using namespace std;
using namespace LinuxGame;


#define WIDTH   48
#define HEIGHT  48


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
        for(int j=0; j<=dungeon.getWidth()+1; j++){
            output(i*windowWidth + j) = buffer[i*(dungeon.getWidth()+2+1) + j];
        }
    }
}


int main(){
    system("clear");   
    Dungeon dungeon(Dungeons::BSP, WIDTH, HEIGHT, 4); // Dungeon 객체를 생성합니다.


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


    // 화면 초기화
	const int sight_x=6,sight_y=6,zoom=3;
    int px=(WIDTH-(sight_x*2+1)*zoom)/2;
    int py=(HEIGHT-(sight_y*2+1)*zoom)/2;
    int windowWidth = (dungeon.getWidth()+3) * 2;
    int windowHeight = dungeon.getHeight()+2;
    std::string buffer =  dungeon.getStringMap();   // (width +2 +1) * (height +2)

    // 화면을 출력할 버퍼를 'B'로 초기화합니다.
    OutputBuffer output(windowWidth * windowHeight, ' ');   
    for(int i = 0;i<windowHeight; i++){
		output(i*windowWidth + dungeon.getWidth()+2)= ' ';
		output(i*windowWidth + (dungeon.getWidth()+2)*2+1)= '\n';
	}

    // 화면을 구성합니다.
    for(int i = player.y - sight_y, my=0; i <= player.y + sight_y; i++, my+=zoom){
		for(int j = player.x - sight_x, mx=0;j <= player.x + sight_x; j++, mx+=zoom){
			if(i<0 || j<0 || j>=dungeon.getWidth()+2 || i>=dungeon.getHeight()+2) continue; // 범위가 맵을 벗어나는 것을 방지합니다.
			for(int t=0;t<zoom;t++){
				for(int k=0;k<zoom;k++){
					output((my+t+py)*windowWidth + (mx+k+px)) = buffer[i*(dungeon.getWidth()+3)+j]; // player sight (zoomed)
				}
			}	
            output(i*windowWidth + (j+dungeon.getWidth()+3)) = buffer[i*(dungeon.getWidth()+3) + j]; // map
		}	
	}
    output.print();

    // 플레이어 이동
    int ch = 0;
    while(1){
        ch = getch();
        if(ch == UP) dungeon.movePlayer(0, -1);
        if(ch == DOWN) dungeon.movePlayer(0, +1);
        if(ch == LEFT) dungeon.movePlayer(-1, 0);
        if(ch == RIGHT) dungeon.movePlayer(+1, 0);
        buffer = dungeon.getStringMap();
        player = dungeon.getPlayerPosition();

        for(int i = player.y - sight_y, my=0; i <= player.y + sight_y; i++, my+=zoom){
            for(int j = player.x - sight_x, mx=0;j <= player.x + sight_x; j++, mx+=zoom){
                if(i<0 || j<0 || j>=dungeon.getWidth()+2 || i>=dungeon.getHeight()+2) continue; // 범위가 맵을 벗어나는 것을 방지합니다.
                for(int t=0;t<zoom;t++){
                    for(int k=0;k<zoom;k++){
                        output((my+t+py)*windowWidth + (mx+k+px)) = buffer[i*(dungeon.getWidth()+3)+j]; // player sight (zoomed)
                    }
                }	
                output(i*windowWidth + (j+dungeon.getWidth()+3)) = buffer[i*(dungeon.getWidth()+3) + j]; // map
            }	
        }
        output.print();      
    }
    
    // 던전 출력
    // if(s){
    //     save(dungeon.getStringMap());
    // }
    return 0;
}