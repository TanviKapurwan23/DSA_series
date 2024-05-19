#include<iostream>
using namespace std;

struct Rectangle{
    int length;
    int breadth;
    char x;
};
/* 
Structures in C++ are user defined data types which are used to store group of items of non-similar data types.
*/
int main(){
//    struct Rectangle r;
    struct Rectangle r={10,5};
    
    r.length = 15;
    r.breadth = 7;
    
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;
    
    printf("Area of rectangle is %d", r.length*r.breadth);
    printf("%lu",sizeof(r));
    
    return 0;
}


/*
 
 Defining Structure
 Size of a Structure
 Declaring a Structure
 Accessing Members
 */
