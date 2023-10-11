#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__
# include <iostream>
# include <string>
# include <cstdlib>

class ScalarConverter {
    public:
        ScalarConverter();
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter& scalarConverter);
        ScalarConverter& operator=(const ScalarConverter& scalarConverter);

        void convert(std::string scalarType);
        void isApplicable(std::string &data, double &value, char **end);

        void applyToChar(std::string data, double &value);
        void isPrintable(std::string data, double &value);
        bool isChar(std::string data);

        void applyToInt(std::string data, double &value);
        void isInt(std::string data, double &value);

        void applyToFloat(std::string data, double &value, char **end);
        void isFloat(std::string data, double &value, char **end);

        void applyToDouble(std::string data, double &value);
        void isDouble(std::string data, double &value);

        bool isPseudoLiteral(std::string data);

        class NotDisplayableException : public std::exception {
            public:
                const char *what() const throw();
        };
        class ImpossibleToConvertAllException : public std::exception {
            public:
                const char *what() const throw();
        };
        class ImpossibleToConvertException : public std::exception {
            public:
                const char *what() const throw();
        };
};

#endif