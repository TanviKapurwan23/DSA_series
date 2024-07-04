#include<iostream>
using namespace std;

void printItems(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<i<<j<<endl;
        }
    }
}

void newPrintItems(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<<i<<j<<k<<endl;
            }
        }
    }
}


int main(){

    // printItems(10);  //n*n  O(N^2)
    newPrintItems(10);  //n*n*n  O(N^2)


    return 0;
}