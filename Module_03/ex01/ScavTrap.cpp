#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    this->name = "";
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}
ScavTrap::ScavTrap(std::string name) : ClapTrap (name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 50;
    this->attack_damage = 20;
    std::cout << "ScavTrap set name constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &old_obj)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    this->name = old_obj.name;
    this->hit_points = old_obj.hit_points;
    this->energy_points = old_obj.energy_points;
    this->attack_damage = old_obj.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &ref)
{
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (&ref == this)
        return *this;
    this->name = ref.name;
    this->hit_points = ref.hit_points;
    this->energy_points = ref.energy_points;
    this->attack_damage = ref.attack_damage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (hit_points != 0 && energy_points != 0)
    {
        this->energy_points--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << 
            ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}
void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in gate keeper mode" << std::endl;
}