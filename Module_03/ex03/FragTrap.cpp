#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    this->name = "";
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}
FragTrap::FragTrap(std::string name) : ClapTrap (name)
{
    this->name = name;
    this->hit_points = 100;
    this->energy_points = 100;
    this->attack_damage = 30;
    std::cout << "FragTrap set name constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &old_obj)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    this->name = old_obj.name;
    this->hit_points = old_obj.hit_points;
    this->energy_points = old_obj.energy_points;
    this->attack_damage = old_obj.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap &ref)
{
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (&ref == this)
        return *this;
    this->name = ref.name;
    this->hit_points = ref.hit_points;
    this->energy_points = ref.energy_points;
    this->attack_damage = ref.attack_damage;
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (hit_points != 0 && energy_points != 0)
    {
        this->energy_points--;
        std::cout << "FragTrap " << this->name << " attacks " << target << 
            ", causing " << this->attack_damage << " points of damage!" << std::endl;
    }
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << this->name << " is requesting a highfive!" << std::endl;
}
int FragTrap::getHitPoints() const
{
    return this->hit_points;
}
int FragTrap::getAttackDamage() const
{
    return this->attack_damage;
}