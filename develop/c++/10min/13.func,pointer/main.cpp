#include <iostream>
using namespace std;

const int SIZE = 8;
int sumArr(int*, int*);

int main(){
    int arr[SIZE] = {1,2,4,8,16,32,64,128};
    cout << "size of arr " << sizeof arr << endl;
    int sum = sumArr(arr, arr+SIZE); // 배열 이름을 배열의 시작 주소로 인식

    cout << "함수의 총 합은 " << sum << "입니다.\n";

    cout << arr[0] << endl;
    return 0;
}

// int sumArr(int* arr, int n){ // 실질적으로 표현하고자 한다면 포인터를 사용
//     int total = 0;

//     cout << "size of arr " << sizeof arr << endl;
//     for(int i=0; i<n; i++){
//         total += arr[i];
//     }

//     arr[0] = 999;
//     return total;
// }

int sumArr(int* begin, int* end){ // 시작주소와 끝 주소를 줄 수 있음
    int total = 0;

    int* pt;
    for(pt=begin; pt!=end; pt++){
        total += *pt;
    }
    return total;
}