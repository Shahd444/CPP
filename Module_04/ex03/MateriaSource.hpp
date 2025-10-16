#ifndef MATERIASOURCE
# define MATERIASOURCE

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria* arr[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource &old_obj);
    MateriaSource& operator=(const MateriaSource &ref);
    virtual ~MateriaSource();
    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

# endif