/*
create a newNode
if root = nullptr then root = newNode
temp = root

while loop
if newNode == temp return false
if < left else > right
if nullptr insert newNode else move to next
*/

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

    BinarySearchTree(){
        root = nullptr;
    }

    bool insert(int value){
        Node* newNode = new Node(value);
        if(root == nullptr){   // if tree is empty
            root = newNode;
            return true;
        }
        Node* temp = root;
        while(true){
            if(newNode->value == temp->value) return false;
            if(newNode->value < temp->value){
                if(temp->left == nullptr){
                    temp->left = newNode;
                    return true;
                } temp = temp->left;
            } else{
                if(temp->right == nullptr){
                    temp->right = newNode;
                    return true;
                } temp = temp->right;
            }
        }
    }
};

int main(){
    BinarySearchTree* myBST = new BinarySearchTree();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    cout<<myBST->root->left->right->value<<endl;


    return 0;
}