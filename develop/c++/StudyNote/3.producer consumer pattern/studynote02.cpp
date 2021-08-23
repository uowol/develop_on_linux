// Thread1 -> 생산자, Thread2 -> 소비자

// now -> 생산자는 메시지 블록에 메시지를 보내고 소비자는 해당 블록에서 메시지를 읽습니다.

// 첫 번째 시나리오 - 소비자는 생산자가 보내는 각 메시지를 받아야 합니다.
// 두 번째 시나리오 - 소비자는 주기적으로 데이터를 폴하므로 각 메시지를 받을 필요가 없습니다.

#include <iostream>
#include <thread>

class Table{
    private:
        std::string* buffer;
        int tail;
        int head;
        int count;
        bool isusing;
    public:
        Table(int count){
            this->buffer = new std::string[count];
            this->head = 0;
            this->tail = 0;
            this->count = 0;
            this->isusing = false;
        };
        void notifyAll(){ this->isusing = false; }
        void put(std::string message){
            while(isusing || count >= (int)sizeof(buffer)){
                // wait
            }
            this->isusing = true;
            this->buffer[tail] = message;
            this->tail = (tail+1) % (int)sizeof(buffer);
            count++;
            notifyAll();
        }
        std::string take(){
            while(isusing || count <= 0){
                // wait
            }
            this->isusing = true;
            std::string message = buffer[head];
            this->head = (head+1) % (int)sizeof(buffer);
            count--;
            notifyAll();
            return message;
        }
};

void Producer_f(Table* table){
    int id = 1;
    while(1){
        table->put("id" + id);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}
void Consumer_f(Table* table){
    while(1){
        std::cout << table->take() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

int main(){
    Table table = Table(100);
    std::thread producer_t(Producer_f, &table);
    std::thread consumer_t(Consumer_f, &table);
    producer_t.detach();
    consumer_t.detach();
}