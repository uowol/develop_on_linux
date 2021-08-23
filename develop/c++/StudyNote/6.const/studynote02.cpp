#include <iostream>

// 2. const 멤버 변수
class Foo{
    private:
        const int n;    // 메모리 할당이 아님.
    public:
        Foo():n(5){     // 리스트 초기화 방법을 이용하면 할당이 아닌 초기화를 할 수 있다.
            std::cout << n << "\n";
        } 

};