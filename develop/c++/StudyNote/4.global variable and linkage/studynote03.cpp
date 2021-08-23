// 다른 소스 파일에서 선언된 외부 전역 변수를 사용하려면 '변수 전방 선언(variable forward declarations)'을 해야 한다.

// extern 키워드는 두 가지 다른 의미가 있다. 
// 어떤 상황에서는 extern 키워드가 '외부 링크가 있는 변수를 의미' 하고 다른 상황에서는 '다른 어딘가에서 정의된 변수에 대한 전방 선언'을 의미한다.
// 출처: https://boycoding.tistory.com/167?category=1007833 [소년코딩]

#include <iostream>
#include "global.cpp"

extern int g_x;     // forward declaration for g_x (defined in global.cpp) -- g_x can now be used beyond this point in this file

int main(){
    extern int g_y; // forward declaration for g_y (defined in global.cpp) -- g_y can be used beyond this point in main() only
    g_x = 6;
    std::cout << g_y << std::endl;
    return 0;
}

