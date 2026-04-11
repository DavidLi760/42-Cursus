#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

// int main()
// {
//     try
//     {
//         Span sp = Span(10001);
    
//         std::vector<int> data;
    
//         for (unsigned int i = 0; i < 10000; ++i)
//             data.push_back(std::rand());
    
//         sp.addNumbers(data.begin(), data.end());
    
//         std::cout << sp.shortestSpan() << std::endl;
//         std::cout << sp.longestSpan() << std::endl;        
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << "Exception: " << e.what() << '\n';
//     }
    

//     return 0;
// }