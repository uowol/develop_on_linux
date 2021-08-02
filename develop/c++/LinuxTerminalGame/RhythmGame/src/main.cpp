#ifndef LINUX_GAME_MAIN_CPP

#include <Utils/input.hpp>
#include <Utils/output.hpp>
#include <Utils/timer.hpp>

#define PERPECT 4
#define GREAT   3
#define GOOD    2
#define BAD     1
#define MISS    0

using namespace std;
using namespace LinuxGame;

bool game_running = false;

int main(){
    // 카운트를 세기 시작합니다.
    int a = 0;
    Timer timer(new int);
    timer.setInterval(3000);
    timer.startCountdown();
    game_running = true;

    // 타이밍에 맞춰 스페이스바를 눌러봅시다.
    while(1){
        int ch = getch();
        if(ch == 10) flag_count = 0;
        if(ch == 32){   // 스페이스바를 눌렀을 때
            cout << flag_count << endl;
            if(!game_running) continue;
            cout <<  left_time << endl;
            // cout <<  << endl;
            if( left_time < 100){
                cout << "Perpect!" << endl;
            }else if( left_time < 500){
                cout << "Great" << endl;
            }else if( left_time < 1000){
                cout << "Good" << endl;
            }else if( left_time < 1500){
                cout << "Bad" << endl;
            }else{
                cout << "Miss!" << endl;
            }
        }
    }


    // 터미널 입력 설정을 되돌립니다.
    resetTermios();

    // 스레드 종료를 대기합니다. -> detach로 임시방편해두었습니다.
    flag_count = 0;
    return 0;
}

#endif