#include<iostream>
using namespace std;

class Employee{
    int id;
    static int count;  
 
    public:
      void setData(void){
       cout<<"Enter the Id"<<endl;
       cin>>id;
       count++;
      }
      void getData(void){
        cout<<"The id of the employee is  "<<id<<" and this is employee number "<<count<<endl;
      }
      static void getCount(void){   // static function
      //cout<<id; // throws and error
        cout<<"The value of count is "<<count<<endl;
      }

};
int Employee :: count; //default value is 0
int main(){
// count is the static data member of the class Employee
    Employee sohan, rohan, lovish;   // they are sharing one count variable
    sohan.setData();
    sohan.getData();

    Employee::getCount();

    rohan.setData();
    rohan.getData();
    Employee::getCount();

    lovish.setData();
    lovish.getData();
    Employee::getCount();

    return 0;
}