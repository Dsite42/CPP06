#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

#include "ScalarConverter.hpp"


// Constructors
ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::outputAsAll(double value, bool isFloatingPoint, int precision) {
    // Special handling for NaN and infinities
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << (std::isnan(value) ? "nanf" : (value > 0 ? "+inff" : "-inff")) << "\n";
        std::cout << "double: " << (std::isnan(value) ? "nan" : (value > 0 ? "+inf" : "-inf")) << "\n";
        return;
    }

    // char conversion
    if (std::isprint(static_cast<int>(value)) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
    {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    }
    else
    {
        std::cout << "char: Non displayable or impossible\n";
    }

    // int, float, double conversion
    std::cout << "int: " << static_cast<int>(value) << "\n";

    // float and double conversion with dynamic precision
    if (isFloatingPoint)
        std::cout << std::fixed << std::setprecision(precision);
    else
        std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << "\n";
}


// Member functions
void ScalarConverter::convert(const std::string& literal)
{
    int precision = 0;
    char single_char = 0;
    try
    {
        // Handle single character
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            single_char = literal[0];
            outputAsAll(static_cast<int>(single_char), false, 0);
        }
        else
        {
            // Convert and print for other cases
            // set precision for float and double
            double doubleValue = std::stod(literal);
            std::size_t decimalPos = literal.find('.');
            if (decimalPos == std::string::npos)
                precision = 0;
            else if (literal[literal.length() - 1] == 'f')
                precision = literal.length() - decimalPos - 2;
            else
                precision = literal.length() - decimalPos - 1;
            outputAsAll(doubleValue, decimalPos != std::string::npos, precision);
        }
    }
    catch (const std::exception&)
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

