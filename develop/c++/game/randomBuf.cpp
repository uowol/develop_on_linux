#include <iostream>
#include <time.h>

using namespace std;

int drink(int);

int iBuf[] = { 
    0x00000001,        //Attack: 00000001
    0x00000002,         //Armor: 00000010
    0x00000004,            //HP: 00000100
    0x00000008,            //MP: 00001000
    0x00000010,      //Critical: 00010000
    0x00000020,        //Damage: 00100000
    0x00000040,        //Sacred: 01000000
    0x00000080,          //Evil: 10000000
};
string sBuf[] = {
    "Attack",
    "Armor",
    "HP",
    "MP",
    "Critical",
    "Damage",
    "Sacred",
    "Evil"
};

int main(){
    // 시드설정
    srand((unsigned int) time(0));

    int iPotion;
    int iStatus = 0x00000000;
    
    cout << "섭취할 포션을 고르세요. (소:0, 중:1, 대:2)" << endl;
    cin >> iPotion;
    switch(iPotion){
        case 0:
            cout << "___는 랜덤 버프 포션(소)을(를) 섭취했다!" << endl;
            break;
        case 1:
            cout << "___는 랜덤 버프 포션(중)을(를) 섭취했다!" << endl;
            break;
        case 2:
            cout << "___는 랜덤 버프 포션(대)을(를) 섭취했다!" << endl;
            break;
    }
    iStatus |= drink(iPotion);
    for(int i=0;i<8;i++){
        if (iStatus & (1<<i)){
            cout << "___는 " << sBuf[i] << " 버프를 획득했다!" << endl;
        }
    }
    
    return 0;
}

int drink(int potion){
    int effect = 0x00000000;
    for (int i=0; i<=potion; i++){
        int n = (int)rand()%8;
        while(effect & iBuf[n]) n = (int)rand()%8;
        effect |= iBuf[n];
    }
    return effect;
}