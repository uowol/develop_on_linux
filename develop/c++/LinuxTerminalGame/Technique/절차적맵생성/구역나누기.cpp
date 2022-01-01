#include <iostream>

using namespace std;

const int SIZE = (1<<4)-1;
#define WIDTH 400
#define HEIGHT 300

// typedef struct EDGE* edgePointer;
typedef struct EDGE{
    int x1, y1;
    int x2, y2;
} edge;

void setEdge(edge&, int, int, int, int);

int main(){
    edge edges[SIZE+1];
    // cout << SIZE << endl;
    setEdge(edges[1], 0, 0, WIDTH, HEIGHT);
    for(int i=2; i<=SIZE; i++){
        
    }

}

void setEdge(edge& e, int x1, int y1, int x2, int y2){
    e.x1 = x1;
    e.x2 = x2;
    e.y1 = y1;
    e.y2 = y2;
}