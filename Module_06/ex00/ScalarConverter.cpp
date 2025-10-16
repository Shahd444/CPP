#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter (const ScalarConverter& old_obj)
{
    (void)old_obj;
}

ScalarConverter& ScalarConverter::operator =(const ScalarConverter& ref)
{
    (void)ref;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::convert(std::string const &input)
{

    if (input.empty())
    {
        std::cout << "unknown input\n";
        return ;
    }
    if (input.length() == 1  && !isdigit(input[0]) && input[0] != '+' && input[0] != '-')
    {
        if (isspace(input[0]) )
            handleSpace(input[0]);
        else if(isprint(input[0]))
            handlePrintable(input[0]);
        else
            std::cout << "Type: unknown\n";
    }
    else 
    {
        if (input == "nan" || input == "nanf" || input == "-nan" || input == "-nanf")
        {
            std::cout << "char: impossible\nint: impossible\nfloat: nanf\ndouble: nan\n";\
            return;
        }
        if (input == "+inf" || input == "-inf" )
        {
            std::cout << "char: impossible\n" << "int: impossible\n" << "float: " << input << "f\n" << "double: " << input << '\n';
            return;
        }
        if (input == "+inff" || input == "-inff")
        {
            std::cout << "char: impossible\n" << "int: impossible\n" << "float: " << input << '\n' << "double: " << input.substr(0, input.size() - 1) << '\n';
            return;
        }
        if (input.find('.') != std::string::npos)
        {
            handleDicimal(input);
            return;
        }
        if ((isdigit(input[0]) || input[0] == '+' || input[0] == '-') && isAllDigits(input.substr(1)))
            handleNumeric(input);
        else
            std::cout << "unknown input\n"; 

    }
}
