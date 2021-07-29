#ifndef LINUX_GAME_INPUT_IMPL_CPP
#define LINUX_GAME_INPUT_IMPL_CPP

#include <Dungeon/Util/Input.hpp>

namespace LinuxGame{
	/* Initialize new terminal i/o settings */
	void initTermios(int echo) 
	{
		if(init) return; // is inited
		init = true;
		tcgetattr(STDIN_FILENO, &termiosOld); /* grab old terminal i/o settings */ // 표준입력 파일의 기술자: 0
		termiosNew = termiosOld; /* make new settings same as old settings */ // (v)복사한다? 참조한다?
		termiosNew.c_lflag &= ~ICANON; /* disable buffered i/o */ // local flags, 캐노니컬(정규) 입력모드(줄로 입력받음)를 사용하지 않는다.
		termiosNew.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
		tcsetattr(STDIN_FILENO, TCSANOW, &termiosNew); /* use these new terminal i/o settings now */ // 속성을 바로 반영한다.
	}

	/* Restore old terminal i/o settings */
	void resetTermios(void) 
	{
		tcsetattr(0, TCSANOW, &termiosOld);
	}

	/* Read 1 character - echo defines echo mode */
	char getch_(int echo) 
	{
		char ch=0;
		initTermios(echo);
		// if(!kbhit()) return ch;
		ch = std::cin.get();
		while(!(ch == UP || ch==DOWN || ch==LEFT || ch==RIGHT)){
			ch = getchar();
		}
		// resetTermios();
		return ch;
	}

	/* Read 1 character without echo */
	char getch(void) 
	{
		char ch = getch_(0);
		return ch;
	}

	/* Read 1 character with echo */
	char getche(void) 
	{
		char ch = getch_(1);
		return ch;
	}

	int kbhit (void)
	{
		struct timeval tv;
		fd_set rdfs; // File Descriptor (이하 FD) 를 저장하는 구조체

		tv.tv_sec = 0;  // seconds
		tv.tv_usec = 0; // micro seconds

		FD_ZERO(&rdfs); // 초기화하여 쓰레기값을 없애준다.
		FD_SET (STDIN_FILENO, &rdfs); // FD_SET(2, &rdfs) -> 010000000 ~~, 표준입력의 파일 기술자를 입력한다.

		select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv); // STDIN_FILENO+1 미만값만 체크하며 이벤트가 발생했을 경우 깨어난다.
		// 저장된 FD 중 이벤트가 발생하면 해당 이벤트만 1로 남기고 나머지는 0으로 세팅한다.
		// 타이머가 0으로 설정 = 이벤트 발생 즉시 리턴
		return FD_ISSET(STDIN_FILENO, &rdfs);

	}

}




#endif