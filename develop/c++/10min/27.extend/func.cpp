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
std::ostream& operator<<(std::ostream& os, Time& t){
    os << t.hours << "시간 " << t.mins << "분\n";
    return os;
};

NewTime::NewTime() : Time(){ // 멤버 초기자 리스트 문법 : Time()객체가 먼저 생성
    // 본래 addHours, addMins 는 자유로이 접근 가능하나 hours나 mins와 같은 private 멤버는 접근 불가
    day = 0; // hours=0, mins=0
};
NewTime::NewTime(int h, int m, int d) : Time(h, m){
    day = d;
};
void NewTime::print(){
    cout << "날짜 : " << day << endl;
    show();
}