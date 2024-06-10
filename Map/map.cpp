#include<iostream>
#include<map>
#include<string>
using namespace std;


// Map is an associative array
int main(){
    map<string, int> marksMap;
    marksMap["Harray"] = 98;
    marksMap["Jack"] = 59;
    marksMap["Rohan"] = 2;

    map<string, int> :: iterator iter;
    for(iter=marksMap.begin(); iter != marksMap.end(); iter++){
        cout<<(*iter).first<<" "<<(*iter).second<<"\n";
    }

    cout<<"the size of the map is "<<marksMap.size()<<endl;
    cout<<"The max size of the map is "<<marksMap.max_size()<<endl;
    cout<<"The empty's return value is "<<marksMap.empty()<<endl;


    return 0;
}