/*
 Pointers:
 
 Why Pointers?
 
 Initialization
 Dereferencing
 Dynamic Allocation
 
 */

// Pointer is a variable that is used for storing address of data
/**
 Used for:
 accessing the heap
 accessing the resources
 parameter passing
 */

#include<iostream>
#include<stdio.h>
#include<stdlib.h>  // for malloc
using namespace std;

struct Rectangle{
    int length;
    int breadth;
};

int main(){
//    int a=10;
//    int *p;   // Declaration of pointer
//    p = &a;
//    
//    cout<<a<<endl;
//    printf("Using pointer %d %d %d", *p, &a, p);
//    
    // pointer to an array
//    int A[5] = {2, 4, 6, 8, 10};
//    int *p;
//    p=A;
//    
//    for(int i=0; i<5; i++){
//        cout<<A[i]<<endl;
//    }
    
    int *a;
//    a = (int *)malloc(5*sizeof(int));   // inside a heap
    a = new int[5]; // array in heap  : dynamically allocating memory
    
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    a[3] = 40;
    a[4] = 50;
    
    for(int i=0; i<5; i++){
        cout<<a[i]<<endl;
    }
    
    delete [] a; // C++ deallocating memory in heap
//    free(a);  in C language  free the memory space in heap
    
    
    // EVERY POINTER TAKE SAME AMOUNT OF MEMORY
    // size of a pointer is independant of its data type
    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;
    
    cout<<sizeof(p1)<<endl;
    cout<<sizeof(p2)<<endl;
    cout<<sizeof(p3)<<endl;
    cout<<sizeof(p4)<<endl;
    cout<<sizeof(p5)<<endl;

    
    return 0;
}
