#include "Base.hpp"

Base::~Base()
{
    std::cout << "Base Destructor called" << std::endl;
}

Base* generate()
{
    int randNum = std::rand() % 3;
    if (randNum == 0)
        return new A();
    else if (randNum == 1)
        return new B();
    else
        return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p)) 
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p)) 
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p)) 
        std::cout << "C\n";
    else
        std::cout << "Unknown type\n";
}

void identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } 
    catch (...) {}

    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    }
    catch (...) {}

    std::cout << "Unknown type\n";
}