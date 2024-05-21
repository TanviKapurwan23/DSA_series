#include<iostream>
#include<stdlib.h>

using namespace std;
int main(){
    int *q, *p;
    int i;
    
    p = (int *)malloc(5*sizeof(int));  // size 5
    
    p[0] = 1;
    p[1] = 2;
    p[2] = 3;
    p[3] = 4;
    p[4] = 5;
    
    q = (int *)malloc(10*sizeof(int)); // size 10
    
    
    for(int i=0; i<5; i++){
        q[i] = p[i];
    }
    
    free(p);
    p=q;
    q=NULL;
    
    for(int i=0; i<5; i++){
        printf("%d \n", p[i]);
    }
    
    
    return 0;
}
