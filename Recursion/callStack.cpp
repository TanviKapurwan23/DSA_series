#include<iostream>

using namespace std;

// Call Stack:

void funcThree(){
    cout<<"Three"<<endl;
}


void funcTwo(){
    funcThree();
    cout<<"Two"<<endl;
}


void funcOne(){
    funcTwo();
    cout<<"One"<<endl;
}



int main(){
    funcOne();

    return 0;
}