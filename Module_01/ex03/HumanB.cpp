#include "HumanB.hpp"

HumanB::HumanB(std::string name)
    : name(name), weapon(0)
{

}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon != 0)
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << this->name << " doesn't have a weapon " << std::endl;
}
HumanB::~HumanB()
{

}