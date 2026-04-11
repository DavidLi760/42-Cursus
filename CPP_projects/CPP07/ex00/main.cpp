#include "whatever.hpp"

int main()
{
    int a = 3, b = 7;
    
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    std::cout << "min(a, b) = " << min(a, b) << std::endl;
    std::cout << "max(a, b) = " << max(a, b) << std::endl;

    std::string s1 = "apple", s2 = "banana";

    std::cout << "Before swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;
    swap(s1, s2);
    std::cout << "After swap: s1 = " << s1 << ", s2 = " << s2 << std::endl;

    std::cout << "min(\"apple\", \"banana\") = " << ::min(s1, s2) << std::endl;
    std::cout << "max(\"apple\", \"banana\") = " << ::max(s1, s2) << std::endl;

    return 0;
}