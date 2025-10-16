#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: wrong number of arguments\n";
        return 1;
    }
    RPN rpn;
    rpn.handleCalculation(av[1]);
    return 0;
}