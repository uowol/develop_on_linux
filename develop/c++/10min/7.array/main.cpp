#include <iostream>
using namespace std;

int main(){
    short month[12] = {1, 2, 3}; // 나머지 원소는 0으로 초기화
    cout << month << endl; // 주소값
    cout << month[0] << " " << month[10] << endl; // 주소값

    int arr[] = {1, 2, 3, 4};
    cout << arr[4] << endl; // 갈비지트뤠시값

    char a[6] = {'H', 'e', 'l', 'l', 'o', '\0'}; // null문자 중요!
    cout << a << endl;
    char b[] = "hello"; // null문자 자동 삽입!
    cout << b << endl;
    return 0;
}