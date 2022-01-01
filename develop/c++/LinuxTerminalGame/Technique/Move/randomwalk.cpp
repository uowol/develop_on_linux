#include <iostream>

#define HEIGHT  10
#define WIDTH   10

int map[HEIGHT][WIDTH] = {0, };
int position[2] = {WIDTH/2, HEIGHT/2};

void show(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%d%d", map[i][j], map[i][j]);
        }
        printf("\n");
    }
}

bool isconflict(int x, int y){
    if(map[y][x] == 2) return true;    // 2 is wall
    if(x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT) return true;
    return false; 
}

bool move(int direction){
    int nextPosition[2] = {position[0], position[1]};
    if(direction == 0){ // 상
        nextPosition[1]--;
    }else if(direction == 1){ // 하
        nextPosition[1]++;
    }else if(direction == 2){ // 좌
        nextPosition[0]--;
    }else if(direction == 3){ // 우
        nextPosition[0]++;
    }
    if(isconflict(nextPosition[0], nextPosition[1])) return false;
    map[position[1]][position[0]] = 0;
    position[0] = nextPosition[0];
    position[1] = nextPosition[1];
    map[position[1]][position[0]] = 1;
    return true;
}

// 예제

#include <random>
#include <unistd.h> // for sleep

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);
    
    map[position[1]][position[0]] = 1;

    while(true){
        while(!move(dist(gen)));
        show();
        sleep(1);
    }

    // std::cout << dist(gen) << std::endl;
    // cout << position[0] << ", " << position[1] << endl;
    return 0;   
}