#include <iostream> 
using namespace std;

int sum(int, int);
float sum(float, float); // 매개변수가 포인트

int main(){
    // 함수의 오버로딩: 서로 다른 데이터형 그러나 같은 작업에 주로 사용
    cout << sum(2, 3) << endl;
    cout << sum(2.2f, 3.3f) << endl;

    return 0;
}

int sum(int a, int b){
    return a + b;
}
float sum(float a, float b){
    return a+b;
}