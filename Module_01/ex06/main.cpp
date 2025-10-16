#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
        Harl::filter(av[1]);
    else
        std::cerr << "wrong number of parameters\n";
}
