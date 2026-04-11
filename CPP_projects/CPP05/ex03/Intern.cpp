#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
    // std::cout << "Intern Default Constructor called" << std::endl;
}

Intern::Intern(const Intern& other)
{
    // std::cout << "Intern Copy Constructor called" << std::endl;
}

Intern::~Intern()
{
    // std::cout << "Intern Destructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other)
{
    // std::cout << "Intern Copy assignment operator called" << std::endl;
    return (*this);
}

AForm* Intern::makeForm(const std::string form, const std::string& target)
{	
    const std::string available_forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
        static AForm* (*formCreators[])(const std::string&) = {
            &ShrubberyCreationForm::create,
            &RobotomyRequestForm::create,
            &PresidentialPardonForm::create
        };
    
        for (size_t i = 0; i < 3; i++)
        {
            if (form == available_forms[i])
            {
                std::cout << "Intern creates " << form << std::endl;
                return formCreators[i](target);
            }
        }
        std::cout << "Error: Form '" << form << "' does not exist!" << std::endl;
        return NULL;
}