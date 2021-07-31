// this example is from https://engineer-rew.tistory.com/2

/////////// Callback 예제 ///////////

#include <iostream>
using namespace std;

///////////// Server ///////////////

typedef void(*CALLBACK_FUNC)(int); // 함수 포인터 정의

CALLBACK_FUNC cbf = NULL; // 실제 콜백함수를 다루기 위한 전역 변수

void RegistCallback(CALLBACK_FUNC cb) // 콜백 등록 함수
{
	cbf = cb;
}

void StartCallback() // 콜백 테스트를 위한 함수
{
	if(cbf == NULL)
	{
		cout << "Callback Function is not Registed" << endl;
		return;
	}

	cout << "Server calls CB." << endl;
	cbf(1); // 서버 측에 등록된 콜백함수 호출 / 인자로 1을 전달.
	
}

///////////// Client ///////////////

void UserCallback(int n)
{
	if(n == 1)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}

int main()
{
	///////////// Client ///////////////	
	RegistCallback(UserCallback); // Callback 등록


	///////////// Server ///////////////
	StartCallback(); 

	return 0;
}