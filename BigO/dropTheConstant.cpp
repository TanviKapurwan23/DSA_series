#include<iostream>
using namespace std;

void printItems(int n){
    for(int i=0; i<n; i++){
        cout<<i<<endl;  // O(N)
    }

    for(int j=0; j<n; j++){
        cout<<j<<endl;   // O(N)
    }
}

 


int main(){
    printItems(10);  // n+n (drop the constants)  O(N)


    return 0;
}