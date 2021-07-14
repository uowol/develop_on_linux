#include <iostream>
#ifndef TIMEH
class Time
{
private:
    int hours;
    int mins;
public:
    Time(/* args */);
    Time(int, int);
    void addHours(int);
    void addMins(int);
    Time operator+(Time&);
    Time operator*(int);
    void show();
    int getHours() { return hours; }
    int getMins(){ return mins; }
    ~Time();
    friend Time operator*(int n, Time& t){
        return t * n;
    };
    friend std::ostream& operator<<(std::ostream&, Time&);
};

class NewTime : public Time {
    // 파생클래스는 자기 자신의 생성자를 필요로 한다.
private:
    int day;
public:
    NewTime();
    NewTime(int, int, int);
    void print();
};

#endif // !TIMEH