#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class   RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        void action(const Bureaucrat& b) const override;
};

#endif