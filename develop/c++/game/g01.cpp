#include <iostream>
using namespace std;

int main(){
    // 버프 코드
    const int iAttack = 0x00000001;     //     1 int형이니까 'i'Attack
    const int iArmor = 0x00000002;      //    10
    const int iHP = 0x00000004;         //   100
    const int iMP = 0x00000008;         //  1000
    const int iCritical = 0x00000010;   // 10000

    // 버프 유무
    int iBuf = iAttack | iHP | iCritical; // 10101
    cout << (iBuf & iAttack) << endl;

    // 스위치 개념 구현 : XOR
    cout << (iBuf & iHP) << endl;
    iBuf ^= iHP;
    cout << (iBuf & iHP) << endl;

    // shift연산자 : <<, >>, 속도가 훨씬 빠름
    // << : 빠른 곱하기
    // 20 << 2 = 80
    // 10100 => 1010000 = 80
    // 20 << 3 = 160 : 위의 두배, *2보다 훨씬 빠름
    // 10100 => 10100000 = 160
    // >> : 빠른 나누기(나누기가 원래 무거운 연산, 오죽하면 *0.5가 더 빠름) 
    // 20 >> 2 = 5
    // 10100 => 101 = 5
    // 20 >> 3 = 2
    // 10100 => 10 = 2

    // 응용 : 변수를 쪼개서 쓰는 방법
    int iHigh = 187;
    int iLow = 13560;

    int iNumber = iHigh; // iNumber에는 187이 들어가 있다.
    iNumber <<= 16;

    // 하위 16비트를 채운다.
    iNumber |= iLow; // OR연산

    // High값을 출력한다.
    cout << "High: " << (iNumber >> 16) << endl;
    cout << "Low: " << (iNumber & 0x0000ffff) << endl; // 상위 16비트값 제거해버리기

    enum Num{
        NUM_0,
        NUM_1
    };

    #define NUM_4 4

    cout << NUM_0 << endl;
    cout << NUM_4 << endl;
    cout << sizeof(NUM_0) << endl; // 무조건 4byte

    Num eNum = (Num)1; // 형변환 시켜주면 들어는 간다.
    cout << typeid(eNum).name() << endl; // 


    return 0;
}