#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{ 
public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(const FragTrap &old_obj);
    FragTrap& operator=(const FragTrap &ref);
    ~FragTrap();
    void attack(const std::string& target);
    void highFivesGuys(void);
    int getHitPoints() const;
    int getAttackDamage() const;
};

# endif