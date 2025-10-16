#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

struct C_struct
{
    AMateria* node;
    C_struct* next;
};


class Character : public ICharacter
{
private:
    std::string name;
    AMateria* material[4];
    C_struct* head;
public:
    Character();
    Character(std::string name);
    Character(const Character &old_obj);
    Character& operator=(const Character &ref);
    ~Character();
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    void clear();
};

# endif