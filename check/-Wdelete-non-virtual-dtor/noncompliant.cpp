#include <stdlib.h>
#include <5/iostream>

struct Base
{
    virtual void f();
};

struct Derived : Base
{
};

void f()
{
    Base *b = new Derived();
    // ...
    delete b;
}
int main()
{
    return 0;
}