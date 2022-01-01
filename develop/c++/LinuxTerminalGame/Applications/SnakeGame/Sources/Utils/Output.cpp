#ifndef OUTPUT_HPP

#include <Utils/Output.hpp>

namespace LinuxGame{
    
    // 출력 함수가 아닌 명령어를 통한 작동
    void gotoxy(const int &x, const int & y){
        printf("%c[%d;%df", 0x1B, y, x);    // 27: ESC, escape == \e, => \e[<L>;<C>f 
    }

    OutputBuffer::OutputBuffer(){}
    OutputBuffer::OutputBuffer(std::string s){
        this->buffer = s;
        this->size = s.length();
    }
    OutputBuffer::OutputBuffer(int _size, char ch = '\0'){
        resize(_size, ch);
    }

    void OutputBuffer::print(){
        gotoxy(0,0);
        std::cout << this->buffer << std::endl;
    }
    void OutputBuffer::resize(int _size, char ch = '\0'){
        this->buffer = "";    // 버퍼를 비웁니다.
        this->size = _size;   // 사이즈를 주어진 사이즈로 재설정합니다.
        for(int i = 0;i<this->size;i++){
            this->buffer+=ch;
        }
    }
    void OutputBuffer::clear(){
        this->buffer = "";
        this->size = 0;
    }
    const std::string& OutputBuffer::getBuffer() const{
        return this->buffer;
    }

    OutputBuffer& OutputBuffer::operator+=(const std::string& rhs){
        this->buffer += rhs;
        this->size += this->buffer.length();
        return *this;
    }
    OutputBuffer& OutputBuffer::operator=(const std::string& rhs){
        this->buffer = rhs;
        this->size = this->buffer.length();
        return *this;
    }

    char& OutputBuffer::operator()(const int& idx){
        return this->buffer[idx];
    }
    const char& OutputBuffer::operator()(const int& idx) const{
        return this->buffer[idx];
    }
}

#endif