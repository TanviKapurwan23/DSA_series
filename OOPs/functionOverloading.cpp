#include<iostream>
using namespace std;

class overloading{
    public:
    void fun(){
        cout<<"I am function with no arguments"<<endl;
    }

    void fun(int x){
        cout<<"I am function with int arguments"<<endl;
    }

    void fun(double x){
        cout<<"I am a function with double arguments"<<endl;
    }
};


int main(){
    overloading obj;
    obj.fun();
    obj.fun(2);
    obj.fun(2.4);

    return 0;
}

/*
OUTPUT:

I am function with no arguments
I am function with int arguments
I am a function with double arguments
*/