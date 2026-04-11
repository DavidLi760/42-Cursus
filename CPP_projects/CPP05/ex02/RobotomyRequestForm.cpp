# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
    setName("default");
    _target = "default";
    setGradeExec(45);
    setGradeSign(72);
    // std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
{
    setName(target);
    _target = target;
    setGradeExec(45);
    setGradeSign(72);
    // std::cout << "RobotomyRequestForm Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
    setName(other._target);
    _target = other._target;
    setGradeExec(45);
    setGradeSign(72);
    // std::cout << "RobotomyRequestForm Copy Constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    // std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    setName(other.getName());
    _target = other._target;
    setGradeExec(45);
    setGradeSign(72);
    return (*this);
}

void RobotomyRequestForm::action(const Bureaucrat& b) const
{
    std::cout << "* Drilling noises... *" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized." << std::endl;
    else
        std::cout << "No robotomization for" << _target << std::endl;
}