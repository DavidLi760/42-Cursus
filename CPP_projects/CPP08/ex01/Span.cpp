#include "Span.hpp"

const char *TooMuchNumberException::what() const throw()
{
    return "Too much number";
}

const char *NotEnoughNumberException::what() const throw()
{
    return "Not enough number";
}

Span::Span() : _max(0), _numbers(0)
{
}

Span::Span(unsigned int max) : _max(max), _numbers(0)
{
}

Span::Span(const Span &other)
{
    _max = other._max;
    _numbers = other._numbers;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max = other._max;
        _numbers = other._numbers;
    }
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int nb)
{
    if (_numbers.size() >= _max)
        throw TooMuchNumberException();
    _numbers.push_back(nb);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumberException();
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minimum = sorted[1] - sorted[0];
    for (unsigned int i = 1; i < sorted.size() - 1; i++)
    {
        int span = sorted[i + 1] - sorted[i];
        if (span < minimum)
            minimum = span;
    }
    return (minimum);
}

int find_min(int a, int b)
{
    if (a > b)
        return (b);
    return (a);
}

int find_max(int a, int b)
{
    if (a > b)
        return (a);
    return (b);
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NotEnoughNumberException();

    int minValue = *_numbers.begin();
    int maxValue = *_numbers.begin();

    for (std::vector<int>::const_iterator it = _numbers.begin(); it != _numbers.end(); it++)
    {
        minValue = find_min(minValue, *it);
        maxValue = find_max(maxValue, *it);
    }

    return maxValue - minValue;
}
