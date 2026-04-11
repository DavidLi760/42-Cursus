#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: could not open file" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    exchange.loadDatabase("data.csv");

    std::ifstream inputFile(argv[1]);
    if (!inputFile)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    exchange.convert(inputFile);

    return 0;
}