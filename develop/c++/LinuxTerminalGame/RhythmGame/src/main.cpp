#ifndef LINUX_GAME_MAIN_CPP

#include <Utils/timer.hpp>
#include <Utils/input.hpp>
#include <Utils/output.hpp>
#include <thread>

#define PERPECT 4
#define GREAT   3
#define GOOD    2
#define BAD     1
#define MISS    0

using namespace std;
using namespace LinuxGame;

time_t t_time = 0;
int left_time = 0;

bool game_running = false;

struct timeval tv;
int interval = 3000;
void countdown(){
    int n = interval/1000;
    while(1){
        gettimeofday(&tv, nullptr);
        time_t now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
        if((t_time - now)/1000 != n){
            cout << (t_time-now)/1000+1 << endl;
            n = (t_time - now)/1000;
        }
        left_time = t_time - now;
        if(left_time<=0){
            cout << "time out!" << endl;
            cout << "next is " << interval/1000 << "!" << endl;
            t_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) + interval;
            left_time = 0;
        }
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main(){
    // 카운트를 세기 시작합니다.
    gettimeofday(&tv, nullptr);
    t_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) + interval;
    thread _t1(countdown);
    game_running = true;

    // 타이밍에 맞춰 스페이스바를 눌러봅시다.
    while(1){
        int ch = getch();
        if(ch == 10) break;
        if(ch == 32){   // 스페이스바를 눌렀을 때
            if(!game_running) continue;
            if(left_time < 100){
                cout << "Perpect!" << endl;
            }else if(left_time < 500){
                cout << "Great" << endl;
            }else if(left_time < 1000){
                cout << "Good" << endl;
            }else if(left_time < 1500){
                cout << "Bad" << endl;
            }else{
                cout << "Miss!" << endl;
            }
        }
    }
    return 0;

    // 스레드가 종료되기를 기다립니다.
    _t1.join();
    cout << "thread finished" << endl;
    return EXIT_SUCCESS;
}

#endif