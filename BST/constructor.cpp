#include<iostream>
using namespace std;

class Node{
    public:
    int value;
    Node* left;
    Node* right;

    Node(int value){
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree{
    public:
    Node* root;

    BinarySearchTree(int value){
        root = nullptr;
    }
};

int main(){
    BinarySearchTree* myBST = new BinarySearchTree(1);
    cout<<"Root : "<<myBST->root;
    return 0;
}