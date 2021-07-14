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
    // 기초 클래스에서 가상메서드를 선언하면 상속하는 객체에서 또한 가상이 된다.
    // 파생되는 클래스에서 다시 정의해야 하는 클래스 메서드는 기초 클래스에서 가상 함수로 선언해야한다.
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
    void show();
};

#endif // !TIMEH