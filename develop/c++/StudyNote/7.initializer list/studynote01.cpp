#include <iostream>

class Foo{
    private:
        int iNum;
        const int c_iNum;
    public:
        Foo(){
            // 이것은 할당이지, 초기화가 아니다. 즉, int iNum; iNum = 1; 과 같다.
            iNum = 1;
            c_iNum = 1;  // 상수에 값을 할당하는 것과 같으므로 에러가 발생한다.
        }
};