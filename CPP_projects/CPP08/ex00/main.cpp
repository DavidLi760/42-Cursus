#include "easyfind.hpp"

const char *NotFoundException::what() const throw()
{
    return "Element not found";
}

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(21);
    v.push_back(30);
    std::list<int> l;
    l.push_back(5);
    l.push_back(15);
    l.push_back(25);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 30);
        std::cout << "Found : " << *it << std::endl;
        std::vector<int>::iterator it2 = easyfind(v, 20);
        std::cout << "Found : " << *it2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    try
    {
        std::list<int>::iterator it = easyfind(l, 15);
        std::cout << "Found in list : " << *it << std::endl;
        it = easyfind(l, 100);
        std::cout << "Found in list : " << *it << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Exception : " << e.what() << std::endl;
    }
    return 0;
}