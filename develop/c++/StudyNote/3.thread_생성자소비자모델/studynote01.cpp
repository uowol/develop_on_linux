// 싱글 스레드에서의 생산자 - 소비자 

#include <iostream>

using namespace std;

class Producer{
    private:
        int id;
    public:
        int produce(){
            return id = id+1; 
        }
};

class Consumer{
    private:
    public:
        void consume(int id){ std::cout << id << endl; };
};

void test(){
    Producer producer;
    Consumer consumer;
    int result = producer.produce();
    consumer.consume(result);
}

int main(){
    test();

    return EXIT_SUCCESS;
}