#include<iostream>

using namespace std;

class Node{
    public:
    string key;
    int value;
    Node* next;

    Node(string key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashTable{
   private:
   static const int SIZE = 7;
   Node* dataMap[SIZE];

   public:
   void printTable(){
    for(int i=0; i<SIZE; i++){
         cout<<i<<":"<<endl;
         if(dataMap[i]){
            Node* temp = dataMap[i];
            while(temp){
                cout<<" {"<<temp->key<<" , "<<temp->value<<"}"<<endl;
                temp = temp->next;
            }
         }
    }
   }
};

int main(){
    HashTable* myHashtable = new HashTable();
    myHashtable->printTable();

    return 0;
}