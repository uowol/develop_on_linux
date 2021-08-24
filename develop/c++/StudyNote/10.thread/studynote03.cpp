#include <iostream>
#include <thread>
#include <mutex>    // thread 동기화를 위한 mutex

class Node{
    private:
        // 변수 선언 
        int data = 0;
    public:
        // 가산을 위한 함수
        void addData(int data){
            this->data += data;
        }
        // data Getter
        int getData(){
            return this->data;
        }
};

// lock을 위한 mutex
std::mutex _mutex;

void t_function(Node& node){
    // 0부터 1000까지 가산 => 500500
    for(int i=0; i<=10; i++){
        std::cout << "Data - " << node.getData() << "\n";
        
        // _mutex가 다른 스레드에서 lock이 걸려있으면 여기서 대기
        // 만약 걸려 있지 않다면 lock을 걸고 다음 스텝으로 이동
        _mutex.lock();

        node.addData(i);

        _mutex.unlock();
    }
}

int main(){
    Node node;
    std::thread _t1(t_function, std::ref(node));    // std::ref를 사용하면 참조 또한 rvalue처럼 보낼 수 있다.
    std::thread _t2(t_function, std::ref(node));
    std::cout << "main process" << "\n";

    _t1.join();
    _t2.join();

    std::cout << "Sum - " << node.getData() << "\n";

    return 0;
}