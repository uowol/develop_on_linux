#include <iostream>
using namespace std;

#define NAME_SIZE 64
#define STUDENT_MAX 10

struct Student
{
    /* data */
    char strName[NAME_SIZE];
    int iNumber;
    int iKor;
    int iEng;
    int iMath;
    int iTotal;
    float fAvg;
};

enum MENU{
    MENU_NONE,
    MENU_INSERT,
    MENU_DELETE,
    MENU_SEARCH,
    MENU_OUTPUT,
    MENU_EXIT
};

int main(){
    Student tStudentArr[STUDENT_MAX] = {};

    int iStudentCount = 0;
    int iStdNumber = 1;

    while(true){
        system("clear");

        cout << "1. 학생등록" << endl;
        cout << "2. 학생제거" << endl;
        cout << "3. 학생탐색" << endl;
        cout << "4. 학생출력" << endl;
        cout << "5. 종료" << endl;
        cout << "메뉴를 선택하세요 : " ;
        int iMenu;
        cin >> iMenu;

        // cin은 만약 오른쪽에 int 변수가 오면 문자가 들어올 경우 에러가 난다. 따라서 이 경우 예외처리를 해주어야 한다.
        // 에러가 발생하면 cin 내부의 에러버퍼를 비워주지만 cin 내부에 입력버퍼가 있는데 입력한 값을 저장해놓고 그 값을 
        // 변수에 넣어주는 역할을 한다. 이 입력버퍼에 \n이 남아있으므로 버퍼를 순회하여 \n을 지워준다.
        // 버퍼: 임시 저장 공간 

        // 먼저 에러를 체크한다.
        if(cin.fail()){
            // 에러버퍼를 지워준다.
            cin.clear();

            // \n을 지워준다.
            cin.ignore(1024, '\n'); // 첫번째: 검색하고자 하는 버퍼 크기, 두번째: 찾고자 하는 문자를 넣어준다.
            continue;
        }

        if(iMenu == MENU_EXIT) break;

        switch(iMenu){
            case MENU_INSERT:
                system("clear");

                if(iStudentCount == STUDENT_MAX) break;

                // 이름, 국어, 영어, 수학을 입력받고 학번, 총점, 평균은 연산을 통해 계산해준다.
                cout << "이름 : ";
                cin >> tStudentArr[iStudentCount].strName; // space bar 역시 문자 입력의 끝으로 인식하는 문제 => cin.getline()으로 해결
                // cin.getline(문자열, 크기) : 이전의 \n 를 입력으로 받아버리기에 cin.ignore(1024, '\n'); 으로 비워주어야 한다.

                cout << "국어 : ";
                cin >> tStudentArr[iStudentCount].iKor;
                cout << "수학 : ";
                cin >> tStudentArr[iStudentCount].iMath;
                cout << "영어 : ";
                cin >> tStudentArr[iStudentCount].iEng;

                tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor
                    + tStudentArr[iStudentCount].iMath
                    + tStudentArr[iStudentCount].iEng;

                tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3.f;

                tStudentArr[iStudentCount].iNumber = iStdNumber;

                ++iStdNumber;
                ++iStudentCount;
                break;
            case MENU_DELETE:
                break;
            case MENU_SEARCH:
                break;
            case MENU_OUTPUT:
                system("clear");
                for(int i=0; i<iStudentCount; i++){
                    cout << "이름 : " << tStudentArr[i].strName << endl;
                    cout << "학번 : " << tStudentArr[i].iNumber << endl;
                    cout << "국어 : " << tStudentArr[i].iKor << endl;
                    cout << "수학 : " << tStudentArr[i].iMath << endl;
                    cout << "영어 : " << tStudentArr[i].iEng << endl;
                    cout << "총점 : " << tStudentArr[i].iTotal << endl;
                    cout << "평균 : " << tStudentArr[i].fAvg << endl;
                }
                // cin.getline(nullptr, 10);
                break;
            case MENU_EXIT:
                break;
            default:
                cout << "잘못 입력하셨습니다." << endl;

        }

    }
    return 0;
}