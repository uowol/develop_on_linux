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
    void show();
    ~Time();
};

#endif // !TIMEH