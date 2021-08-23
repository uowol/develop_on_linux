#include <iostream>

// const 멤버 함수

int GetString(void) const;  // Compile Error - class의 멤버 함수만 상수화 가능

// 해당 멤버 함수 내에서는 모든 멤버 변수를 상수화 시킨다는 의미
class Foo{
    private:
        int num;
    public:
        Foo():num(1){};
        int GetNum(void) const{
            int a = 1;
            a++;        // 지역 변수는 가능
            num = 2;    // Compile Error
            return num;
        }
};

int main(){
    return 0;
}