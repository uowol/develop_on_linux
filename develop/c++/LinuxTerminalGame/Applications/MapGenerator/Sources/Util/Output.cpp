#ifndef LINUX_GAME_OUTPUT_CPP
#define LINUX_GAME_OUTPUT_CPP

#include <Util/Output.hpp>


// 사실 출력 함수가 아닌 명령어를 통한 작동입니다. \033[L;Cf 가 Lows,Columns으로 좌표를 이동시키는 명령어입니다. 
void LinuxGame::gotoxy(const int &x, const int & y){
    printf("%c[%d;%df", 0x1B, y, x); // 27: ESC, escape == \e, => \e[<L>;<C>f 
}

LinuxGame::OutputBuffer::OutputBuffer(){}
LinuxGame::OutputBuffer::OutputBuffer(std::string s){
    buffer = s;
    size = s.length();
}
LinuxGame::OutputBuffer::OutputBuffer(int _size, char ch = '\0'){
    resize(_size, ch);  // 주어진 문자로 주어진 사이즈 만큼의 버퍼를 채웁니다.
}

void LinuxGame::OutputBuffer::print(){
    gotoxy(0,0);
    std::cout<< buffer << std::endl;
}

void LinuxGame::OutputBuffer::resize(int _size, char ch = ' '){
    buffer = "";    // 버퍼를 비웁니다.
    size = _size;   // 사이즈를 주어진 사이즈로 재설정합니다.
    for(int i = 0;i<size;i++){
        buffer+=ch;
    }
}

void LinuxGame::OutputBuffer::clear(){
    buffer = "";
    size = 0;
}

const std::string& LinuxGame::OutputBuffer::getBuffer() const{
    return this->buffer;
}

// 문자열과의 연산입니다.
LinuxGame::OutputBuffer& LinuxGame::OutputBuffer::operator+=(const std::string& rhs){
    this->buffer += rhs;
    this->size += buffer.length();
    return *this;
}

LinuxGame::OutputBuffer& LinuxGame::OutputBuffer::operator=(const std::string& rhs){
    this->buffer = rhs;
    this->size = buffer.length();
    return *this;
}

// l-value 입니다.
char& LinuxGame::OutputBuffer::operator()(const int& idx){
    return this->buffer[idx];
}

// r-value 입니다.
const char& LinuxGame::OutputBuffer::operator()(const int& idx) const{
    return this->buffer[idx];
}

#endif