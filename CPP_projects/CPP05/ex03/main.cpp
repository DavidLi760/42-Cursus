#include "Bureaucrat.hpp"
# include "Intern.hpp"
# include "AForm.hpp"
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

        Intern someRandomIntern;
        Intern someRandomIntern1;
        Intern someRandomIntern2;
        AForm* rrf;
        AForm* rrf1;
        AForm* rrf2;
        
        rrf = someRandomIntern.makeForm("robotomy request", "Robot");
        rrf1 = someRandomIntern1.makeForm("NONO FORM", "error");
        rrf2 = someRandomIntern2.makeForm("presidential pardon", "President");

        if (rrf)
        {
            a.signForm(*rrf);
            a.executeForm(*rrf);
        }
        if (rrf1)
        {
            a.signForm(*rrf1);
            a.executeForm(*rrf1);
        }
        if (rrf2)
        {
            a.signForm(*rrf2);
            a.executeForm(*rrf2);
        }
    }
    catch(std::exception & e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}