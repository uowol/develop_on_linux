#include <iostream>

// 3. const 포인터 변수

// 두 번째, const 위치가 type과 변수 이름 사이에 있으면서 포인터 변수 자체를 상수화
int num1 = 1;
int num2 = 2;
int* const ptr = &num1;

int main(){
    ptr = &num2;    // Compile Error
    return 0;
}