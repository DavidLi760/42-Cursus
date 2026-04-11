#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string _name;
        bool _sign;
        int _grade_sign;
        int _grade_exec;
    public:
        AForm();
        AForm(const std::string name, const int s, const int e);
        AForm(const AForm& other);
        ~AForm();
        AForm& operator=(const AForm& other);
        const std::string getName() const;
        bool getSign() const;
        const int getGradeSign() const;
        const int getGradeExec() const;
        void setName(const std::string& name);
        void setGradeSign(int grade);
        void setGradeExec(int grade);
        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        virtual void action(const Bureaucrat& b) const = 0;
        class GradeTooHighException : public std::exception
        {
            const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            const char* what() const throw();
        };
        class NotSignedException : public std::exception
        {
            const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif