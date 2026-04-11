#include "Form.hpp"

Form::Form() : _name("default"), _sign(0), _grade_sign(150), _grade_exec(150)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "Form Default Constructor called" << std::endl;
}

Form::Form(const std::string name, const int s, const int e) : _name(name), _sign(0), _grade_sign(s), _grade_exec(e)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "Form Constructor called" << std::endl;
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "Form Copy Constructor called" << std::endl;
}

Form::~Form()
{
    // std::cout << "Form Destructor called" << std::endl;
}

Form& Form::operator=(const Form& other)
{
    // std::cout << "Form Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_sign = other._sign;
    return (*this);
}

const std::string Form::getName() const
{
    return (_name);
}

bool Form::getSign() const
{
    return (_sign);
}

const int Form::getGradeSign() const
{
    return (_grade_sign);
}

const int Form::getGradeExec() const
{
    return (_grade_exec);
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _grade_sign)
        _sign = true;
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high !";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low !";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
    os << "Name : " << f.getName() << "\nGrade to sign : " << f.getGradeSign() << "\nGrade to execute : " << f.getGradeExec() << "\nSigned : " << f.getSign();
    return os;
}