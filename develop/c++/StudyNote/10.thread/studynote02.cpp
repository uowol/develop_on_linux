#include <iostream>
#include <thread>

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

void t_function(Node* node){
    // 0부터 1000까지 가산 => 500500
    for(int i=0; i<=10; i++){
        std::cout << "Data - " << node->getData() << "\n";
        node->addData(i);
    }
}

int main(){
    Node node;
    std::thread _t1(t_function, &node);
    std::thread _t2(t_function, &node);
    std::cout << "main process" << "\n";

    _t1.join();
    _t2.join();

    std::cout << "Sum - " << node.getData() << "\n";

    return 0;
}