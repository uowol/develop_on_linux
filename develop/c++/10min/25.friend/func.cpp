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
Time Time::operator+(Time& t){ // 멤버함수
    Time sum;
    sum.mins = mins + t.mins;
    sum.hours = hours + t.hours;
    sum.hours += sum.mins/60;
    sum.mins %= 60;

    return sum;
};
Time Time::operator*(int n){ // 멤버함수
    Time res;
    long resMin = hours * n * 60 + mins * n;
    res.hours = resMin / 60; 
    res.mins = resMin % 60;

    return res;
};
void Time::show(){
    cout << "시간 : " << hours << endl;
    cout << "분 : " << mins << endl;
};
Time::~Time(){

};
// Time operator*(int n, Time& t){ // 프렌드 함수
//     Time res;
//     long resMin = t.hours * n * 60 + t.mins * n;
//     res.hours = resMin / 60; 
//     res.mins = resMin % 60;
//     return res;
// };