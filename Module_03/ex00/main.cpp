#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");

    Bob.attack("enemy");
    Bob.takeDamage(5);
    Bob.beRepaired(2);
}
