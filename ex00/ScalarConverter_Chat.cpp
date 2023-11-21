#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

void outputAsAll(double value, bool isFloatingPoint, int precision);

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter() {} // Prevent instantiation
};

void ScalarConverter::convert(const std::string& literal) {
    try {
        // Handle single character
        if (literal.length() == 1 && !std::isdigit(literal[0])) {
            char ch = literal[0];
            outputAsAll(static_cast<int>(ch), false, 0);
        } else {
            // Convert and print for other cases
            double doubleValue = std::stod(literal);
            std::size_t decimalPos = literal.find('.');
            int precision = decimalPos != std::string::npos ? literal.length() - decimalPos - 1 : 0;
            outputAsAll(doubleValue, decimalPos != std::string::npos, precision);
        }
    } catch (const std::exception&) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
    }
}

void outputAsAll(double value, bool isFloatingPoint, int precision) {
    // Special handling for NaN and infinities
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: " << (std::isnan(value) ? "nanf" : (value > 0 ? "+inff" : "-inff")) << "\n";
        std::cout << "double: " << (std::isnan(value) ? "nan" : (value > 0 ? "+inf" : "-inf")) << "\n";
        return;
    }

    // char conversion
    if (std::isprint(static_cast<int>(value)) && value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max()) {
        std::cout << "char: '" << static_cast<char>(value) << "'\n";
    } else {
        std::cout << "char: Non displayable or impossible\n";
    }

    // int, float, double conversion
    std::cout << "int: " << static_cast<int>(value) << "\n";

    // float and double conversion with dynamic precision
    std::cout << std::fixed << std::setprecision(isFloatingPoint ? precision : 1);
    std::cout << "float: " << static_cast<float>(value) << "f\n";
    std::cout << "double: " << value << "\n";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>\n";
        return 1;
    }

    ScalarConverter::convert(argv[1]);

    return 0;
}
