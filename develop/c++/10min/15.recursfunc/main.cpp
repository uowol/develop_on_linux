#include <iostream>
using namespace std;

int countDown(int n);

int main(){
    int (*func)(int); // 함수를 지시하는 포인터 **중요**
    func = countDown;

    cout << (*func)(1) << endl;
    return 0;
}

int countDown(int n){
    cout << "Counting..." << n << endl;
    if(n>0){
        countDown(n-1);
    }
    return 0;
}