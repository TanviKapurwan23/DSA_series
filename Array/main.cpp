/*
 WHAT IS RECURSION
 EXAMPLE OF RECURSION
 TRACING RECURSION
 STACK USED IN RECURSION
 TIME COMPLEXITY
 RECURRENCE RELATION
 */
/*
 what is an array
 declaring and initializing
 accessing array
 */

#include<iostream>
#include<stdlib.h>
using namespace std;

int main(){
//    int A[5];
//    int B[5] = {1, 2, 3, 4, 5};
//    int C[10] = {2, 4, 6};
//    int D[5] = {0};
//    int E[] = {11, 22, 33, 44, 55};
//    for(int i=0; i<5; i++){
//        printf("%u \n", &A[i]);
//    }
    
    int B[10]={2,4,6,8,10};  // array in stack
    int *p;
    
    p = (int *)malloc(sizeof(int));  // array in heap using pointer
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    
    for(int i=0; i<5; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
    for(int i=0; i<5; i++){
        printf("%d ", p[i]);
    }
    
    
    return 0 ;
}
