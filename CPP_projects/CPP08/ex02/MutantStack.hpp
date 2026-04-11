#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <list>

template<typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() {};
        MutantStack(const MutantStack &other) {(void)other;};
        ~MutantStack() {};
        MutantStack &operator=(const MutantStack &other) {(void)other; return (0);};
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }    
        iterator end()
        {
            return this->c.end();
        }
};

#endif