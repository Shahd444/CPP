#include "FragTrap.hpp"

int main(void)
{
    ClapTrap Bob("Bob");
    FragTrap frog("frog");

    Bob.attack("enemy");
    Bob.takeDamage(5);
    Bob.beRepaired(2);

    frog.attack("enemy");
    frog.takeDamage(8);
    frog.beRepaired(3);
    frog.highFivesGuys();
}
