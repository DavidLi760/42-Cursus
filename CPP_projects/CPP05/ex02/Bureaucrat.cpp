#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    // std::cout << "Bureaucrat Default Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    // std::cout << "Bureaucrat Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    else if (_grade > 150)
        throw GradeTooLowException();
    // std::cout << "Bureaucrat Copy Constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
    // std::cout << "Bureaucrat Destructor called" << std::endl;    
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    // std::cout << "Bureaucrat Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low !";
}

void Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade += 1;
}

const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const& form)
{
    try
    {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}