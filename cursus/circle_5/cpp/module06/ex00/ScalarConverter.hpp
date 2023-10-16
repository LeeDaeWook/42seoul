#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__
# include <iostream>
# include <string>
# include <cstdlib>

class ScalarConverter {
    private:
        ScalarConverter();
        virtual ~ScalarConverter();
        ScalarConverter(const ScalarConverter& scalarConverter);
        ScalarConverter& operator=(const ScalarConverter& scalarConverter);

    public:
        static void convert(std::string scalarType);
        static void isApplicable(std::string &data, double &value, char **end);

        static void applyToChar(std::string data, double &value);
        static void isPrintable(std::string data, double &value);
        static bool isChar(std::string data);

        static void applyToInt(std::string data, double &value);
        static void isInt(std::string data, double &value);

        static void applyToFloat(std::string data, double &value, char **end);
        static void isFloat(std::string data, double &value, char **end);

        static void applyToDouble(std::string data, double &value, char **end);
        static void isDouble(std::string data, double &value, char **end);

        static bool isPseudoLiteral(std::string data);

        static bool isZeroAfterDot(std::string data, char **end);

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