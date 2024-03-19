#include<iostream>
#include<string>

using namespace std;

// STRINGS


int main(){
    
    // string str = "google";
    
    // cin>>str;
    // cout<<str;
    
    // different types of ways to declare strings
    
    string str1(5, 't');
    cout<<str1<<endl;
    
    
    // string newstr;
    // getline(cin, newstr);  // full sentence input output
    // cout<<newstr<<endl;
    

    
    string s1 = "fam";
    string s2 = "ily";
    
    cout<<s1[1]<<endl;
    
    // s1.append(s2);
    s1 = s1 + s2;
    cout<<s1<<endl;
    cout<<s1+s2<<endl;
    
    string abc = "dsdklnsldn";
    cout<<abc<<endl;
    abc.clear();
    cout<<abc<<endl;
    
    string t1 = "abc";
    string t2 = "abc";
    
    if(!t1.compare(t2)){
        cout<<"strings are equal";
    }
    cout<<t2.compare(t1)<<endl;
    

    return 0;
    
    
    
}

