#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <exception>
# include <algorithm>
# include <iterator>

class TooMuchNumberException : public std::exception
{
    public:
        const char *what() const throw();
};

class NotEnoughNumberException : public std::exception
{
    public:
        const char *what() const throw();
};

class Span
{
    private:
        unsigned int _max;
        std::vector<int> _numbers;
    public:
        Span();
        Span(unsigned int max);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int nb);
        
        template <typename It>
        void addNumbers(It begin, It end)
        {
            size_t dist = std::distance(begin, end);
            if (_numbers.size() + dist >= _max)
                throw TooMuchNumberException();
            _numbers.insert(_numbers.end(), begin, end);
        }
        
        int shortestSpan() const;
        int longestSpan() const;
};

#endif