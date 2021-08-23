#include <iostream>

// 3. const 포인터 변수

// 첫 번째, const 위치가 맨 앞에 있으면서 포인터 변수가 가리키는 값에 대하여 상수화
int num = 1;
const int* ptr = &num;    // 포인터 변수가 '가리키는 값'에 대한 상수화, not 'num 변수'의 상수화

int main(){
    *ptr = 2;   // Compile Error
    num = 2;    // Pass
}