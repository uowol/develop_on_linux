#include <iostream>
#include <string.h>

using namespace std;
char str[30];
int main(){
    string text = "abcd";

    // char* v : v는 문자열이 저장된 메모리의 첫 주소를 저장할 수 있는 포인터 변수
    // v 주소 메모리의 내용 변경 가능

    // const char* v : v는 문자열이 저장된 메모리의 첫 주소를 저장할 수 있는 포인터 변수
    // v 주소 메모리의 내용 변경 불가 : v는 "상수문자열"의 포인터 변수라는 것
    // 한편, const의 대상이 v 자체가 아니므로 v가 가리키는 주소는 변경 가능함
    // ex)  v = "test"  : 가능
    //      *v = "test" : 불가능

    // char* const v : v는 문자열이 저장된 메모리의 첫 주소를 저장할 수 있는 포인터 변수
    // 초기화 할 때 한 번 지정된 메모리 주소를 변경할 수 없음
    
    const char* pch = text.c_str(); // pch는 문자열의 내부 버퍼의 시작 주소값을 리턴, 내용변경 불가
    char* tar = (char*)pch; // 시작 주소값을 저장, 내용 변경 가능
    tar[3] = 'b';
    strcpy(str, text.c_str());
    cout << str << endl; 

    const char* _pch = &text[0];
    char* _tar = (char*)pch;
    _tar[3] = 'b';
    strcpy(str, text.c_str());
    cout << str << endl; 

    // printf("%s\n", text);
}