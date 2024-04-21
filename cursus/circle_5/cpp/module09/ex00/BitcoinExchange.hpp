#ifndef __BITCOINEXCHANGE_HPP__
# define __BITCOINEXCHANGE_HPP__
# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>

class BitcoinExchange {
    private:
        std::map<std::string, std::string> dict;

    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &BitcoinExchange);
        BitcoinExchange &operator=(BitcoinExchange& BitcoinExchange);

        void makeDict();
        bool isDate(std::string str);
        void calculate(std::string fileName);
        bool isValidDate(std::string date);
        bool isValidMonth(int month);
        bool isValidDay(int year, int month, int day);
        bool isLeapYear(int year);
        bool isThirtyOne(int month);
        bool isValidYear(int year);
        std::string findLowerDate(std::string date);
        int findDay(int year, int month);
        void print(std::string date, double value, std::string rate);
        std::string numToStr(int year, int month, int day);
        bool isValue(std::string str);
        std::string trimWhitespace(std::string str);
};

#endif