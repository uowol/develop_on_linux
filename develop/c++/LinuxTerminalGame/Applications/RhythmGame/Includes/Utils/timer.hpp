#ifndef LINUX_GAME_TIMER_HPP

#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>
#include <thread>
#include <mutex>

namespace LinuxGame{
    static int flag_count;
    static int left_time;
    
    class Timer{
        private:
            timeval tv;
            time_t t_time;  // target_time
            time_t interval;
            // std::thread timer_thread; 

        public:
            Timer( int* );
            void startCountdown();
            void setInterval(time_t);
            static int* addr_left_time;
            static void countdown(time_t interval, timeval tv, time_t t_time);
    };
}


#endif