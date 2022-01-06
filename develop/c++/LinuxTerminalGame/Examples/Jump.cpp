#include <thread>
#include <iostream>
#include <mutex>
#include </home/alllhvhla/git/develop_on_linux/develop/c++/LinuxTerminalGame/Technique/TerminalIO/input.cpp>

#define HEIGHT  10
#define WIDTH   10

int map[HEIGHT][WIDTH] = {0, };
int isrun = false;

class Point{
private:
    int x = 0;
    int y = 0;
    int direction = 1;
public:
    Point(int x, int y, int direction) {
        this->x = x;
        this->y = y;
        this->direction = direction;
    }
    void moveLeft(){
        this->x--;
    }
    void moveRight(){
        this->x++;
    }
    void moveUp(){
        this->y--;
    }
    void moveDown(){
        this->y++;
    }
    int getX(){return this->x;}
    int getY(){return this->y;}
    int getDirection(){return this->direction;}
    void setDirection(int direction){this->direction = direction;}
};


void show(){
    for(int i=0; i<HEIGHT; i++){
        for(int j=0; j<WIDTH; j++){
            printf("%d%d", map[i][j], map[i][j]);
        }
        printf("\n");
    }
}

bool isconflict(Point p){
    if(map[p.getY()][p.getX()] == 2) return true;    // 2 is wall
    if(p.getX() < 0 || p.getX() >= WIDTH || p.getY() < 0 || p.getY() >= HEIGHT) return true;
    return false; 
}


using namespace std;

int main(){
    Point p = Point(WIDTH/2, HEIGHT/2, 3);
    mutex mtx;

    auto move_func = [&p, &mtx](){
        while(true){
            mtx.lock();
            if(!isrun) return;
            mtx.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(100));         

            Point nextP = Point(p.getX(), p.getY(), p.getDirection());
            if(nextP.getDirection() == 0){
                nextP.moveUp();
            }else if(nextP.getDirection() == 1){
                nextP.moveDown();
            }else if(nextP.getDirection() == 2){
                nextP.moveLeft();
            }else if(nextP.getDirection() == 3){
                nextP.moveRight();
            }
            if(isconflict(nextP)) {
                if(nextP.getDirection() == 2) {
                    nextP.setDirection(3);
                    nextP.moveRight();
                }
                else if(nextP.getDirection() == 3) {
                    nextP.setDirection(2);
                    nextP.moveLeft();
                }
            }
            map[p.getY()][p.getX()] = 0;
            p = nextP;
            map[p.getY()][p.getX()] = 1;
        }
    };
    
    auto show_func = [&mtx](){
        while(true){
            mtx.lock();
            if(!isrun) return;
            mtx.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(100));

            system("clear");
            show();
        }
    };

    auto input_func = [&p, &mtx](){
        while(true){
			std::this_thread::sleep_for(std::chrono::milliseconds(100));

            mtx.lock();
            if(!isrun) return;
            mtx.unlock();

            int ipt = getch();
            if(ipt == 10) isrun = false;
            if(ipt == 32){
                map[p.getY()][p.getX()] = 0;
                p.moveUp();
                map[p.getY()][p.getX()] = 1;
    			std::this_thread::sleep_for(std::chrono::milliseconds(500));
                map[p.getY()][p.getX()] = 0;
                p.moveDown();
                map[p.getY()][p.getX()] = 1;
            }
        }
    };

    isrun = true;

    std::thread t1 = std::thread(show_func);
	std::thread t2 = std::thread(move_func);
	std::thread t3 = std::thread(input_func);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}