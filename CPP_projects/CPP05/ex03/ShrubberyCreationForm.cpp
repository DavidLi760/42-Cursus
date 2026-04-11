# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    setName("default");
    _target = "default";
    setGradeExec(137);
    setGradeSign(145);
    // std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
{
    setName(target);
    _target = target;
    setGradeExec(137);
    setGradeSign(145);
    // std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
{
    setName(other._target);
    _target = other._target;
    setGradeExec(137);
    setGradeSign(145);
    // std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    // std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    setName(other.getName());
    _target = other._target;
    setGradeExec(137);
    setGradeSign(145);
    return (*this);
}

void ShrubberyCreationForm::action(const Bureaucrat& b) const
{
    if (b.getGrade() > getGradeExec())
        throw GradeTooLowException();
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file)
    {
        std::cerr << "Error : Could not create file" << getName() << "_shrubbery" << std::endl;
        return;
    }
    file << "🌲🌲🌲🌲🌲🌲" << std::endl;
    file.close();
    std::cout << getName() << "_shrubbery has been created." << std::endl;
}

AForm* ShrubberyCreationForm::create(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}