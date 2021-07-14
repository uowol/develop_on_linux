#include <iostream>
using namespace std;

int main(){
    int a[10] = {1,3,5,7,9};
    for(int i : a){
        cout << i;
    }

    return 0;
}