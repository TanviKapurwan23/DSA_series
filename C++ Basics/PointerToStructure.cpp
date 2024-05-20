#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
    
    struct Rectangle r = {10, 5};   // variable
    cout<<"Variable to a Structure"<<endl;
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    
    cout<<"Pointer to a Structure"<<endl;
    Rectangle *p=&r;       //pointer
    cout<<p->length<<endl;
    cout<<p->breadth<<endl;
    
    // DYNAMIC ALLOCATION  OF RECTANGLE STRUCTURE
    
    struct Rectangle *a;  // pointer created in stack
//    a = (struct Rectangle *)malloc(sizeof(struct Rectangle));  // In Heap
    a = new Rectangle;  // C++
    
    a->length=15;
    a->breadth=7;
    
    cout<<"DYNAMIC ALLOCATION  OF RECTANGLE STRUCTURE"<<endl;
    cout<<a->length<<endl;
    cout<<a->breadth<<endl;
    
    return 0;
}


/*
OUTPUT:

Variable to a Structure
10
5
Pointer to a Structure
10
5
DYNAMIC ALLOCATION  OF RECTANGLE STRUCTURE
15
7
*/
