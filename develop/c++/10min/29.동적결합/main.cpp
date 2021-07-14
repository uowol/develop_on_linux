#include "time.h"
using namespace std;

const int MAX =3;

int main(){
    Time* times[MAX]; // 배열은 한 자료형만을 저장할 수 있으나 상속된 객체의 경우 포인터를 사용하여 저장할 수 있음.
    int day;
    int hours;
    int mins;
    for(int i=0;i<MAX;i++){
        cout << i+1 << "번 째 원소를 정의합니다." << endl;
        cout << "시간을 입력하세요: ";
        cin >> hours;
        cout << "분을 입력하세요: ";
        cin >> mins;
        char check;
        cout << "일 정보가 있다면 1, 없다면 0을 입력하세요;" << endl;
        cin >> check;
        if(check=='0'){
            times[i] = new Time(hours, mins); // new를 사용하였으므로 delete사용해주는 거 잊지 말기
        }else{
            cout << "일을 입력하십시오." << endl;
            cin >> day;
            times[i] = new NewTime(hours, mins, day);
        }
    }

    for (int i=0; i<MAX; i++){
        cout << i+1 << "번 째 정보입니다.\n";
        times[i]->show();
    }
    for (int i=0; i<MAX; i++){
        delete times[i]; // 파괴자 역시 virtual로 선언해 줄 필요가 있음
    }
    return 0;
}