#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    // std::cout << "ScalarConverter Default Constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
    // std::cout << "ScalarConverter Copy Constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    // std::cout << "ScalarConverter Destructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    // std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
    return (*this);
}

void ScalarConverter::convert(const std::string literal)
{
    if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
    {
        char c = literal[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
            float f = static_cast<float>(std::atof(literal.c_str()));
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << f << 'f' << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        double d = std::atof(literal.c_str());
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
        std::cout << "double: " << d << std::endl;
        return;
    }
    else
    {
        char *end;
        long i = std::strtol(literal.c_str(), &end, 10);

        if (*end == '\0')
        {
            if (i >= 32 && i <= 126)
                std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
            else if (i >= -128 && i <= 127)
                std::cout << "char: Non displayable" << std::endl;
            else
                std::cout << "char : impossible" << std::endl;
            if (i <= 2147483647 && i >= -2147483648)
                std::cout << "int: " << i << std::endl;
            else
                std::cout << "int: impossible" << std::endl;
            std::cout << "float: " << static_cast<float>(i) << 'f' << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
            return ;
        }
        float f = std::strtod(literal.c_str(), &end);
        if (*end == 'f' && *(end + 1) == '\0')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: " << static_cast<int>(f) << std::endl;
            std::cout << "float: " << f << 'f' << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
            return;
        }
        double d = std::strtod(literal.c_str(), &end);
        if (*end == '\0')
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: " << static_cast<int>(d) << std::endl;
            std::cout << "float: " << static_cast<float>(d) << 'f' << std::endl;
            std::cout << "double: " << d << std::endl;
            return;
        }
        std::cout << "Invalid input" << std::endl;
    }
}