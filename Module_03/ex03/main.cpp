#include "DiamondTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    DiamondTrap diamond("diamond");

    Bob.attack("enemy");
    Bob.takeDamage(5);
    Bob.beRepaired(2);

    diamond.attack("enemy");
    diamond.takeDamage(8);
    diamond.beRepaired(3);
    diamond.whoAmI();
}
