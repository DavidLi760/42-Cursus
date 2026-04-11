#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string _name;
        bool _sign;
        const int _grade_sign;
        const int _grade_exec;
    public:
        Form();
        Form(const std::string name, const int s, const int e);
        Form(const Form& other);
        ~Form();
        Form& operator=(const Form& other);
        const std::string getName() const;
        bool getSign() const;
        const int getGradeSign() const;
        const int getGradeExec() const;
        void beSigned(const Bureaucrat& b);
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif