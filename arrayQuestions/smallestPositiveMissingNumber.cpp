#include"bits/stdc++.h"
using namespace std;

int main(){
  int n;
  cin>>n;
  
  int arr[n];
  for(int i=0; i<n; i++){
      cin>>arr[i];
  }
  const int N = 1e6 + 2;
  bool check[N];
  for(int i=0; i<N; i++){. //initialize check array as false
      check[i] = false;
  }
  
  for(int i=0; i<n; i++){.   
      if(arr[i]>=0){   // if non-negative
          check[arr[i]] = 1;   // mark it as true
      }
  }
  int ans = -1;            
  for(int i=1; i<N; i++){
      if(check[i] == false){    // if false/missing
          ans = i;               // store it 
          break;
      }
  }
  cout<<ans<<endl;
  
  return 0;
}