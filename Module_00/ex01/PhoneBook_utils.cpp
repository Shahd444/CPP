#include "main.hpp"

int ft_stoi(const std::string str)
{
    int res = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
        {
            res = res * 10 + (str[i] - '0');
        }
        else 
        {
            std::cout << "invalid index, please enter only digits";
            return (-1);
        }
    }
    return (res);
}

bool isValidAlpha(std::string& str)
{
    bool has_alpha = false;

    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isspace(str[i]) && !std::isalpha(str[i]))
            return (false);
        if (std::isalpha(str[i]))
            has_alpha = true;
    }
    return (has_alpha);
}

bool isValidDigit(std::string& str)
{
    bool has_digit = false;

    if (str.empty())
        return (false);
    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isspace(str[i]) && !std::isdigit(str[i]))
            return (false);
        if (std::isdigit(str[i]))
            has_digit = true;
    }
    return (has_digit);
}

bool hadDigit(std::string& str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            return (true);
    }
    return (false);
}