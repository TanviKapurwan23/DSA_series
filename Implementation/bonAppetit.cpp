#include<iostream>
using namespace std;

void bonAppetit(vector<int> bill, int k, int b){
   int totalCost = 0;

   // total cost of share items

   for(int i=0; i<bill.size(); i++){
      if(i != k){
        totalCost += bill[i];
      }
   }

   int annaShare =  totalCost/2;

   if(b == annaShare){
    cout<<"Bon Appetit"<<endl;
   } else{
    cout<<b - annaShare<<endl;
   }
}

int main(){

    vector<int> bill = {3, 10, 2, 9};
    int k = 1;  // index 1 (10)
    int b = 12; // Brian charges anna 12

    bonAppetit(bill, k, b);

    return 0;
}