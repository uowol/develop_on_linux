#ifndef INPUT_CPP
#define INPUT_CPP

#include <Utils/Input.hpp>

namespace LinuxGame{
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
        init = true;
    }

    char getch(){
        char ch = 0;
        if(init==false) initTermios();
        ch = getchar();
        if(ch!=27) return ch;   // 화살표 입력이 아니라면 값을 리턴합니다.
        while(!(ch==UP||ch==DOWN||ch==LEFT||ch==RIGHT)){
            ch = getchar();
        }
        return ch;
    }
}

#endif