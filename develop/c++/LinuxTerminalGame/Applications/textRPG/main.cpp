#include <iostream>
#include <time.h>
using namespace std;

#define NAME_SIZE 64

enum MAIN_MENU{
    MM_NONE,
    MM_MAP,
    MM_STORE,
    MM_INVENTORY,
    MM_EXIT
};

enum MAP_TYPE{
    MT_NONE,
    MT_EASY,
    MT_NORMAL,
    MT_HARD,
    MT_BACK
};

enum JOB{
    J_NONE, // 시작과
    J_KNIGHT,
    J_ARCHOR,
    J_WIZARD,
    J_LOGGER,
    J_END // 끝을 명시해 놓는 것이 이후 유지보수에 용이하다.
};

struct _tagPlayer{
    char    strName[NAME_SIZE];
    char    strJobName[NAME_SIZE];
    JOB     eJob;
    int     iAttackMin;
    int     iAttackMax;
    int     iArmorMin;
    int     iArmorMax;
    int     iHP;
    int     iHPMax;
    int     iMP;
    int     iMPMax;
    int     iExp;
    int     iLevel;
};

struct _tagMonster{
    char    strName[NAME_SIZE];
    // char    strJobName[NAME_SIZE];
    // JOB     eJob;
    int     iAttackMin;
    int     iAttackMax;
    int     iArmorMin;
    int     iArmorMax;
    int     iHP;
    int     iHPMax;
    int     iMP;
    int     iMPMax;
    int     iLevel;
    int     iExp; // 획득 Exp
    int     iGoldMin;
    int     iGoldMax;
};

int main(){
    // init();
    while(true){
        system("clear");
        cout << "1. 맵" << endl;
        cout << "2. 상점" << endl;
        cout << "3. 가방" << endl;
        cout << "4. 종료" << endl;
        cout << "메뉴를 선택하세요 : ";
        int iMenu;
        cin >> iMenu;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1024, '\n');
        }

        if(iMenu == MM_EXIT) break;

        switch (iMenu)
        {
        case MM_MAP:
            while(true){
                system("clear");
                cout << "1. EASY" << endl;
                cout << "2. NORMAL" << endl;
                cout << "3. HARD" << endl;
                cout << "4. 뒤로가기" << endl;
                cout << "맵을 선택하세요 : ";
                int iMap;
                cin >> iMap;
                if(cin.fail()){
                    cin.clear();
                    cin.ignore(1024, '\n');
                }

                if(iMap == MT_BACK) break;
            }
            break;
        
        case MM_STORE:
            break;
        
        case MM_INVENTORY:
            break;
        
        default:
            break;
        }


    }

    return 0;
}