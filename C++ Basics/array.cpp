#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    
    int n;
  
    cout<<"Enter the size"<<endl;
    cin>>n;
    int A[n];     // variable size array cannot be initialized
    A[0] = 2;
    
    
    int B[10]={2,4,6,8,10,12,14};
//    A[0]=1;
//    A[1]=2;
//    A[2]=3;
    
//    for(int i=0; i<10; i++){
//        cout<<A[i]<<endl;
//    }
//    
    for(int x:A){      // for each loop
        cout<<x<<endl;
    }
    
//    cout<<sizeof(A)<<endl;
//    cout<<A[9]<<endl;
//    printf("%d\n", A[2]);
    return 0 ;
}
