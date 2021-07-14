#include <iostream>
using namespace std;

int main(){
    // 공용체(union) : 서로 다른 데이터형을 한 번에 한 가지만 보관 가능
    union mUnion{
        int intVal;
        long longVal;
        float floatVal;
    };

    mUnion test;
    test.intVal = 3;
    cout << test.intVal << endl; // 3
    test.longVal = 33;
    cout << test.intVal << endl; // 33
    cout << test.longVal << endl; // 33
    test.floatVal = 3.3;
    cout << test.intVal << endl; // ?
    cout << test.longVal << endl; // ?
    cout << test.floatVal << endl; // 3.3
    // 메모리 절약

    // 열거체(enum) : 기호 상수를 만드는 방법
    enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolat};
    // red, orange, ... 0에서부터 7까지 정수 값을 각각 나타내는 기호 상수로 만듭니다.

    spectrum a = orange; // orange + yellow : error
    cout << a << endl;

    int b;
    b = blue; // (자동)형변환
    b = blue + 3;
    cout<< b << endl;

    enum special_case {A=0, B=2, C=4, D, E, F};
    special_case c = C;
    special_case d = D;
    cout << c << ',' << d << endl;

    return 0;
}