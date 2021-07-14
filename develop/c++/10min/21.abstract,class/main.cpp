#include "Stock.h"

int main(){
    // 자료형: 어떠한 연산을 수행할 수 있는가 생각해보는 것이 중요
    // 클래스: 추상화를 사용자 정의 데이터형으로 변환해주는 수단
    /*
    1. 클래스 선언
    2. 클래스 매서드 선언
    */
    // 추상화: 어떠한 객체를 사실적으로 표현하는 것이 아니라
    //         동일한 특징을 간결한 방식으로, 이해하기 쉽게 표현하는 것
    Stock temp;
    temp.acquire("Panda", 100, 1000);
    temp.show();
    temp.buy(10, 1200);
    temp.show();
    temp.sell(5, 800);
    temp.show();
}