#include<iostream>
#include<string>

using namespace std;

string catAndMouse(int x, int y, int z){
  int distCatA = abs(z - x);
  int distCatB = abs(z - y);

  if(distCatA < distCatB){
    return "Cat A";
  } else if(distCatB < distCatA){
    return "CatB";
  } else{
    return "Mouse C";
  }
}


int main(){
    int x = 1;
    int y = 3;
    int z = 2;

    string result  =  catAndMouse(x, y, z);
    cout<<result <<endl;

    return 0;
}