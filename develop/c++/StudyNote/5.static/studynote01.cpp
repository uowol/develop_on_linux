#include <iostream>

// static 키워드는 블록 내에서 선언된 지역 변수에서도 사용할 수 있다. 
// 지역 변수는 '자동 주기(auto duration)'를 가지며, 정의되는 시점에서 생성되고 초기화되며, 정의된 블록이 끝나는 지점에서 소멸한다. 

// static 키워드를 사용한 지역 변수는 완전히 다른 의미가 있다. 
// static 키워드를 사용한 지역 변수는 '자동 주기(auto duration)'에서 '정적 주기(static duration)'로 바뀐다. 
// 이것을 정적 변수(static variable)라고도 부르는데, 생성된 스코프(=범위)가 종료한 이후에도 해당 값을 유지하는 변수다. 
// 또한, 정적 변수는 한 번만 초기화되며 프로그램 수명 내내 지속된다.

void IncrementAndPrint(){
    // g_를 사용하여 전역 변수에 접두어를 지정하는 것처럼 s_를 사용하여 정적 변수에 접두사를 지정하는 것이 일반적이다.
    static int s_value = 1;   
    ++s_value;
    std::cout << s_value << std::endl;
}

int main(){
    IncrementAndPrint();
    IncrementAndPrint();
    IncrementAndPrint();
    return 0;
}

// 정적 변수의 가장 일반적인 용도 중 하나는 고유 식별자 생성기다. 
// 프로그램 내에서 다수의 유사한 개체를 처리할 때 각 개체에 고유 ID 번호를 할당하여 식별하는 것이 유용한 경우가 많다. 
// 정적 변수를 사용하면 이 작업을 쉽게 수행할 수 있다.

int generateID()
{
    static int s_itemID = 0;
    return s_itemID++; // s_isemID의 복사본을 만들고, 실제 s_isemID를 증가시킨 다음 복사본의 값을 반환한다.
}

// 출처: https://boycoding.tistory.com/169?category=1007833 [소년코딩]