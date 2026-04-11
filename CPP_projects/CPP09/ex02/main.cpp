#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: Please provide a sequence of positive integers." << std::endl;
        return 1;
    }
    
    std::vector<int> vec;
    std::deque<int> deq;
    
    for (int i = 1; i < argc; ++i)
    {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num <= 0)
        {
            std::cerr << "Error: Invalid input ('" << argv[i] << "'). Only positive integers allowed." << std::endl;
            return 1;
        }
        vec.push_back(num);
        deq.push_back(num);
    }
    
    print_container("Before: ", vec);
    
    clock_t start = clock();
    vec = ford_johnson_sort(vec);
    clock_t end = clock();
    double time_vec = double(end - start) * 1000 / CLOCKS_PER_SEC;
    
    print_container("After: ", vec);
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << time_vec << " ms" << std::endl;
    
    start = clock();
    ford_johnson_sort(deq);
    end = clock();
    double time_deq = double(end - start) * 1000 / CLOCKS_PER_SEC;
    
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque: " << time_deq << " ms" << std::endl;
    
    return 0;
}
