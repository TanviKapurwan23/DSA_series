#include<iostream>

using namespace std;

int main(){
    int* num1 = new int(11);
    int* num2 = num1;

    cout<<"Num1 = "<<*num1<<endl;
    cout<<"Num2 = "<<*num2<<endl;

    return 0;
}