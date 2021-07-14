#include <iostream>
using namespace std;

int main(){
    int a = 3.141592;
    cout << a << endl;

    char ch = 'M';
    cout << (int)ch << " " << int(ch) << endl;

    // C++
    cout << static_cast<int>(ch) << endl;
    return 0;
}