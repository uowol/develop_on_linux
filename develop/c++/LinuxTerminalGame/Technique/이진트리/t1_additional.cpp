#include <iostream>

using namespace std;

int number = 15;

typedef struct node* treePointer; // node 구조체의 포인터를 treePointer로 설정
typedef struct node{ // node구조체의 이름을 node로 설정
    int data;
    int x;
    int y;
    int width;
    int height;
    treePointer left, right;
} node;

void preorder(treePointer ptr){ // 전위 순회
    if(ptr){
        cout << ptr->data << ": " << ptr->x << ", " << ptr->y << endl;
        cout << ptr->width << ", " << ptr->height << endl;
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(treePointer ptr){ // 중위 순회
    if(ptr){
        inorder(ptr->left);
        cout << ptr->x << ", " << ptr->y << endl;
        inorder(ptr->right);
    }
}

void postorder(treePointer ptr){ // 후위 순회
    if(ptr){
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->x << ", " << ptr->y << endl;
    }
}

int main(){
    // srand()

    node nodes[number+1];
    int iWidth = 400;
    int iHeight = 300;
    for(int i=1; i<=number; i++){
        nodes[i].data = i;
        nodes[i].x = 0;
        nodes[i].y = 0;
        nodes[i].width = 0;
        nodes[i].height = 0;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    for(int i=1; i<=number; i++){
        if (i%2 == 0)
            nodes[i/2].left = &nodes[i];
        else
            nodes[i/2].right = &nodes[i];
    }
    nodes[1].width = iWidth;
    nodes[1].height = iHeight;
    for(int i=1; i<=number; i++){
        int iMaxWidth = nodes[i].width;
        int iMaxHeight = nodes[i].height;

        int r = rand() & 1; // 가로분할 세로분할 비율을 1:1로 랜덤하게.
        // cout << r << endl; 
        int _width = iMaxWidth * (rand()%41+30)/100;
        int _height = iMaxHeight * (rand()%41+30)/100;
        if (r) _width = iMaxWidth;
        else _height = iMaxHeight;
        // cout << "log" << endl;
        // cout << _width << endl;
        // cout << _height << endl;
    
        if(nodes[i].left){
            nodes[i].left->width = _width;
            nodes[i].left->height = _height;
            nodes[i].left->x = nodes[i].x;
            nodes[i].left->y = nodes[i].y;
        }
        if(nodes[i].right){
            nodes[i].right->width = r ? nodes[i].width : nodes[i].width - _width;
            nodes[i].right->height = r ? nodes[i].height - _height : _height;
            nodes[i].right->x = r ? nodes[i].x : nodes[i].x + nodes[i].left->width;
            nodes[i].right->y = r ? nodes[i].y + nodes[i].left->height : nodes[i].y;
        }
        
    }
    preorder(&nodes[1]);
    return 0;
}

