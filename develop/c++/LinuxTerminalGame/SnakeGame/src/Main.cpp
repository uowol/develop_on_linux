#include <Utils/Input.hpp>
#include <Snake.hpp>

using namespace LinuxGame;
using namespace std;

void show(Snake snake){
    cout<<snake.qBody.front().first<< ", " << snake.qBody.front().second << endl;
}

int main(){
    Snake snake = Snake();
    snake.generate(5, 5, 3, 1);
    while(1){
        int ipt = int(getch());
        if(ipt == 10) break;
        if(ipt == UP){
            snake.changeDirection(1);
        }
        if(ipt == DOWN){
            snake.changeDirection(2);
        }
        if(ipt == RIGHT){
            snake.changeDirection(3);
        }
        if(ipt == LEFT){
            snake.changeDirection(4);
        }
        snake.move();
        show(snake);
    }

    terminalTermios();
    return 1;
}