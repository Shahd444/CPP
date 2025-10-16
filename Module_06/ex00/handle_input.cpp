#include "ScalarConverter.hpp"

void handleSpace(char c)
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c)<< "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void handlePrintable(char c)
{
    std::cout << "char: "<< c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c)<< "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

bool isAllDigits(std::string const & input)
{
    for (std::string::size_type i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]))
            return false;
    }
    return true;
}

void handleDicimal(std::string const & input)
{
    if (input[input.size() - 1] == 'f')
    {
        char *endptr;
        std::string num = input.substr(0, input.size() - 1);
        double val = strtod(num.c_str(), &endptr);

        if(*endptr != '\0')
        {
            std::cout << "unknown input\n";
            return ;
        }

        if (val >= 32 && val <= 126)
            std::cout << "char: "<< static_cast<char>(val) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (val >= INT_MIN && val <= INT_MAX)
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        if (val > FLT_MAX)
            std::cout << "float: inff" << std::endl;
        else if (val < -FLT_MAX)
            std::cout << "float: -inff" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << static_cast<double>(val) << std::endl;
    }
    else
    {
        char *endptr;
        double val = strtod(input.c_str(), &endptr);
        if(*endptr != '\0')
        {
            std::cout << "unknown input\n";
            return ;
        }
        if (val >= 32 && val <= 126)
            std::cout << "char: "<< static_cast<char>(val) << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        if (val >= INT_MIN && val <= INT_MAX)
            std::cout << "int: " << static_cast<int>(val) << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(val) << std::endl;

    }
}

void handleNumeric(std::string const & input)
{

    if (input.length() == 1 && isdigit(input[0]))
    {
        char c = input[0];
        std::cout << "char: " << c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;

    }


    else if((input.length() == 1) && (input[0] == '+' || input[0] == '-'))
    {
        char c = input[0];
        std::cout << "char: "<< c << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << static_cast<float>(c)<< "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    char *endptr;
    double val = strtod(input.c_str(), &endptr);

    if(*endptr != '\0')
    {
        std::cout << "unknown input\n";
        return ;
    }


    if (val >= 32 && val <= 126)
        std::cout << "char: "<< static_cast<char>(val) << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    if (val >= INT_MIN && val <= INT_MAX)
        std::cout << "int: " << static_cast<int>(val) << std::endl;
    else 
        std::cout << "int: impossible" << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    if (val > FLT_MAX)
        std::cout << "float: inff" << std::endl;
    else if (val < -FLT_MAX)
        std::cout << "float: -inff" << std::endl;
    else
        std::cout << "float: " << static_cast<float>(val) << "f" << std::endl;\

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "double: " << static_cast<double>(val) << std::endl;
}