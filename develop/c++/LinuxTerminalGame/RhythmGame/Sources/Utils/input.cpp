#ifndef LINUX_GAME_INPUT_CPP

#include <Utils/input.hpp>

// 입력을 개행 없이 받을 수 있게 합니다.
void LinuxGame::initTermios(void){
    tcgetattr(STDIN_FILENO, &setting);  // 터미널 기본입력의 현재 설정값을 setting에 저장합니다.
    setting.c_lflag &= ~ICANON;         // ICANON은 입력을 개행문자로 받을지 결정하는 mask입니다.
    setting.c_lflag &= ~ECHO;           // EHCO는 입력한 문자를 보여줄지 결정하는 mask입니다.
    tcsetattr(STDIN_FILENO, TCSANOW, &setting);
    init = true;
}
void LinuxGame::resetTermios(void){
    tcgetattr(STDIN_FILENO, &setting);  // 터미널 기본입력의 현재 설정값을 setting에 저장합니다.
    setting.c_lflag |= ICANON;          // ICANON은 입력을 개행문자로 받을지 결정하는 mask입니다.
    setting.c_lflag |= ECHO;            // EHCO는 입력한 문자를 보여줄지 결정하는 mask입니다.
    tcsetattr(STDIN_FILENO, TCSANOW, &setting);
    init = false;
}

int LinuxGame::kbhit(void){
    struct timeval tv;
    fd_set rdfs;    // 파일 기술자에 대한 값을 넣을 구조체입니다.

    // 입력값을 받은 즉시 처리하기 위하여 시간을 0으로 설정합니다.
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs); // 파일 기술자에 대한 값을 초기화합니다.
    FD_SET(STDIN_FILENO, &rdfs); // 파일 기술자에 표준 입력에 대한 값을 넣습니다.

    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
    /*
        첫 번째 인자의 값 미만의 mask를 확인하므로 표준 입력에 대한 이벤트를 감지하기 위해 +1을 해줍니다.
        읽고자 하는 파일 기술자를 넣어주고 쓰거나 제외할 파일 기술자는 없으므로 NULL을 넣어줍니다.
        원래는 배열 형식이지만 우리는 하나의 값이므로 ref를 넣어줍니다.
        마지막 변수는 time out 값입니다. 값을 즉시 확인하기 위하여 0을 넣어두었습니다.

        표준 입력이 발생하면 해당 mask를 제외한 모든 mask가 0으로 바뀝니다.
    */

    return FD_ISSET(STDIN_FILENO, &rdfs);    // 해당 이벤트가 발생하였는지 여부를 반환합니다.
}

char LinuxGame::getch(void){
    char ch = 0;
    if(init==false) initTermios();
    if(!kbhit()) return ch; // 키보드 입력이 감지되지 않았을 경우 NULL값(0)을 반환합니다.
    ch = getchar();
    if(ch!=27) return ch;   // 화살표 입력이 아니라면 값을 리턴합니다.
    while(!(ch==UP||ch==DOWN||ch==LEFT||ch==RIGHT)){
        ch = getchar();
    }
    return ch;
}


#endif