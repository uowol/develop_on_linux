#include <iostream>
#include <cstring>
using namespace std;

int main(){
    const int SIZE = 15;
    char name1[SIZE];

    cout << "입력 : ";
    // cin >> name1; // 사용자 입력, 공백을 포함할 수 없음
    cin.getline(name1, SIZE); // 저장할 변수와 최대 크기, 공백을 포함할 수 있음
    cout << "안녕하세요! " << name1 << "!" << endl;
    cout << strlen(name1) << "글자" << endl; // 한글 한 문자는 3글자로 취급됨
    cout << sizeof(name1) << "바이트" << endl; // 할당된 크기
    cout << name1[0] << endl;
    name1[3] = '\0'; // 여기서 끊기
    cout << name1 << endl;

    string name2 = "아브라카다브라"; // 문자열을 다른 문자열에 통째로 대입할 수 있다!
    // <-> 배열의 한계
    char char1[20];
    string char2;
    // char1 = name1;
    char2 = name2;
    return 0;
}