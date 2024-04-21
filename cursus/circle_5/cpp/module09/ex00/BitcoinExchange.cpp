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

bool BitcoinExchange::isDate(std::string str) {
    int cnt = 0;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '-')
            cnt++;
    }
    if (cnt == 2)
        return true;
    return false;
}

void BitcoinExchange::makeDict() {
    std::ifstream file("./data.csv");
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream is(line);
            std::string key;
            std::string token;
            while (std::getline(is, token, ',')) {
                if (isDate(token)) {
                    this->dict.insert(std::make_pair(token, ""));
                    key = token;
                }
                else {
                    this->dict[key] = token;
                }
            }
        }
        file.close();
    } 
    else {
        std::cout << "Error : data.csv can't be opened" << std::endl;
        exit(1);
    }
}

bool BitcoinExchange::isValidMonth(int month) {
    if (month >= 1 && month <= 12)
        return true;
    return false;
}

bool BitcoinExchange::isThirtyOne(int month) {
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      return true;
    default:
      return false;
  }
}


bool BitcoinExchange::isValidDay(int year, int month, int day) {
    if (month == 2 && !isLeapYear(year) && day >= 1 && day <= 28) 
        return true;
    if (month == 2 && isLeapYear(year) && day >= 1 && day <= 29) 
        return true;
    if (!isThirtyOne(month) && day >= 1 && day <= 30)
        return true;
    if (isThirtyOne(month) && day >= 1 && day <= 31)
        return true;
    return false;
}

bool BitcoinExchange::isValidYear(int year) {
    if (year < 2009 || year > 2999)
        return false;
    return true;
}

bool BitcoinExchange::isLeapYear(int year) {
  if (year % 4 != 0) {
    return false;
  } else if (year % 100 == 0 && year % 400 != 0) {
    return false;
  } else {
    return true;
  }
}

bool BitcoinExchange::isValidDate(std::string date) {
    std::istringstream ss(date);
    std::string token;
    int tokens[3];
    
    int i = 0;
    while (std::getline(ss, token, '-')) {
        if (i == 0 && isValidYear(std::atoi(token.c_str()))) {
            tokens[i] = std::atoi(token.c_str());
        }
        else if (i == 1 && isValidMonth(std::atoi(token.c_str()))) {
            tokens[i] = std::atoi(token.c_str());
        }
        else if (i == 2 && isValidDay(tokens[0], tokens[1], std::atoi(token.c_str()))) {
            tokens[i] = std::atoi(token.c_str());
        }
        else {
            return false;
        }
        i++;
    }
    return true;
}

int BitcoinExchange::findDay(int year, int month) {
    if (month == 2 && !isLeapYear(year))
        return 28;
    else if (month == 2 && isLeapYear(year))
        return 29;
    else if (isThirtyOne(month))
        return 31;
    else
        return 30;
}

std::string BitcoinExchange::numToStr(int year, int month, int day) {
        std::stringstream is;
        if (month < 10 && day < 10)
            is << year << "-" << "0" << month << "-" << "0" << day;
        else if (month < 10)
            is << year << "-" << "0" << month << "-" << day;
        else if (day < 10)
            is << year << "-" << month << "-" << "0" << day;
        else
            is << year << "-" << month << "-" << day;
        return is.str();
}

std::string BitcoinExchange::findLowerDate(std::string date) {
    std::string token;
    int year;
    int month;
    int day;

    int i = 0;
    while (true) {
        std::istringstream ss(date);
        while (std::getline(ss, token, '-')) {
            if (i == 0)
                year = std::atoi(token.c_str());
            else if (i == 1)
                month = std::atoi(token.c_str());
            else if (i == 2)
                day = std::atoi(token.c_str());
            i++;
        }
        day--;
        if (day == 0) {
            month--;
            if (month == 0) {
                month = 12;
                day = 31;
                year--;
                if (year == 0) {
                    return "NA";
                }
            }
            else {
                day = findDay(year, month);
            }
        }
        date = numToStr(year, month, day);
        if (this->dict.find(date) != this->dict.end())
            break;
    }
    return date;
}

void BitcoinExchange::print(std::string date, double value, std::string rate) {
    std::cout << date << " => " << value << " = " << rate << std::endl;
}

bool BitcoinExchange::isValue(std::string str) {
    for (unsigned int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]) && str[i] != '.') {
            return false;
        }
    }
    return true;
}

void BitcoinExchange::calculate(std::string fileName) {
    std::ifstream file(fileName);
    std::string line;

    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream is(line);
            std::string token;
            std::string date;
            double value;

            while (std::getline(is, token, '|')) {
                if (isDate(token)) {
                    if (!isValidDate(token)) {
                        std::cout << "Error: bad input => " << token << std::endl;
                        break;
                    }
                    else
                        date = token;
                }
                else if (isValue(token)) {
                    value = std::strtod(token.c_str(), NULL);
                    if (value > 1000)
                        std::cout << "Error: too large a number." << std::endl;
                    else if (value < 0)
                        std::cout << "Error: not a positive number." << std::endl;
                    else {
                        date.erase(remove(date.begin(), date.end(), ' '), date.end());
                        if (this->dict.find(date) != this->dict.end()) {
                            print(date, value, this->dict[date]);
                        }
                        else {
                            std::string newDate = findLowerDate(date);
                            if (newDate == "NA")
                                std::cout << "Error: bad input => " << date << std::endl;
                            else
                                print(date, value, this->dict[newDate]);
                        }
                    }
                }
                // else if ((value = std::strtod(token.c_str(), NULL)) && errno == 0) {
                //     if (value > 1000)
                //         std::cout << "Error: too large a number." << std::endl;
                //     else if (value < 0)
                //         std::cout << "Error: not a positive number." << std::endl;
                //     else {
                //         date.erase(remove(date.begin(), date.end(), ' '), date.end());
                //         if (this->dict.find(date) != this->dict.end()) {
                //             print(date, value, this->dict[date]);
                //         }
                //         else {
                //             std::string newDate = findLowerDate(date);
                //             if (newDate == "NA")
                //                 std::cout << "Error: bad input => " << date << std::endl;
                //             else
                //                 print(date, value, this->dict[newDate]);
                //         }
                //     }
                // }
                else {
                    std::cout << "Error: bad input => " << date << std::endl;
                    break;
                }
            }
        }
        file.close();
    } 
    else {
        std::cout << "Error : " << fileName << " can't be opened" << std::endl;
        exit(1);
    }
}