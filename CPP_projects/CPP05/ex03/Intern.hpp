#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        ~Intern();
        Intern& operator=(const Intern& other);
        AForm* makeForm(const std::string form, const std::string& target);
};

#endif