#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->arr[i] = NULL;
    std::cout << "MateriaSource default constructor called\n";
}

MateriaSource::MateriaSource(const MateriaSource &old_obj)
{
    for (int i = 0; i < 4; i++)
    {
        if(old_obj.arr[i] != NULL)
            this->arr[i] = old_obj.arr[i]->clone();
        else
            this->arr[i] = NULL;
    }
    std::cout << "MateriaSource copy constructor called\n";
}
MateriaSource& MateriaSource::operator=(const MateriaSource &ref)
{
    if (&ref == this)
        return *this;
    for (int i = 0; i < 4; i++)
    {
        if(ref.arr[i] != NULL)
        {
            delete this->arr[i];
            this->arr[i] = ref.arr[i]->clone();
        }
        else
            this->arr[i] = NULL;
    }
    return *this;
}
MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        delete this->arr[i];
    std::cout << "MateriaSource destructor called\n";
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == NULL)
        return ;
    for (int i = 0; i < 4; i++)
    {
        if (this->arr[i] == NULL)
        {
            this->arr[i] = m->clone();
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4 ; i++)
    {
        if (this->arr[i] != NULL && this->arr[i]->getType() == type)
            return arr[i]->clone();
    }
    return NULL;
}

