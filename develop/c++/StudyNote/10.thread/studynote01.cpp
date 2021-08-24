#include <iostream>
#include <thread>

void t_count(int count){
    for(int i=1; i<=count; i++){ // 1 ~ count 까지 출력 
        // 콘솔 출력 
        std::cout << " i / count = " << i << " / " << count << "\n";
        // 쓰레드의 비활성 상태 대기, 10ms간
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

int main(){
    // thread 생성, t_count 함수를 호출하고 파라미터는 10을 넘긴다.
    std::thread t1(t_count, 10);
    // thread 생성, 위 함수가 종료될 때 까지 대기하지 않고 실행한다.
    std::thread t2(t_count, 10);
    // 콘솔 출력
    std::cout << "main process" << "\n";

    // 다른 thread가 종료될 때 까지 대기
    t1.join();
    t2.join();
    return 0;
}