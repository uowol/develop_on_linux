#ifndef LINUX_GAME_INPUT_CPP
#define LINUX_GAME_INPUT_CPP


#include <Util/Input.hpp>


void LinuxGame::initTerminos(){
    tcgetattr(STDIN_FILENO, &setting);  // STDIN_FILENO: 표준입력 파일의 파일기술자 = 0
    setting.c_lflag &= ~ICANON;         // c_lflag: local flags, ICANON: 입력을 개행문자로 받을 지 결정하는 bit mask로, 부정의 의미로 ~를 넣어줍니다.
    setting.c_lflag &= ~ECHO;           // EHCO: 입력한 문자를 보여줄 지 결정하는 bit mask로, 없어야 하므로 ~를 넣어줍니다.
    tcsetattr(STDIN_FILENO, TCSANOW, &setting); // TCSANOW: 설정을 즉시 적용한다.
    init = true;
} // init Terminal Input/Output Setting

char LinuxGame::getch(){
    char ch = -1;
    if(init==false) initTerminos();

    if(!kbhit()) return -1;
    ch = getchar();
    if(ch == UP || ch == DOWN || ch == LEFT || ch == RIGHT) return ch;
    return -1;
    
} // input without enter

int LinuxGame::kbhit(){
    struct timeval tv;
    fd_set rdfs; // File Descriptor (이하 FD) 를 저장하는 구조체

    tv.tv_sec = 0;  // seconds
    tv.tv_usec = 0; // micro seconds

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);

    return FD_ISSET(STDIN_FILENO, &rdfs);
} // watch keyboard event 

#endif