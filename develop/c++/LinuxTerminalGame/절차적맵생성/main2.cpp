#include <iostream>
#include <fstream> // ofstream
using namespace std;

#define H true  // 가로분할
#define V false // 세로분할

#define WIDTH   50
#define HEIGHT  50

enum TILE_TPYE{
    TT_NONE,
    TT_ROOM,
    TT_CORRIDOR,
    TT_WALL,
    TT_LINE
};

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
					output+="  ";
					break;
				case TT_CORRIDOR:
					output+="  ";
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

void BSP(int x1, int y1, int x2, int y2, bool flag, int cnt){
    int t_x1 = 0;
    int t_x2 = 0;
    int t_y1 = 0;
    int t_y2 = 0;
    if(cnt == target){
        // 방 위치 및 크기 설정 파트
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

        // 통로 만들기
        x1-=1; y1-=1; x2+=1; y2+=1;
        // cout << x1 << ", " << x2 << endl;
        int n = rand() % 3;
        if (n == 0 || n == 2){
            int p = rand() % (y2-y1-1) + y1+1;
            for(int i=x1;;i--){
                if(arr[p][i] == TT_WALL) break;
                if(arr[p][i] == TT_ROOM){
                    for(int j=x1; j>=i; j--){
                        arr[p][j] = TT_CORRIDOR;
                    }
                    break;
                }
            }
            // 방이 왼쪽에서 오른쪽으로 생성되기 때문에 사실상 아래 코드는 작동하지 않음
            // for(int i=x2;;i++){ 
            //     if(arr[p][i] == TT_WALL) break;
            //     if(arr[p][i] == TT_ROOM){
            //         for(int j=x2; j<=i; j++){
            //             arr[p][j] = TT_CORRIDOR;
            //         }
            //         break;
            //     }
            // }
        }
        if (n == 1 || n == 2){
            int p = rand() % (x2-x1-1) + x1+1;
            for(int i=y1;;i--){
                if(arr[i][p] == TT_WALL) break;
                if(arr[i][p] == TT_ROOM){
                    for(int j=y1; j>=i; j--){
                        arr[j][p] = TT_CORRIDOR;
                    }
                    break;
                }
            }
            // 방이 위에서 아래로 생성되기 때문에 사실상 아래 코드는 작동하지 않음
            // for(int i=x2;;i++){ 
            //     if(arr[p][i] == TT_WALL) break;
            //     if(arr[p][i] == TT_ROOM){
            //         for(int j=x2; j<=i; j++){
            //             arr[p][j] = TT_CORRIDOR;
            //         }
            //         break;
            //     }
            // }
        }

        return;
    }
    if(flag == H){ // 가로분할
        int t = (x2+x1)/2 + (rand() % 3 - 1); // 중심으로부터 -1~2의 오차
        for(int i=y1; i<=y2; i++){
            arr[i][t] = TT_LINE;
        }
        BSP(x1, y1, t, y2, V, cnt+1); // left
        BSP(t, y1, x2, y2, V, cnt+1); // right
        
        // *
        // t_x1 = p1.x2;
        // t_x2 = p2.x1;
        // t_y1 = max(p1.y1, p2.y1);
        // t_y2 = min(p1.y2, p2.y2);
        // int p = 0;
        // do{
        //     p = rand() % (t_y2 - t_y1) + t_y1;
        //     // break;
        // }while(arr[p][t_x1] != TT_ROOM || arr[p][t_x2] != TT_ROOM);

        // for(int i = t_x1; i<=t_x2; i++){
        //     if(arr[p][i] == CORRIDOR) break;
        //     arr[p][i] = CORRIDOR;
        // }

        // return Edge{t_x1, t_y1, t_x2, t_y2};
    }
    else if(flag == V){ // 세로분할
        int t = (y2+y1)/2 +(rand() % 4 - 2);
        for(int j=x1; j<=x2; j++){
            arr[t][j] = TT_LINE;
        }
        BSP(x1, y1, x2, t, H, cnt+1);
        BSP(x1, t, x2, y2, H, cnt+1);
    }
    return;
}

int main(){
    srand((unsigned int) time(nullptr)); // nullptr: null을 나타내는 포인터 값

    init(TT_NONE);
    BSP(1,1, WIDTH, HEIGHT, H, 1);

    save();

    return 0;
}