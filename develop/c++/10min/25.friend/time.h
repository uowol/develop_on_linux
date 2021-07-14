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
    ~Time();
    friend Time operator*(int n, Time& t){
        return t * n; // 멤버함수 operator*(int) 호출 **중요**
    }; // 멤버는 아니지만 멤버처럼 private 변수에 접근 가능
    // 더 이상 private 변수에 직접 접근하지 않으므로 friend를 뺄 수 있지만 interface 쪽으로 생각해보면 이것이 맞는 표현
};

#endif // !TIMEH