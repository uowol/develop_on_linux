#ifndef INPUT_CPP
#define INPUT_CPP

#include <iostream>
#include <queue>

namespace LinuxGame{
    
    class Snake{
        private:
            int iLength;
            int fSpeed;
            int iDirection;
            bool isAlive;
        public:
            std::queue<std::pair<int,int>> qBody;
            void generate(int x, int y, int direction, float speed);
            void die();
            void changeDirection(int d);
            void move();
    };

    int check(int x, int y);
}

#endif