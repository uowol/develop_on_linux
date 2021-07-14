#include <iostream>
#include "time.h"
using namespace std;

int main(){
    // C++ Friend : private 변수에 접근 가능함
    Time t1(1, 20);
    Time t2, t3;

    t2 = 3*t1;
    // t2 = operator*(3, t1);
    t2.show();

    t3 = t1*2;
    // t2 = t1.operator*(3);
    t3.show();

    return 0;
}