#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class   PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        void action(const Bureaucrat& b) const override;
        static AForm* create(const std::string& target);
    };

#endif