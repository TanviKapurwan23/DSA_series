#include<iostream>
using namespace std;


void printfunction(int n){ 
    for(int i=0; i<n; i++){               //O(N^2)
        for(int j=0; j<n; j++){
            cout<<i<<j<<endl;
        }
    }

    for(int k=0; k<n; k++){               //O(N)
        cout<<k<<endl;
    }
}

int main(){
   printfunction(10);                  // O(N^2) + O(N)   ~  O(N^2)  drop non dominant terms
}