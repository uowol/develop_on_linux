#include <iostream> 
using namespace std;

inline float square(float x) {return x*x;} // inline 함수
int sumArr(int* arr, int n = 1); // default 매개변수, 제일 오른쪽이어야! **중요**

int main(){
    // 일반적인 함수의 호출은 함수의 주소로 점프하는 과정
    // 인라인 함수는 컴파일된 함수 코드가 프로그램의 다른 코드에 삽입되는 것
    // 컴파일러의 인라인 함수 호출 = 점프 X 대응하는 함수 코드로 대체 O
    // 프로그램의 실행속도 UP
    int a = 5;
    cout << square(a) << endl;

    // 디폴트 매개변수: 인자를 생략하였을 때 자동으로 들어가는 value
    int arr[] = {1,2,3,4,5};
    cout << sumArr(arr) << endl;
    return 0;
}

int sumArr(int* arr, int n){
    int total = 0;

    for(int i=0;i<n;i++){
        total += arr[i];
    }

    return total;
}