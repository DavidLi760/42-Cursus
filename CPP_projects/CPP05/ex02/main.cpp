#include "Bureaucrat.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        std::srand(std::time(0));
        Bureaucrat a("King", 1);
        Bureaucrat b("Zobo", 25);
        Bureaucrat c("Bob", 45);
        
        PresidentialPardonForm p("President");
        RobotomyRequestForm r("Robot");
        ShrubberyCreationForm s("Home");

        std::cout << std::endl;
        b.signForm(p);
        b.executeForm(p);
        std::cout << std::endl;
        b.signForm(r);
        b.executeForm(r);
        std::cout << std::endl;
        b.signForm(s);
        b.executeForm(s);
    }
    catch(std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}