#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        void action(const Bureaucrat& b) const;
        static AForm* create(const std::string& target);
};

#endif