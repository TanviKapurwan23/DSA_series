#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;



int birthdayCakeCandles(vector<int> candles){
   int max_height = *max_element(candles.begin(), candles.end());

   int count = 0;
   for(int height : candles){
      if(height == max_height){
        count++;
      }
   }
   return count;
}

int main(){
    int n;
   cout<<"Enter the number of candles"<<endl;
   cin>>n;

   vector<int> candles(n);
   cout<<"Enter the heights of the candles"<<endl;
   for(int i=0; i<n; i++){
      cin>>candles[i];
   }

   int results = birthdayCakeCandles(candles);
   cout<<"The number of tallest cake candles are "<<results<<endl;

   return 0;

}

