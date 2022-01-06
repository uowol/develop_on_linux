#include <thread>
#include <iostream>
#include <mutex>
#include <random>
#include </home/alllhvhla/git/develop_on_linux/develop/c++/LinuxTerminalGame/Technique/TerminalIO/input.cpp>
#include </home/alllhvhla/git/develop_on_linux/develop/c++/LinuxTerminalGame/Technique/TerminalIO/output.cpp>

#define TILE_NODE 'V'

int map[10][10] = {0, };

void show(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%d%d", map[i][j], map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, 9);

    std::mutex mtx;

    // OutputBuffer buf = OutputBuffer(20*10+10, '0');
    // for(int i=0; i<10;i++){
    //     buf(i*21) = '\n';
    // }
    // buf.print();
    // return 0;

    auto fall_func = [&map, &rd, &gen, &dist, &mtx](){
        int x = dist(gen);
        int y = 0;
        while(y < 10){
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            system("clear");
            mtx.lock();
            map[y][x] = 0;
            mtx.unlock();
            // gotoxy(x*2, y);
            // std::cout << "00";
            y++;
            mtx.lock();
            map[y][x] = 1;
            mtx.unlock();
            // gotoxy(x*2, y);
            // std::cout << "##";
            // buf.print();
            show();
        }
    };
    
    auto generator_func = [&fall_func](){
        std::thread t = std::thread(fall_func);
        t.join();
    };

    std::thread t[100];

    for(int i=0; i<100; i++){
        t[i] = std::thread(fall_func);
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    for(int i=0; i<100; i++){
        t[i].join();
    }
    // show();
}