#include <iostream>
using namespace std;

int main(){
    int a = 77;
    char b = a;
    cout << b << endl; // 아스키코드

    char c[] = {'a', 'b', 'c', '\0', 'd'}; // null 문자
    // "" => 명시적으로 null문자가 포함되어 있음 => string 변수
    cout << c << endl;

    bool x = 0;
    bool y = 1;
    bool z = -1; // True
    cout << x << y << z << endl;
    return 0;
}