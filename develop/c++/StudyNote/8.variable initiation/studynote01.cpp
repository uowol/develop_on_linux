#include <iostream>

int main(){
    int iValue = 5; // copy initialization
    int iValue_(5); // direct initialization

    // 직접 초기화는 함수 호출과 매우 유사하지만, 컴파일러는 어떤 이름이 변수이고 어떤 이름이 함수인지를 잘 추적하여 제대로 컴파일한다.
    // 직접 초기화는 일부 데이터 타입에서 복사 초기화보다 성능이 더 뛰어날 수 있다. 
    // 클래스에 관해 설명을 시작하면 다른 이점도 있다. 또한, 초기화와 할당을 구분하는 데도 도움이 된다. 
    // 따라서 복사 초기화보다 직접 초기화를 사용하는 것이 좋다.
    // 출처: https://boycoding.tistory.com/181 [소년코딩]

    int iValue__{5};    // uniform initialization

    // 유니폼 초기화는 형 변환을 허용하지 않는다는 이점이 있다. 변수를 다른 자료형의 값으로 초기화하려고 하면 컴파일러에서 경고 또는 오류가 발생한다.
}

// 출처: https://boycoding.tistory.com/181 [소년코딩]
