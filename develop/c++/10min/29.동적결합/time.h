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
    virtual void show(); // 가상메서드
    // 동적결합 : Time 객체를 상속한 NewTime 객체의 포인터에서 show 함수를 호출하였을 때,
    //            NewTime 객체에 선언된 show 함수를 실행함.
    int getHours() { return hours; }
    int getMins(){ return mins; }
    virtual ~Time();
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
    void show();
    ~NewTime();
};

#endif // !TIMEH