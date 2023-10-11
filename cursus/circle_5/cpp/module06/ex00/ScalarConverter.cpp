#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
    std::cout << "Default ScalarConverter constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "Default ScalarConverter destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& scalarConverter)
{
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
    (void)scalarConverter;
    *this = scalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& scalarConverter)
{
    std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
    (void)scalarConverter;
    return *this;
}

const char *ScalarConverter::NotDisplayableException::what() const throw()
{
    return "Non displayable";
}

const char *ScalarConverter::ImpossibleToConvertAllException::what() const throw()
{
    return "char: Impossible\nint: Impossible\nfloat: Impossible\ndouble: Impossible\n";
}

const char *ScalarConverter::ImpossibleToConvertException::what() const throw()
{
    return "Impossible";
}

void ScalarConverter::convert(std::string data)
{
    double value;
    char *end;
    try {
        isApplicable(data, value, &end);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return ;
    }
    applyToChar(data, value);
    applyToInt(data, value);
    applyToFloat(data, value, &end);
    applyToDouble(data, value);
}

void ScalarConverter::applyToFloat(std::string data, double &value, char **end)
{
    std::cout << "float : ";
    try {
        isFloat(data, value, end);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::isFloat(std::string data, double &value, char **end)
{
    if ((value == 0 && data.compare("0")) || isChar(data))
        throw ImpossibleToConvertException();
    else if (isPseudoLiteral(data) || (*end && **end == 'f' && data.find(".") != std::string::npos))
        std::cout << static_cast<float>(value) << "f" << std::endl;
    else if (*end && **end == 'f' && data.find(".") == std::string::npos)
        std::cout << static_cast<float>(value) << ".0f" << std::endl;
    else if (*end && **end != 'f' && data.find(".") != std::string::npos)
        std::cout << static_cast<float>(value) << "f" << std::endl;
    else
        std::cout << static_cast<float>(value) << ".0f" << std::endl;
}

void ScalarConverter::applyToDouble(std::string data, double &value)
{
    std::cout << "double : ";
    try {
        isDouble(data, value);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::isDouble(std::string data, double &value)
{
    if (!isChar(data) && !isPseudoLiteral(data) && data.find(".") == std::string::npos)
        std::cout << static_cast<double>(value) << ".0" << std::endl;
    else if (!isChar(data) && (isPseudoLiteral(data) || data.find(".") != std::string::npos))
        std::cout << static_cast<double>(value) << std::endl;
    else
        throw ImpossibleToConvertException();
}

void ScalarConverter::isApplicable(std::string &data, double &value, char **end)
{
    value = std::strtod(data.c_str(), end);
    if (*end && **end != '\0' && data.length() > 1 \
    && (**end != 'f' || (**end == 'f' && *(*end + 1) != '\0') || (**end == 'f' && *(*end - 1) == '.')))
        throw ImpossibleToConvertAllException();
}

void ScalarConverter::applyToInt(std::string data, double &value)
{
    std::cout << "int : ";
    try {
        isInt(data, value);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::isInt(std::string data, double &value)
{
    if (isPseudoLiteral(data) || isChar(data))
        throw ImpossibleToConvertException();
    std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::applyToChar(std::string data, double &value)
{
    std::cout << "char : ";
    try {
        isPrintable(data, value);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}

void ScalarConverter::isPrintable(std::string data, double &value)
{
    // 제어 문자인 경우 (출력 불가)
    if (isPseudoLiteral(data))
        throw ImpossibleToConvertException();
    else if (isChar(data))
        value = data.at(0);
    else if (data.length() > 1 && (value < 32 || value >= 127))
        throw NotDisplayableException();
    std::cout << static_cast<char>(value) << std::endl;
}

bool ScalarConverter::isChar(std::string data)
{
    if (data.length() == 1 && data.at(0) >= 32 && data.at(0) <= 126)
        return true;
    return false;
}

bool ScalarConverter::isPseudoLiteral(std::string data)
{
    if (data.find("nan") != std::string::npos || data.find("inf") != std::string::npos)
        return true;
    return false;
}

