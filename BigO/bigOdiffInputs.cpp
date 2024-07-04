#include<iostream>

using namespace std;

int main()
{  
    return 0;
}
void printItems(int a, int b)
{
    for(int i=0; i<a; i++){
        cout<<i<<endl;
    }

    for(int j=0; j<b; j++){
        cout<<j<<endl;
    }
}

// O(a)+O(b)  O(a+b)

void newPrintItems(int a, int b){
    for(int i=0; i<a; i++){
        for(int j=0; j<b; j++){
            cout<<i<<j<<endl;
        }
    }
}

// O(a*b)