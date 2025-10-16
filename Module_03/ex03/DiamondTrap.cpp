#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
    : ClapTrap("default name"), ScavTrap(), FragTrap()
{
    this->name = "default";
    this->hit_points = getHitPoints();
    this->energy_points = getEnergyPoints();
    this->attack_damage = getAttackDamage();
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hit_points = getHitPoints();
    this->energy_points = getEnergyPoints();
    this->attack_damage = getAttackDamage();
    std::cout << "DiamondTrap name constructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap &old_obj)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    this->name = old_obj.name;
    this->hit_points = old_obj.hit_points;
    this->energy_points = old_obj.energy_points;
    this->attack_damage = old_obj.attack_damage;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &ref)
{
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (&ref == this)
        return *this;
    this->name = ref.name;
    this->hit_points = ref.hit_points;
    this->energy_points = ref.energy_points;
    this->attack_damage = ref.attack_damage;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}
void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name is " << this->name << " ClapTrap name is " << ClapTrap::getName() << std::endl;;
}