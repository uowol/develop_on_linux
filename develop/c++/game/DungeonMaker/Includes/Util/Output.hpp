#ifndef LINUX_GAME_OUTPUT_HPP
#define LINUX_GAME_OUTPUT_HPP


#include <iostream>
#include <string>
#include <vector>
#include <sstream>  
// string stream: 문자열과 스트림의 기능이 동시에 존재하는 것, 스트림: 입출력을 추상화하여 나타내는 것
/*
cin(istream)은 사용자로부터 입력받았고 ifstream은 파일로부터 입력받았다면
이 stringstream은 문자열로부터 입력을 받는 것입니다!!

[출처] [C++ 강좌] 090 - 스트림과 파일 입출력 (6) - stringstream, str(): https://blog.naver.com/kks227/220245263973
*/

namespace LinuxGame{
	void gotoxy(const int &x, const int & y);

	class OutputBuffer{
		private:
			int size;
			std::string buffer;

		public:
			OutputBuffer();
			OutputBuffer(std::string s);
			OutputBuffer(int _size, char ch);

			void print();
			void resize(int size, char ch);
			void clear();
			const std::string& getBuffer() const;
		
			OutputBuffer& operator+=(const std::string& rhs);
			OutputBuffer& operator=(const std::string& rhs);

			char& operator()(const int& idx);
			const char& operator()(const int& idx) const;
		
	};

}


#endif