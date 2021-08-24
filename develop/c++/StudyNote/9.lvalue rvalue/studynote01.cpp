#include <iostream>

// expression
// ㄴ glvalue       - 개체, 비트 필드 또는 함수의 ID를 결정하는 식
//      ㄴ lvalue   - xvalue가 아닌 glvalue
//      ㄴ xvalue   - 소스를 다시 사용할 수 있는 개체 또는 비트 필드를 나타내는 glvalue(일반적으로 수명이 끝나서)
// ㄴ rvalue        - xvalue 또는 prvalue
//      ㄴ xvalue
//      ㄴ prvalue  - 개체 또는 비트 필드를 초기화하거나 연산자 값을 계산하는 식

// lvalue에는 프로그램이 액세스 할 수 있는 주소가 있다.
// - 변수명
// - const 변수
// - 배열 요소
// - lvalue 참조를 반환하는 함수
// - 비트필드
// - union과 class 멤버

// prvalue 표현식에는 프로그램이 액세스 할 수 있는 주소가 없다.
// - 리터럴(Literal)
// - 비 참조 유형을 반환하는 함수 호출
// - 식 평가 중에 생성되지만 컴파일러에서만 액세스할 수 있는 임시 개체

int main(){
    int i, j, *p;

    // 옳은 사용방법 : 변수 i는 lvalue이고 리터럴 7은 prvalue이다.
    i = 7; 

    // 잘못된 사용방법 : 왼쪽 피연산자는 lvalue이어야 합니다.
    7 = i;
    j * 4 = 7;

    // 옳은 사용방법 : 역참조된 포인터는 lvalue이다.
    *p = i;

    // 옳은 사용방법 : 조건 연산자 (?:)는 lvalue를 반환한다.
    ((i<3) ? i : j) = 7;
}