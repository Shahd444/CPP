#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    IMateriaSource* src = new MateriaSource();

    AMateria* ice = new Ice();
    src->learnMateria(ice);
    delete ice;

    AMateria* cure = new Cure();
    src->learnMateria(cure);
    delete cure;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);

    me->unequip(0);

    delete bob;
    delete me;
    delete src;
    return 0;
}