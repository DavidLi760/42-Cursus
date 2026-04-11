#include "AForm.hpp"

AForm::AForm() : _name("default"), _sign(0), _grade_sign(150), _grade_exec(150)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "AForm Default Constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int s, const int e) : _name(name), _sign(0), _grade_sign(s), _grade_exec(e)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "AForm Constructor called" << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _sign(other._sign), _grade_sign(other._grade_sign), _grade_exec(other._grade_exec)
{
    if (_grade_sign < 1 || _grade_exec < 1)
        throw GradeTooHighException();
    else if (_grade_sign > 150 || _grade_exec > 150)
        throw GradeTooLowException();
    // std::cout << "AForm Copy Constructor called" << std::endl;
}

AForm::~AForm()
{
    // std::cout << "AForm Destructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
    // std::cout << "AForm Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_sign = other._sign;
    return (*this);
}

const std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getSign() const
{
    return (_sign);
}

const int AForm::getGradeSign() const
{
    return (_grade_sign);
}

const int AForm::getGradeExec() const
{
    return (_grade_exec);
}

void AForm::setName(const std::string& newname)
{
    _name = newname;
}

void AForm::setGradeSign(int grade)
{
    _grade_sign = grade;
}

void AForm::setGradeExec(int grade)
{
    _grade_exec = grade;
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= _grade_sign)
        _sign = true;
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low !";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form is not signed !";
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!_sign)
        throw NotSignedException();
    if (executor.getGrade() > getGradeExec())
        throw GradeTooLowException();
    action(executor);
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    os << "Name : " << f.getName() << "\nGrade to sign : " << f.getGradeSign() << "\nGrade to execute : " << f.getGradeExec() << "\nSigned : " << f.getSign();
    return os;
}