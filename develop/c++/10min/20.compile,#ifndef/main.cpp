#include "struct.h" 
using namespace std;
// 헤더 파일을 여러 파일에 포함시킬 때 반드시 단 한번만 포함시켜야 한다.
// 만약 다른 헤더파일이나 링크된 c/c++ 파일에서 다시 한번 동일한 헤더를 불러오면 에러 발생
// 이 때 ifndef(if-not-define)을 사용한다.

// 헤더파일
/*
1. 함수 원형
2. #define이나 const를 사용하는 기호 상수
3. 구조체 선언
4. 클래스 선언
5. 템플릿 선언
6. 인라인 함수
*/

int main(){
    MyStruct PandaCoding = {
        "Panda",
        26,
    };

    display(PandaCoding);
    return 0;
}