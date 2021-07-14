#include <iostream>
using namespace std;

// class 혹은 typeName
template <class Any>
Any sum(float, Any);
template <class Any>
Any sum(int, Any);

int main() {
    // 함수 템플릿: 구체적인 데이터형을 포괄할 수 있는 일반형으로 정의
    int a = 3;
    int b = 4;
    cout << sum(a,b) << endl;
    float c = 3.14;
    float d = 1.592;
    cout << sum(c, d) << endl;

    cout << sum(a, c) << endl;

    return 0;
}

template <class Any>
Any sum(float a, Any b){
    return a+b;
}
template <class Any>
Any sum(int a, Any b){
    return a+b;
}