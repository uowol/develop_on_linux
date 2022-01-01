#include <Utils/Input.hpp>
#include <Utils/Output.hpp>
#include <Map.hpp>
#include <Snake.hpp>

using namespace LinuxGame;
using namespace std;

void show(OutputBuffer outb, Snake snake){
    outb.print();
    cout<<snake.qBody.front().first<< ", " << snake.qBody.front().second << endl;
    
}

int main(){
    Snake snake = Snake();
    OutputBuffer outputBuffer = OutputBuffer();
    Map map = Map(10, 10);
    outputBuffer.resize((map.getWidth()+1)*map.getHeight(), getTile(TILE_WALL));

    for(int i=0; i<map.getHeight(); i++){
        outputBuffer((map.getWidth()+1)*i + map.getWidth()) = '\n';
    }
    for(int i=1; i<map.getHeight()-1; i++){
        for(int j=1; j<map.getWidth()-1; j++){
            outputBuffer((map.getWidth()+1)*i + j) = getTile(TILE_NONE);
        }
    }

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
        show(outputBuffer, snake);
    }

    terminalTermios();
    return 1;
}