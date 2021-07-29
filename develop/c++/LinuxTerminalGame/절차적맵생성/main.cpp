#include <iostream>
#include <fstream> // ofstream
#include <bitset>
using namespace std;

#define H true  // 가로분할
#define V false // 세로분할

#define WIDTH   50
#define HEIGHT  50

#define TOP      1
#define LEFT     2
#define BOTTOM   3
#define RIGHT    4

#define NONE        10
#define ROOM        11
#define CORRIDOR    12
#define WALL        13
#define LINE        14 // 지역 구분선


typedef struct EDGE{
    int x1;
    int y1;
    int x2;
    int y2;
} Edge;


int target = 5;
int arr[HEIGHT+2][WIDTH+2];

void init(int tile){
    for(int i=0; i<HEIGHT+2; i++){
        for(int j=0; j<WIDTH+2; j++){
            arr[i][j]=WALL;
        }
    }
    for(int i=1; i<HEIGHT+1; i++){
        for(int j=1; j<WIDTH+1; j++){
            arr[i][j]=tile;
        }
    }
}

void save() {
    ofstream writeFile; // output file system
    string output="";
    writeFile.open("map.txt");

    for(int i=0; i<HEIGHT+2; i++){
        for(int j=0; j<WIDTH+2; j++){
            switch(arr[i][j]){
                case NONE:
					output+=" +";
					break;
				case ROOM:
					output+="  ";
					break;
				case CORRIDOR:
					output+="  ";
					break;
				case WALL:
					output+=" ■";
					break;
				case LINE:
					output+=" .";
					break;
            }
        }
        output+='\n';
    }

    writeFile.write(output.c_str(), output.size()); // c_str(): string의 시작 주소 리턴
    writeFile.close();
}

void addCorridor(int direction, int x1, int x2, int y1, int y2){
    int midX = (x1+x2)/2;
    int midY = (y1+y2)/2;

    if (direction == LEFT){
        // cout<<"LEFT"<<endl;
        for(int i=midX; i<=x2; i++){
            if(arr[midY][i] == LINE){
                arr[midY][i] = CORRIDOR;
                arr[midY+1][i] = CORRIDOR;
                break;
            }
            arr[midY][i] = CORRIDOR;
            arr[midY+1][i] = CORRIDOR;
        }
    }
    else if(direction == RIGHT){
        // cout<<"RIGHT"<<endl;
        for(int i=midX; i >= x1; i--){
            if(arr[midY][i] == LINE){
                arr[midY][i] = CORRIDOR;
                arr[midY+1][i] = CORRIDOR;
                break;
            }
            arr[midY][i] = CORRIDOR;
            arr[midY+1][i] = CORRIDOR;
        }
    }
    else if(direction == TOP){
        // cout<<"TOP"<<endl;
        for(int i=midY; i <= y2; i++){
            if(arr[i][midX] == LINE){
                arr[i][midX] = CORRIDOR;
                arr[i][midX+1] = CORRIDOR;
                break;
            }
            arr[i][midX] = CORRIDOR;
            arr[i][midX+1] = CORRIDOR;
        }
    }
    else if(direction == BOTTOM){
        // cout<<"BOTTOM"<<endl;
        for(int i=midY; i >= y1; i--){
            if(arr[i][midX] == LINE){
                arr[i][midX] = CORRIDOR;
                arr[i][midX+1] = CORRIDOR;
                break;
            }
            arr[i][midX] = CORRIDOR;
            arr[i][midX+1] = CORRIDOR;
        }
    }   

}

Edge BSP(int x1, int y1, int x2, int y2, bool flag, int cnt, unsigned int direction){
    int t_x1 = 0;
    int t_x2 = 0;
    int t_y1 = 0;
    int t_y2 = 0;
    // cout << bitset<16>(direction) << endl;
    if(cnt == target){
        // 방 위치 및 크기 설정 파트
        x1 += rand() % 3 + 1; // 1, 2, 3 난수 발생
        if(x1 < 1) x1 = 1;
        if(x1 > WIDTH) x1 = WIDTH;
        y1 += rand() % 3 + 1;
        if(y1 < 1) y1 = 1;
        if(y1 > HEIGHT) y1 = HEIGHT;
        x2 -= rand() % 3 + 1;
        if(x2 < 1) x2 = 1;
        if(x2 > WIDTH) x2 = WIDTH;
        y2 -= rand() % 3 + 1;
        if(y2 < 1) y2 = 1;
        if(y2 > HEIGHT) y2 = HEIGHT;

        for(int i=y1; i<=y2; i++){
            for(int j=x1; j<=x2; j++){
                arr[i][j] = ROOM; // 최소 4*4 크기의 방 생성
            }
        }

        // 가로분할이면 가로로 통로 세우기 (최소 4칸 넓이의 통로가 가능하다.)
        x1-=3; y1-=3; x2+=3; y2+=3;
        addCorridor(direction & 7, x1, x2, y1, y2);
        while(direction>0){
            // cout << (x1+x2)/2 << ", " << (y1+y2)/2 << ", " << bitset<16>(direction) << endl;
            direction>>=3;
            int corridor = rand() & 1;
            if(corridor){
                addCorridor(direction&7, x1, x2, y1, y2);
            }

        }

        return Edge{};
    }
    if(flag == H){ // 가로분할
        int t = (x2+x1)/2 + (rand() % 4 - 2); // 중간으로부터 -2~1 가로지점
        for(int i=y1; i<=y2; i++){
            arr[i][t] = LINE;
        }
        Edge p1 = BSP(x1, y1, t, y2, V, cnt+1, (direction<<3)|LEFT); // left
        Edge p2 = BSP(t, y1, x2, y2, V, cnt+1, (direction<<3)|RIGHT); // right
        
        // *
        // t_x1 = p1.x2;
        // t_x2 = p2.x1;
        // t_y1 = max(p1.y1, p2.y1);
        // t_y2 = min(p1.y2, p2.y2);
        // int p = 0;
        // do{
        //     p = rand() % (t_y2 - t_y1) + t_y1;
        //     // break;
        // }while(arr[p][t_x1] != ROOM || arr[p][t_x2] != ROOM);

        // for(int i = t_x1; i<=t_x2; i++){
        //     if(arr[p][i] == CORRIDOR) break;
        //     arr[p][i] = CORRIDOR;
        // }

        // return Edge{t_x1, t_y1, t_x2, t_y2};
    }
    else if(flag == V){ // 세로분할
        int t = (y2+y1)/2 +(rand() % 4 - 2);
        for(int j=x1; j<=x2; j++){
            arr[t][j] = LINE;
        }
        Edge p1 = BSP(x1, y1, x2, t, H, cnt+1, (direction<<3)|TOP);
        Edge p2 = BSP(x1, t, x2, y2, H, cnt+1, (direction<<3)|BOTTOM);
    }
    return Edge{t_x1, t_y1, t_x2, t_y2};
}

int main(){
    srand((unsigned int) time(nullptr)); // nullptr: null을 나타내는 포인터 값

    init(NONE);
    BSP(1,1, WIDTH, HEIGHT, H, 1, 0);

    save();

    return 0;
}