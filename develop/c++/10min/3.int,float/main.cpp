#include <iostream>
#include <climits> // 최대크기 
using namespace std;

int main(){
    int n_int = INT_MAX;
    short n_short = SHRT_MAX;
    long n_long = LONG_MAX;
    long long n_llong = LLONG_MAX;

    cout << "int는 " << sizeof n_int << "바이트" << endl;
    cout << "이 바이트의 최대값은 " << n_int << "이다." << endl;

    cout << "short는 " << sizeof n_short << "바이트" << endl;
    cout << "이 바이트의 최대값은 " << n_short << "이다." << endl;

    cout << "long는 " << sizeof n_long << "바이트" << endl;
    cout << "이 바이트의 최대값은 " << n_long << "이다." << endl;

    cout << "long long는 " << sizeof n_llong << "바이트" << endl;
    cout << "이 바이트의 최대값은 " << n_llong << "이다." << endl;

    unsigned short d = -2; // 65534
    cout << d << endl;

    float a = 3.14;
    int b = 3.14;
    cout << a << " " << b << endl;

    return 0;
}