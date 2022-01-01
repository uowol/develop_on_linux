#ifndef OUTPUT_HPP

#include <iostream>
#include <string>   // 문자열 관련 라이브러리
#include <vector>   // 
#include <sstream>  // stringstream은 문자열로부터 입력을 받음

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
			const char& operator()(const int& idx) const; // right value
	};
}

#endif