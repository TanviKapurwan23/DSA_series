#include<iostream>
using namespace std;

int main(){
    return 0;
}
class Cookie{
  private:
     string color;
  public: 
     Cookie(string color){
        this->color = color;
     }
     string getColor(){
        return color;
     }
     void setColor(){
        this->color = color;
     }
};

Cookie* cookieOne = new Cookie("green");
Cookie* cookieTwo = new Cookie("Pink");
