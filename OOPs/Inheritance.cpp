/*
Inheritance:-

Derived class   Base class

Derived Class(child): the class that inherits from another class
Base Class(parent): the class being inherited from

Types Of Inheritance:

1 Single Inheritance
2 Multiple Inheritance
3 Multi Level Inheritance
4 Hybrid Inheritance
5 Hierarchical Inheritance


1 Single Inheritance:

class A
   ^
   |
class B

class A
{
    public:
    void func(){
        cout<<"Inherited";
    }
};

class B: public A{

};

int main(){
    B b;
    b.func();
}

2 Multiple Inheritance

class A       class B
       class C


class A{
    public:
       void Afunc(){
        cout<<"Func A \n";
       }
};

class B{
    public:
    void Bfunc(){
        cout<<"Func B \n";
    }
};

class C: public A, public B{
    public:
};

int main(){
    C c;
    c.Afunc();
    c.Bfunc();
}
3 Hybrid Inheritance

           class A

class B               class C
           
            class D

4 Multi Level Inheritance:

Class A

Class B

Class C

class A{
    public:
    void Afunc(){
        cout<<"Func A \n";
    }
};

class B: public A{
    public:
    void Bfunc(){
        cout<<"Func B \n";
    }
}

class C: public B{
    public:
};

int main(){
    C c;
    c.Afunc();
    c.Bfunc();
}


5 Hierarchical Inheritance

            class A

  class B                 class C

class D class E      class F   class G


*/