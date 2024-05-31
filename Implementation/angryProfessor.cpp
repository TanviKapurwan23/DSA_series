#include<iostream>
using namespace std;

string angryProfessor(int k, vector<int> a){
    int onTimeCount  = 0;
    // Count the number of students who arrive on time (arrival time <= 0)

    for(int i=0; i<a.size(); i++){
        if(a[i] <= 0){
            onTimeCount++;
        }
    }
    // Check if the class is canceled (onTimeCount < k)

    if(onTimeCount < k){
        return "YES";
    } else{
        return "NO";
    }
}

int main(){
   int k = 3;
   vector<int> arrivalTimes = {-1, 3 , 4, 2};

   string result  = angryProfessor(k, arrivalTimes);
   cout<<result<<endl;
  
}