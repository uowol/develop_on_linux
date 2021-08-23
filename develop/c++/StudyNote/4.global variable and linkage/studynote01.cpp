// 변수를 고려할 때는 두 가지 속성을 고려해야 한다.
// 1. duration  : 생성 / 소멸 주기
// 2. scope     : 접근할 수 있는 범위
// 3. linkage   : 같은 이름의 여러 식별자가 같은 식별자를 참조하는지를 결정

#include <iostream>

int value = 5;

int main(){
    int value = 7;  // 전역변수를 숨깁니다. (shadowing and hide)
    value++;        // 지역변수를 증가시킵니다.
    ::value--;      // 전역변수를 증가시킵니다.

    std::cout << value << std::endl;
    std::cout << ::value << std::endl;
    return 0;
}

// 전역 변수와 같은 지역 변수를 정의하는 건 피해야 한다.
// 관습에 따라 일반적으로 전역 변수를 정의할 때는 g_ 접두사를 붙인다.
// 출처: https://boycoding.tistory.com/167?category=1007833 [소년코딩]
