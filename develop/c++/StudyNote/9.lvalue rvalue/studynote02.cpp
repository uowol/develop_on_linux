// Lvalue 참조 선언자 &
#include <iostream>
using namespace std;

struct Person
{
    char* Name;
    short Age;
};

int main()
{
   // Person 객체를 선언합니다.
   Person myFriend;

   // myFriend 에 대한 참조를 선언합니다. 
   Person& rFriend = myFriend;

   // 동일한 객체의 필드 값을 수정합니다.
   myFriend.Name = "Bill";
   rFriend.Age = 40;        

   cout << rFriend.Name << " is " << myFriend.Age << endl;
}
