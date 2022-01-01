// this example is from https://nowonbun.tistory.com/732

#include <iostream>
#include <thread>

using namespace std;
 
// 함수
void thread_function(int count)
{
  // 파라미터로 받은 count 수치만큼 반복문을 실행한다.
  for (int i = 0; i < count; i++)
  {
    // 콘솔 출력
    cout << "i - " << i << endl;
    // 쓰레드의 비활성 상태 대기, 10ms간..
    this_thread::sleep_for(chrono::milliseconds(10));
  }
}

// 실행 함수
int main()
{
  // thraed 생성, thread_function함수를 호출하고 파라미터는 10을 넘긴다.
  thread _t1(thread_function, 10);
  // thraed 생성
  thread _t2(thread_function, 10);
  // 콘솔 출력
  cout << "main process " << endl;
 
  // thread가 종료될 때까지 대기
  _t1.join();
  _t2.join();
  return 0;
}
