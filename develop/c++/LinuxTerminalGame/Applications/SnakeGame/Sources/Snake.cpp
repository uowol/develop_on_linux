#ifndef SNAKE_CPP
#define SNAKE_CPP

#include <Snake.hpp>
#include <Map.hpp>

namespace LinuxGame{
    void Snake::generate(int x, int y, int direction, float speed){
        qBody.push(std::make_pair(x, y));
        iDirection = direction;
        fSpeed = speed;
        isAlive = true;
    };
    void Snake::die(){
        isAlive = false;
    };
    void Snake::changeDirection(int d){
        this->iDirection = d;
    };
    void Snake::move(){
        if(!isAlive) return;
        
        std::pair<int, int> head = qBody.back();
        int x = head.first;
        int y = head.second;

        if(iDirection == 1){ // UP
            if(!check(x, y-1)) die();
            qBody.pop();
            qBody.push(std::make_pair(x, y-1));
        }
        if(iDirection == 2){ // DOWN
            if(!check(x, y+1)) die();
            qBody.pop();
            qBody.push(std::make_pair(x, y+1));
        }
        if(iDirection == 3){ // RIGHT
            if(!check(x+1, y)) die();
            qBody.pop();
            qBody.push(std::make_pair(x+1, y));
        }
        if(iDirection == 4){ // LEFT
            if(!check(x-1, y)) die();
            qBody.pop();
            qBody.push(std::make_pair(x-1, y));
        }
    };

    int check(int x, int y){
        return true;
    };
}

#endif