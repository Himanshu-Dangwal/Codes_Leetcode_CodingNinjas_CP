#include <iostream>
using namespace std;

class A
{
public:
    void f1()
    {
        cout << "f1 Inside class A" << endl;
    }
    virtual void f2()
    {
        cout << "f2 Inside class A" << endl;
    }
    virtual void f3()
    {
        cout << "f3 Inside class A" << endl;
    }
    virtual void f4()
    {
        cout << "f4 Inside class A" << endl;
    }
};

class B : public A
{
public:
    void f1()
    {
        cout << "f1 Inside class B" << endl;
    }
    void f2()
    {
        cout << "f2 Inside class B" << endl;
    }
    void f4(int x)
    {
        cout << "f4 Inside class B" << endl;
    }
};

int main()
{
    A *p;
    B o2;
    p = &o2;
    p->f1();
    p->f2();
    p->f3();
    // p->f4();
    // p->f4(5);
    p->f4();
}
