#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>
# include <ctime>
#include <cstdlib>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{

};

class B : public Base
{

};

class C : public Base
{

};

Base* generate();
void identify(Base* p);
void identify(Base& p);

#endif