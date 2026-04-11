#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bob", 2);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b << std::endl;
        // b.incrementGrade();
        // std::cout << b << std::endl;
        b.decrementGrade();
        std::cout << b << std::endl;

        Bureaucrat b2("John", 0);
        std::cout << b2 << std::endl;
    }
    catch(std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}