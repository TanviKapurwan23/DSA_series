#include<iostream>
#include<string>

using namespace std;

struct node{
    char data;
    node* left;
    node* right;
    node(char x) : data(x), left(NULL), right(NULL){}
};

void decode_huff(node* root, string s){
    node* current = root;
    for(char bit : s){
        if(bit == '0'){
            current = current->left;
        } else if ( bit == '1'){
            current = current->right;
        }

        if(current->left == NULL && current->right == NULL){
            cout<<current->data;
            current = root;
        }
    }
}

int main(){
    node* root = new node('\0');
    root->left = new node('\0');
    root->right = new node('A');
    root->left->left = new node('B');
    root->left->right = new node('C');

    string s = "1001011";

    decode_huff(root, s);
    cout<<endl;

    return 0;
    


}