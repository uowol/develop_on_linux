#ifndef LINUX_GAME_RHYTHM_CPP

#include <chrono>
#include <iostream>
#include <sys/time.h>
#include <ctime>

#define PERPECT 4
#define GREAT   3
#define GOOD    2
#define BAD     1
#define MISS    0

using namespace std;

void timer(){
    
}

int main(){
    struct timeval tv;
    gettimeofday(&tv, nullptr);
    time_t msec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
    while(1){
        gettimeofday(&tv, nullptr);
        time_t new_msec = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
        if(new_msec - msec >= 1000){
            msec = new_msec;
            timer();
        }
    }

    return EXIT_SUCCESS;
}

#endif