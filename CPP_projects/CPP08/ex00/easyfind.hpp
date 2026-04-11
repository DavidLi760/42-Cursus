#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <string>
# include <iostream>
# include <algorithm>
# include <list>
# include <vector>
# include <exception>

class NotFoundException : public std::exception
{
    public:
        const char *what() const throw();
};

template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw NotFoundException();
    return it;
}


#endif