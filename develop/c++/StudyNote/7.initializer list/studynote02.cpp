#include <iostream>

class Foo{
    private:
        int iNum;
        const int c_iNum;
    public:
        Foo(): iNum(5), c_iNum(5){  // 직접 초기화(direct initialization) 방법을 사용하였다.
            // 멤버 변수를 여기서 초기화 할 필요가 없다.
        }
};

int main(){
    return 0;
}

// 멤버 초기화 리스트를 사용하면 값을 할당하지 않고 멤버 변수를 초기화할 수 있다.
// 생성자 본문에서 값을 할당하는 것보다 성능이 더 우수하다.
// const 또는 reference 변수와 같이 초기값이 필요한 멤버를 초기화할 수 있는 유일한 방법이다.
// 멤버 초기화 리스트는 기본 자료형 변수와 클래스 자체인 멤버 모두에서 잘 작동한다.

// 출처: https://boycoding.tistory.com/246 [소년코딩]