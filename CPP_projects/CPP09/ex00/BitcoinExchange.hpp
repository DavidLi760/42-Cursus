#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <sstream>
# include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _database;

    public:
        void loadDatabase(const std::string &filename);
        void convert(std::ifstream &inputFile);
        float getExchangeRate(const std::string &date);
};

#endif