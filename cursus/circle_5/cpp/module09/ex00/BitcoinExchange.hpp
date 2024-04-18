#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <regex>

class BitcoinExchange {
    private:
        std::map<std::string, int> dict;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &BitcoinExchange);
        BitcoinExchange &operator=(BitcoinExchange& BitcoinExchange);

        void makeDict();
        bool isNumericString(const std::string& str);
        
};

#endif