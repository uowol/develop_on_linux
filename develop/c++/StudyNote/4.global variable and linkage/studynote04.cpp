#include <iostream>
#include "constant.cpp"

extern const double g_gravity;

int main(){
    std::cout << g_gravity << std::endl;    // linker error가 발생해야 하지만 잘 작동함 (?)
    return 0;
}