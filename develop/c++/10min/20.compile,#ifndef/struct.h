#ifndef STRUCT // 기호상수화 시켜 이후 들어오는 입력을 '무시'시킴.

#include <iostream>
// using namespace std;
// 되도록이면 header 파일 안에는 using을 사용하지 말 것, 충돌 위험 존재

struct MyStruct{
    std::string name;
    int age;
};

void display(MyStruct&);
// void display(MyStruct& tmp){
//     cout << "이름: " << tmp.name << endl;
//     cout << "나이: " << tmp.age << endl;
// }

#endif