#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <cstring>

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(const std::string str);
};

#endif