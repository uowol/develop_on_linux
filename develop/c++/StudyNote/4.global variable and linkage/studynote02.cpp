// static and extern keywords for linkage

// 링크가 없는 변수는 정의된 제한된 범위에서만 참조할 수 있다. 
// 지역 변수가 링크가 없는 변수의 예이다. 이름은 같지만 다른 함수에서 정의된 지역 변수는 링크가 없다. 각 변수는 독립적이다.
// 출처: https://boycoding.tistory.com/167?category=1007833 [소년코딩]

#include <iostream>

static int g_x;         // 내부 링크 -> 정의된 소스 파일 내에서 어디서나 접근 가능
extern int g_y;         // 외부 링크 -> 정의된 소스 파일 외의 파일에서도 접근 가능
int g_z;                // 기본적으로 전역 변수는 extern 변수로 간주한다. 즉, 외부에서 접근 가능하다.
const int g_const = 2;  // 그러나, 상수(const) 전역변수는 static 변수로 간주한다. 

int main(){
    return 0;
}