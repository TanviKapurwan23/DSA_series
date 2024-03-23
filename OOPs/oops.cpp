#include <iostream>
using namespace std;

class student
{
    string name;

public:
    // Data Members
    int age;
    bool gender;

    student()
    {
        cout << "Default Constructor" << endl; // no parameters
    }

    student(string s, int a, int g) // parameterised constructor
    {
        cout << "Parameterised Constructor" << endl;
        name = s;
        age = a;
        gender = g;
    }

    student(student &a)
    {
        name = a.name;
        age = a.age;
        gender = a.gender;
    }

    ~student()
    {
        cout << "Destructor called" << endl;
    }

    void setName(string s)
    {
        name = s;
    }

    void getName()
    {
        cout << name << endl;
    }

    void printInfo()
    {
        cout << "Name = ";
        cout << name << endl;
        cout << "Age = ";
        cout << age << endl;
        cout << "Gender = ";
        cout << gender << endl;
    }
    bool operator == (student &a)
    {
        if (name == a.name && age==a.age && gender==a.gender){
            return true;
        }
        return false;
    }
};

int main()
{
    // student a;
    // a.name = 'Urvi';
    // a.age = 20;
    // a.gender = 1;

    // student arr[3];
    // for (int i = 0; i < 3; i++)
    // {
    //     string s;
    //     cout << "Name = ";
    //     cin >> s;
    //     arr[i].setName(s);
    //     cout << "Age = ";
    //     cin >> arr[i].age;
    //     cout << "Gender = ";
    //     cin >> arr[i].gender;
    // }

    // for (int i = 0; i < 3; i++)
    // {
    //     arr[i].printInfo();
    // }

    student a("Urvi", 20, 1);
    // a.printInfo();
    student b("Rahul", 21, 0);
    student c = a;

    // Operator Overloading??

    if (b == a)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not Same" << endl;
    }

    return 0;
}

/*
Parameterised Constructor
Parameterised Constructor
Not same
Destructor called
Destructor called
Destructor called
*/