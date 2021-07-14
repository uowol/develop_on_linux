#include <iostream>

using namespace std;

int main(){
    // new 연산자
    /*
    어떤 데이터형을 원하는지 new 연산자에게 알려주면 new 연산자는 그에 알맞은 크기의 메모리 블록을 찾아
    그 블록의 '주소'를 리턴
    */
    int a;
    int* b = &a;
    int* pointer = new int; // 메모리 제어권을 사용자에게 줄 수 있다!

    // delete 연산자
    int *ps = new int; // 메모리 할당
    // 메모리 사용
    delete ps; // 메모리 반환
    // 1. new로 대입하지 않은 메모리는 delete로 해제할 수 없다.
    // 2. 같은 메모리를 연달아 두 번 해제할 수 없다.
    // 3. new[]로 메모리를 대입할 경우 delete[]로 해제한다.
    
    double* p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 + 1; // p3가 포인터여서 가능, 배열 이름이었다면 X
    // p3 가 공간의 주소 대한 데이터 변수이기 때문에 가능한 것.

    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << "\n.";

    p3 = p3-1; // 원래 주소로 되돌리고,
    delete[] p3; // 대괄호 주의

    return 0;
}

