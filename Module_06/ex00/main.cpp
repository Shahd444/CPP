#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    (void)av;
    if (ac != 2)
        std::cout << "try: ./ScalarConvetrer string\n";
    else 
    {
        std::string input(av[1]);
        ScalarConverter::convert(input);
    }
    return 0;
}