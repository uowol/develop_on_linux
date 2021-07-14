#include <iostream>
#include <fstream> // ofstream
using namespace std;

#define H true  // 가로분할
#define V false // 세로분할

#define WIDTH   100
#define HEIGHT  100

enum TILE_TPYE{
    TT_NONE,
    TT_ROOM,
    TT_CORRIDOR,
    TT_WALL,
    TT_LINE
};

typedef struct EDGE{ // typedef로 struct 키워드 없이 구조체 선언하기
    int x1;
    int y1;
    int x2;
    int y2;
} Edge; // 구조체 별칭

int target = 7;
int arr[HEIGHT+2][WIDTH+2];

void init(int tile){
    for(int i=0; i<HEIGHT+2; i++){
        for(int j=0; j<WIDTH+2; j++){
            arr[i][j]=TT_WALL;
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
                case TT_NONE:
					output+=" .";
					break;
				case TT_ROOM:
					output+=" 0";
					break;
				case TT_CORRIDOR:
					output+=" 1";
					break;
				case TT_WALL:
					output+=" ■";
					break;
				case TT_LINE:
					output+=" ,";
					break;
            }
        }
        output+='\n';
    }

    writeFile.write(output.c_str(), output.size()); // c_str(): string의 시작 주소 리턴
    writeFile.close();
}

int iterators = 0;

Edge BSP(int x1, int y1, int x2, int y2, bool flag, int cnt){
    // cout << iterators++ << ": " << flag << endl;
    if(cnt == target){ // 트리의 잎에 도착하면,
        // 방 위치 및 크기 설정 파트, x1, x2, y1, y2는 방 위치의 지표가 됨.
        x1 += rand() % 2 + 2; // 2, 3 난수 발생
        if(x1 < 1) x1 = 1;
        if(x1 > WIDTH) x1 = WIDTH;
        y1 += rand() % 2 + 2;
        if(y1 < 1) y1 = 1;
        if(y1 > HEIGHT) y1 = HEIGHT;
        x2 -= rand() % 2 + 2;
        if(x2 < 1) x2 = 1;
        if(x2 > WIDTH) x2 = WIDTH;
        y2 -= rand() % 2 + 2;
        if(y2 < 1) y2 = 1;
        if(y2 > HEIGHT) y2 = HEIGHT;

        for(int i=y1; i<=y2; i++){
            for(int j=x1; j<=x2; j++){
                arr[i][j] = TT_ROOM;
            }
        }

        return Edge{x1, y1, x2, y2};
    }

    int t_x1 = 0;
    int t_x2 = 0;
    int t_y1 = 0;
    int t_y2 = 0;
    if(flag == H){ // 가로분할
        int t = (x2+x1)/2 + (rand() % 3 - 2); // 중심으로부터 -2~1의 오차
        for(int i=y1; i<=y2; i++){
            arr[i][t] = TT_LINE;
        }
        Edge p1 = BSP(x1, y1, t, y2, V, cnt+1); // left room
        Edge p2 = BSP(t, y1, x2, y2, V, cnt+1); // right room

        t_y1 = min(p1.y1, p2.y1);
        t_y2 = max(p1.y2, p2.y2);
        t_x1 = p1.x2;
        t_x2 = p2.x1;

        int left, right;
        int pos_line = 0;

        do{
            left = rand() % (t_y2-t_y1-2) + t_y1+1;
            right = rand() % (t_y2-t_y1-2) + t_y1+1; 
        } while(arr[left][t_x1]!=TT_ROOM || arr[right][t_x2]!=TT_ROOM);

        for(int i=t_x1+1;;i++){
            if(arr[left][i] == TT_LINE) {
                pos_line = i;
                break;
            }
            arr[left][i] = TT_CORRIDOR;
        }
        for(int i=t_x2-1;;i--){
            if(arr[right][i] == TT_LINE) break;
            arr[right][i] = TT_CORRIDOR;
        }
        for(int j=left;j<=right;j++) arr[j][pos_line] = TT_CORRIDOR;
        for(int j=right;j<=left;j++) arr[j][pos_line] = TT_CORRIDOR;

        return Edge{p1.x1, t_y1, p2.x2, t_y2};
    }
    else if(flag == V){ // 세로분할
        int t = (y2+y1)/2 +(rand() % 3 - 2);
        for(int j=x1; j<=x2; j++){
            arr[t][j] = TT_LINE;
        }
        Edge p1 = BSP(x1, y1, x2, t, H, cnt+1);
        Edge p2 = BSP(x1, t, x2, y2, H, cnt+1);

        t_x1 = min(p1.x1, p2.x1);
        t_x2 = max(p1.x2, p2.x2);
        t_y1 = p1.y2;
        t_y2 = p2.y1;

        int up, down;
        int pos_line = 0;

        do{
            up = rand() % (t_x2-t_x1-2) + t_x1+1;
            down = rand() % (t_x2-t_x1-2) + t_x1+1; 
        } while(arr[t_y1][up]!=TT_ROOM || arr[t_y2][down]!=TT_ROOM);

        for(int i=t_y1+1;;i++){
            if(arr[i][up] == TT_LINE) {
                pos_line = i;
                break;
            }
            arr[i][up] = TT_CORRIDOR;
        }
        for(int i=t_y2-1;;i--){
            if(arr[i][down] == TT_LINE) break;
            arr[i][down] = TT_CORRIDOR;
        }
        for(int j=up;j<=down;j++) arr[pos_line][j] = TT_CORRIDOR;
        for(int j=down;j<=up;j++) arr[pos_line][j] = TT_CORRIDOR;

        return Edge{t_x1, p1.y1, t_x2, p2.y2};
    }
    return Edge{t_x1, t_y1, t_x2, t_y2};
}

int main(){
    srand((unsigned int) time(nullptr)); // nullptr: null을 나타내는 포인터 값

    init(TT_NONE);
    BSP(1,1, WIDTH, HEIGHT, H, 1);

    save();

    return 0;
}