#include "time.h"
using namespace std;

int main(){
    Time t1(3,45);

    t1.show();

    int x = 5;
    int y = 8;

    (cout << x) << y << endl; // std::ostream& operator<<(std::ostream&,...)() 함수라고 볼 수 있음

    cout << t1;
}