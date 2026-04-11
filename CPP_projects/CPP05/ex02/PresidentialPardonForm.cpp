# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
    setName("default");
    _target = "default";
    setGradeExec(5);
    setGradeSign(25);
    // std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
{
    setName(target);
    _target = target;
    setGradeExec(5);
    setGradeSign(25);
    // std::cout << "PresidentialPardonForm Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
{
    setName(other._target);
    _target = other._target;
    setGradeExec(5);
    setGradeSign(25);
    // std::cout << "PresidentialPardonForm Copy Constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    // std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    setName(other.getName());
    _target = other._target;
    setGradeExec(5);
    setGradeSign(25);
    return (*this);
}

void PresidentialPardonForm::action(const Bureaucrat& b) const
{
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}