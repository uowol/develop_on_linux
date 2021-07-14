#include <iostream>
using namespace std;

struct Time{
    int hours;
    int mins;
};

const int minsPerHr = 60;

Time sum(Time*, Time*);
void showTime(Time t1);

int main(){
    // 함수는 원본이 아닌 복사본을 대상으로 작업함, 복사하는 time을 줄일 수 있음!
    Time t1 = {5, 45};
    Time t2 = {4, 55};
    Time total = sum(&t1, &t2);

    showTime(total);
    return 0;
}

Time sum(Time* t1, Time* t2){
    Time total;

    // value에서 멤버로 접근 : .
    // address에서 멤버로 접근 : ->
    total.mins = (t1->mins + t2->mins) % minsPerHr;
    total.hours = (t1->hours + t2->hours + (t1->mins + t2->mins) / minsPerHr);

    return total;
}
void showTime(Time t1){
    cout << t1.hours<<" : "<<t1.mins<<endl;
}