#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
    // std::cout << "Default BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
    // std::cout << "Default BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange &BitcoinExchange)
{
    // std::cout << "BitcoinExchange Copy constructor called" << std::endl;
    *this = BitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange &BitcoinExchange)
{
    // std::cout << "BitcoinExchange Copy assignment operator called" << std::endl;

    (void)BitcoinExchange;
    return *this;
}

bool BitcoinExchange::isNumericString(const std::string& str) {
  std::regex pattern("^[0-9]+$");
  return std::regex_match(str, pattern);
}

void BitcoinExchange::makeDict() {
    std::ifstream file("./data.csv");
    std::string line;

    int i = 0;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream is(line);
            std::string key;
            std::string token;
            std::pair<std::string, int> p;
            while (std::getline(is, token, ',')) {
                if (!isNumericString(token)) {
                    this->dict.insert(std::make_pair(token, 0));
                    key = token;
                }
                else {
                    this->dict[key] = std::atoi(token.c_str());
                    // std::cout << key << " : " << dict[key] << std::endl;
                }
            }
            std::cout << i++ << std::endl;
        }
        file.close();
    } 
    else {
        std::cerr << "Error : can not open data.csv" << std::endl;
        exit(1);
    }
}