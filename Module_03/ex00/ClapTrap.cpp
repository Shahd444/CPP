#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "";
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout << "set name constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &old_obj)
{
    std::cout << "Copy constructor called" << std::endl;
    this->name = old_obj.name;
    this->hit_points = old_obj.hit_points;
    this->energy_points = old_obj.energy_points;
    this->attack_damage = old_obj.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &ref)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&ref == this)
        return *this;
    this->name = ref.name;
    this->hit_points = ref.hit_points;
    this->energy_points = ref.energy_points;
    this->attack_damage = ref.attack_damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hit_points != 0 && energy_points != 0)
    {
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << 
            ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points != 0)
    {
        if (amount >= this->hit_points)
            this->hit_points = 0;
        else
            this->hit_points -= amount;
        std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hit_points != 0 && energy_points != 0)
    {
        this->energy_points--;
        this->hit_points += amount;
        std::cout << "ClapTrap " << this->name << " repairs itself, regaining " << amount << " hit points!" << std::endl;
    }
}
