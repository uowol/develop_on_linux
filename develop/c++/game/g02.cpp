#include <time.h> // 전처리기: 컴파일 당시 값이 정해짐
#include <iostream>
using namespace std;

int main(){
    // 난수 발생: 난수 테이블이 고정되어 있어 쉬지 않고 바뀌기 위해선 시간을 사용 -> 시드
    srand((unsigned int)time(0)); // 시드 설정

    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    cout << (rand() % 100) << endl; // 0~99
    cout << (rand() % 101 + 100) << endl; // 100~200

    // 실수로 뽑으려면?
    cout << (rand() % 10000 / 100.f) << endl; // 소수점 둘째 자리까지

    // 강화하기
    int iUpgrade = 0;
    cout << "Upgrade기본 수치를 입력하세요 : ";
    cin >> iUpgrade;

    float fPercent = rand() % 10000 / 100.f;

    // 강화확률 : 업그레이드가 0~3: 100%, 4~6: 40%, 7~9: 10%, 10~13: 1%, 14~15: 0.01%
    cout << "Upgrade : " << iUpgrade << endl;
    cout << "Percent : " << fPercent << endl;

    if (iUpgrade <= 3)
        cout << "강화 성공" << endl;
    else if (iUpgrade <= 6 && fPercent < 40.f)
        cout << "강화 성공" << endl;
    else if (iUpgrade <= 9 && fPercent < 10.f)
        cout << "강화 성공" << endl;
    else if (iUpgrade <= 13 && fPercent < 1.f)
        cout << "강화 성공" << endl;
    else if (iUpgrade <= 15 && fPercent < .1f)
        cout << "강화 성공" << endl;
    else   
        cout << "강화 실패" << endl;

    return 0;
}