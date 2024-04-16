#include <iostream>
#include <vector>
using namespace std;

void display(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> vect1; // dynamic array
    int element, size;

    cout << "Enter the size of the vector: ";
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element to add to this vector" << endl;
        cin >> element;
        vect1.push_back(element);
    }
    vect1.pop_back();
    display(vect1);
    return 0;
}