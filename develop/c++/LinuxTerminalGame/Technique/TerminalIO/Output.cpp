#ifndef OUTPUT_CPP

#include <iostream>
#include <string>
#include <vector>

// 사실 함수가 아닌 명령어를 통한 작동입니다. \033[L;Cf 가 Lows,Columns으로 좌표를 이동시키는 명령어입니다. 
void gotoxy(const int& x, const int& y){ printf("%c[%d;%df",0x1B, y, x); }

class OutputBuffer{
    private:
        int size;
        std::string buffer;
    public:
        OutputBuffer(){}
        OutputBuffer(std::string s){
            buffer = s;
            size = s.length();
        }
        OutputBuffer(int _size, char ch='\0'){
            resize(_size, ch);
        }
        void print(){
            gotoxy(0, 0);
            std::cout << buffer << std::endl;
        }
        void resize(int _size, char ch = ' '){
            buffer = "";
            size = _size;
            for(int i=0; i<size; i++) buffer += ch;
        }
        void clear(){
            buffer = "";
            size = 0;
        }

        const std::string& getBuffer() const{
            return buffer;
        }	

        // 문자열과 더할수 있게 처리해 줍니다.
        OutputBuffer& operator+=(const std::string& rhs){
            buffer += rhs;
            size += rhs.length();
            return *this;
        }
        OutputBuffer& operator=(const std::string& rhs){
            buffer = rhs;
            size = rhs.length();
            return *this;
        }

        // index로 buffer접근 할 수 있습니다.
        char& operator()(const int& idx){
            return buffer[idx];
        } // l-value
        const char& operator()(const int& idx) const{
            return buffer[idx];
        } // r-value
};

#endif

// 예시

using namespace std;

int main(){
    srand(time(nullptr));
    for(int i=0; i<10; i++){
        int x = rand()%20;
        int y = rand()%20;
        gotoxy(x, y);
        cout << "*";
    }
    return 0;   
}