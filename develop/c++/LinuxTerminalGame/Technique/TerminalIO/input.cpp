#define UP      65
#define DOWN    66
#define RIGHT   67
#define LEFT    68

#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <iostream>

static struct termios setting;
static bool init = false;

void initTermios(){
    tcgetattr(STDIN_FILENO, &setting);  // 터미널 기본입력의 현재 설정값을 setting에 저장합니다.
    setting.c_lflag &= ~ICANON;         // ICANON은 입력을 개행문자로 받을지 결정하는 mask입니다.
    setting.c_lflag &= ~ECHO;           // EHCO는 입력한 문자를 보여줄지 결정하는 mask입니다.
    tcsetattr(STDIN_FILENO, TCSANOW, &setting);
    init = true;
}

void terminalTermios(){
    if(!init) return;
    tcgetattr(STDIN_FILENO, &setting);  // 터미널 기본입력의 현재 설정값을 setting에 저장합니다.
    setting.c_lflag |= ICANON;          // ICANON은 입력을 개행문자로 받을지 결정하는 mask입니다.
    setting.c_lflag |= ECHO;            // EHCO는 입력한 문자를 보여줄지 결정하는 mask입니다.
    tcsetattr(STDIN_FILENO, TCSANOW, &setting);
    init = false;
}

int kbhit(){
    struct timeval tv;
    fd_set rdfs;        // 파일 기술자에 대한 값을 넣을 구조체입니다.

    // 입력값을 받은 즉시 처리하기 위하여 시간을 0으로 설정합니다.
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs); // 파일 기술자에 대한 값을 초기화합니다.
    FD_SET(STDIN_FILENO, &rdfs); // 파일 기술자에 표준 입력에 대한 값을 넣습니다.

    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);

    return FD_ISSET(STDIN_FILENO, &rdfs);    // 해당 이벤트가 발생하였는지 여부를 반환합니다.
}

char getch(){   // for arrow key event
    char ch = 0;
    if(init==false) initTermios();
    if(!kbhit()) return ch;
    ch = getchar();
    if(ch!=27) return ch;   // 화살표 입력이 아니라면 값을 리턴합니다.
    while(!(ch==UP||ch==DOWN||ch==LEFT||ch==RIGHT)){
        ch = getchar();
    }
    return ch;
}

using namespace std;

int main(){
    while(1){
        int ch = getch();
        if(ch == 10) break;
        if(ch != 0)
            cout << ch << '\n';
    }
    terminalTermios();
    return 0;
}
