#include "Base.hpp"

Base::~Base(){}

Base * generate(void)
{
    int res = rand() % 3;
    // res = 10;
    if (res == 0)
        return new A();
    if (res == 1)
        return new B();
    if (res == 2)
        return new C();
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Class A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "Class B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "Class C\n";
    else
    	std::cout << "invalid class type\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Class A\n";
        return;
    }
    catch(...)
    {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Class B\n";
        return;
    }
    catch(...)
    {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Class C\n";
        return;
    }
    catch(...)
    {
        std::cout << "invalid class type\n";
    }
    
}
