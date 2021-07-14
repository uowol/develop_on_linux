#include <iostream>

using namespace std;

int number = 15;

typedef struct node* treePointer;
typedef struct node{
    int data;
    treePointer left, right;
} node;

void preorder(treePointer ptr){ // 전위 순회
    if(ptr){
        cout << ptr->data << ' ';
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void inorder(treePointer ptr){ // 중위 순회
    if(ptr){
        inorder(ptr->left);
        cout << ptr->data << ' ';
        inorder(ptr->right);
    }
}

void postorder(treePointer ptr){ // 후위 순회
    if(ptr){
        postorder(ptr->left);
        postorder(ptr->right);
        cout << ptr->data << ' ';
    }
}

int main(){
    node nodes[number+1];
    for(int i=1; i<=number; i++){
        nodes[i].data = i;
        nodes[i].left = NULL;
        nodes[i].right = NULL;
    }
    for(int i=1; i<=number; i++){
        if (i%2 == 0)
            nodes[i/2].left = &nodes[i];
        else
            nodes[i/2].right = &nodes[i];
    }
    preorder(&nodes[1]);
    cout << nodes[1].left->data << endl;
    return 0;
}

