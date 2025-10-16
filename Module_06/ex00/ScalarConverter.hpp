#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream> // input output op
#include <cstdlib> // strtoll
#include <limits> // INT_MIN, INT_MAX
#include <string> // string
#include <cctype> // isdigit
#include <iomanip> // std::fixed and std::setprecision
#include <cfloat> // FLT_MAX
#include <climits> // INT_MIN, INT_MAX

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter (const ScalarConverter& old_obj);
    ScalarConverter& operator =(const ScalarConverter& ref);
    ~ScalarConverter();
public:
    static void convert(std::string const &input);

};

void handleSpace(char c);
void handlePrintable(char c);
void handleNumeric(std::string const & input);
bool isAllDigits(std::string const & input);
void handleDicimal(std::string const & input);

# endif
