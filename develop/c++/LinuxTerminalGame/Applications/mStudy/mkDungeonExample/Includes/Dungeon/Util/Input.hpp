#ifndef LINUX_GAME_INPUT_HPP
#define LINUX_GAME_INPUT_HPP


#include <termios.h>    // 터미널 제어
#include <iostream>
// #include <cstdio>    // C STandarD Input and Output의 약자로, C언어의 stdio.h와 동일, iostream을 사용하는 것이 더 안정적
#include <unistd.h>     // POSIX 운영체제(유닉스 호환 운영체제) API에 대한 액세스를 제공
#include <sys/types.h>  // 각종 typedef들
#include <sys/time.h>   // 시스템 시간


#define UP 		65
#define DOWN 	66
#define RIGHT 	67
#define LEFT 	68

#define KEY_ENTER 13


namespace LinuxGame{ // namespace의 사용 이유에 대한 블로그 : https://hwan-shell.tistory.com/4
	static struct termios termiosOld, termiosNew; // 정적멤버변수는 정적멤버함수로 접근한다. 클래스 밖에서 초기화해야한다.
	static bool init = false;
	/* Initialize new terminal i/o settings : termios */
	void initTermios(int echo);

	/* Restore old terminal i/o settings */
	void resetTermios(void);

	/* Read 1 character - echo defines echo mode */
	char getch_(int echo);

	/* Read 1 character without echo */
	char getch(void);

	/* Read 1 character with echo */
	char getche(void);
	
	int kbhit (void); // 함수가 호출된 시점에서 표준입력이 있었는가 리턴
}


#endif