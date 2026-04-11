#include "Base.hpp"

int main()
{
    std::srand(std::time(0));

    Base* obj = generate();
    std::cout << "Type by pointer: ";
    identify(obj);
    std::cout << "Type by reference: ";
    identify(*obj);
    delete obj;
    return 0;
}