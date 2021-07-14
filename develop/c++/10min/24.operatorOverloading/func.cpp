#include "time.h"
using namespace std;

Time::Time(/* args */){
    hours = mins = 0;
};
Time::Time(int h, int m){
    hours = h;
    mins = m;
};
void Time::addHours(int h){
    hours+=h;
};
void Time::addMins(int m){
    mins+=m;
    hours += mins/60;
    mins %= 60;
};
Time Time::operator+(Time& t){
    Time sum;
    sum.mins = mins + t.mins;
    sum.hours = hours + t.hours;
    sum.hours += sum.mins/60;
    sum.mins %= 60;

    return sum;
};
void Time::show(){
    cout << "시간 : " << hours << endl;
    cout << "분 : " << mins << endl;
};
Time::~Time(){

};