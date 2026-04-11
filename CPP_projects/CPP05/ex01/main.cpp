#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bob1", 1);
        Form f("peasantForm", 150, 150);
        std::cout << f << std::endl;
        b.signForm(f);
        std::cout << f << std::endl;
        Bureaucrat b2("Bob2", 150);
        Form f2("kingForm", 1, 1);
        std::cout << f2 << std::endl;
        b2.signForm(f2);
    }
    catch(std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}