#include <iostream>
using namespace std;

int main(){
    // 포인터 : 사용할 주소에 이름을 붙인다. 
    int a = 6; // 값
    int* b; // 주소를 참조할 변수 : 위치

    b = &a;

    cout << "a의 값 " << a << endl;
    cout << "*b의 값 " << *b << endl;

    cout << "a의 주소 " << &a << endl;
    cout << "*b의 주소 " << b << endl;

    cout << "b의 주소 " << &b << endl;

    *b = *b + 1;

    cout << "이제 a의 값은 " << a << endl;
     
    return 0;
}

