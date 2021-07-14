#include <iostream>
#include <string.h>
using namespace std;

#define SIZE 20
int main(){
    // 복습

    double* p3 = new double[3];
    p3[0] = 0.2; // 이 같은 경우 데이터형이 double이므로
    p3[1] = 0.5; // 다음 포인터가 가리키는 주소는 double의 byte만큼 증가하게됨
    p3[2] = 0.8; 

    // 동적 할당

    char animal[SIZE];
    char* ps;

    cout << "동물 이름을 입력하시오.\n";
    cin >> animal;

    ps = new char[strlen(animal) + 1]; // 동적으로 크기 할당 가능 **중요**
    strcpy(ps, animal);

    cout << "입력하신 동물 이름을 복사하였습니다." << endl;
    cout << "입력하신 동물 이름은 " << animal << "이고, 그 주소는 " << (int*)animal << " 입니다." << endl;
    cout << "복사된 동물 이름은 " << ps << "이고, 그 주소는 " << (int*)ps << " 입니다." << endl;
     
    delete[] ps;

    // 동적 구조체 생성
    struct mStruct{ // 내부 구조체
        char name[20];
        int age;
    };

    mStruct* temp = new mStruct; // mStruct 크기만큼 할당

    cout << "당신의 이름을 입력하세요.\n";
    cin >> temp->name; // '.' 대신 포인터를 활용할 땐 '->'를 사용

    cout << "당신의 나이를 입력하세요.\n";
    cin >> (*temp).age; // *pointer : 주소 속 value에 접근

    cout << temp->name << endl;
    cout << temp->age << endl;
    return 0;
}

