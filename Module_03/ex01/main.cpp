#include "ScavTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    ScavTrap minion("minion");

    Bob.attack("enemy");
    Bob.takeDamage(5);
    Bob.beRepaired(2);

    minion.attack("enemy");
    minion.takeDamage(5);
    minion.beRepaired(2);
    minion.guardGate();
}
