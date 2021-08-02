#ifndef LINUX_GAME_TIMER_CPP

#include <Utils/timer.hpp>

namespace LinuxGame{
    Timer::Timer(int* lt){
        // this->addr_left_time = lt;
        this->interval = 10*1000;       // 10sec
        // this->timer_thread.detach();    // main thread보다 먼저 종료되어도 오류가 발생하지 않게 합니다. 다른 방법 찾아보려고 노력했는데 못찾겠어요...
    }
    void Timer::setInterval(time_t msec){
        this->interval = msec;
    }
    void Timer::startCountdown(){
        gettimeofday(&tv, nullptr);
        this->t_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) + interval;
        std::thread(Timer::countdown, interval, tv, t_time).detach();
        flag_count = 1;
    }
    void Timer::countdown(time_t interval, timeval tv, time_t t_time){
        int n = interval/1000;
        while(flag_count){
            gettimeofday(&tv, nullptr);
            time_t now = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
            if((t_time - now)/1000 != n){
                std::cout << (t_time-now)/1000+1 << std::endl;
                n = (t_time - now)/1000;
            }
            left_time = t_time - now;
            if(left_time<=0){
                std::cout << "time out!" << left_time << std::endl;
                std::cout << "next is " << interval/1000 << "!" << std::endl;
                t_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000) + interval;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}



#endif