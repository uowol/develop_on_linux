#include <thread>
#include <iostream>
#include <mutex>
#include <random>
#include </home/alllhvhla/git/develop_on_linux/develop/c++/LinuxTerminalGame/Technique/TerminalIO/input.cpp>
#include </home/alllhvhla/git/develop_on_linux/develop/c++/LinuxTerminalGame/Technique/TerminalIO/output.cpp>

#define SPEED 2
#define NUM_NODE 100
#define NUM_KEY_PAD 4
#define HEIGHT 10

#define A   122
#define B   120
#define X   110
#define Y   109

int map[HEIGHT][NUM_KEY_PAD] = {0, };

void show(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<NUM_KEY_PAD; j++){
            printf("%d%d", map[i][j], map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    system("clear");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 3);

    std::mutex mtx;

    OutputBuffer buf = OutputBuffer(2*NUM_KEY_PAD*(HEIGHT+1)+HEIGHT, ' ');
    for(int i=1; i<=HEIGHT;i++){
        buf(i*2*NUM_KEY_PAD+(i-1)) = '\n';
    }
    for(int i=2*NUM_KEY_PAD*HEIGHT+HEIGHT; i<2*NUM_KEY_PAD*(HEIGHT+1)+HEIGHT;i++){
        buf(i) = '~';
    }

    auto fall_func = [&map, &buf, &rd, &gen, &dist, &mtx](){
        int x = dist(gen);
        int y = 0;
        while(y < HEIGHT){
            std::this_thread::sleep_for(std::chrono::milliseconds(100/SPEED));
            // system("clear");
            mtx.lock();
            map[y][x] = 0;
            if(y<HEIGHT){
                buf(y*(2*NUM_KEY_PAD+1) + 2*x) =    ' ';
                buf(y*(2*NUM_KEY_PAD+1) + 2*x+1) =  ' ';
            }
            mtx.unlock();
            y++;
            mtx.lock();
            map[y][x] = 1;
            if(y<HEIGHT){
                buf(y*(2*NUM_KEY_PAD+1) + 2*x) =    '#';
                buf(y*(2*NUM_KEY_PAD+1) + 2*x+1) =  '#';
            }
            mtx.unlock();
            buf.print();
            // show();
        }
    };
    
    auto input_func = [&buf](){
        while(true){
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
            int ch = getch();
            if(ch == A){
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT) =    '@';
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+1) =  '@';
            }else if(ch == B){
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+2) =  '@';
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+3) =  '@';
            }else if(ch == X){
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+4) =  '@';
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+5) =  '@';
            }else if(ch == Y){
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+6) =  '@';
                buf(2*NUM_KEY_PAD*HEIGHT+HEIGHT+7) =  '@';
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            for(int i=2*NUM_KEY_PAD*HEIGHT+HEIGHT; i<2*NUM_KEY_PAD*(HEIGHT+1)+HEIGHT;i++){
                buf(i) = '~';
            }
        }
    };

    std::thread t_ipt = std::thread(input_func); 
    std::thread t[NUM_NODE];

    for(int i=0; i<NUM_NODE; i++){
        t[i] = std::thread(fall_func);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    for(int i=0; i<NUM_NODE; i++){
        t[i].join();
    }
    // show();
}