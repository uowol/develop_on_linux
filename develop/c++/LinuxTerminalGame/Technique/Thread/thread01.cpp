#include <iostream>
#include <thread>

using namespace std;

int main(){
    cout << thread::hardware_concurrency() << endl;
    cout << this_thread::get_id() << endl;

    thread t1 = thread([] {     // 람다 함수
        cout << this_thread::get_id() << endl;
    });

    t1.join();  // 끝날때까지 대기
}