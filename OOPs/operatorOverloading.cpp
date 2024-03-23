#include <iostream>
using namespace std;

class complex
{
private:
    int real, imag;

public:
    complex(int r = 0, int i = 0)
    { // constructor
        real = r;
        imag = i;
    }
    complex operator + (complex const &obj)  //Operator Overloading
    {
        complex res;
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }

    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    complex c1(12, 7);
    complex c2(6, 7);
    complex c3 = c1 + c2;
    c3.display();

    return 0;
}