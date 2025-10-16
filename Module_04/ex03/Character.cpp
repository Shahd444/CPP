#include "Character.hpp"

Character::Character()
{
    head = NULL;
    std::cout << "Character default constructor called\n";
}

Character::Character(std::string name)
{
    head = NULL;
    this->name = name;
    for(int i = 0; i < 4; i++)
        material[i] = NULL;
    std::cout << "Character type set constructor called\n";
}
Character::Character(const Character &old_obj)
{
    head = NULL;
    this->name = old_obj.name;
    for (int i = 0; i < 4; i++)
    {
        if(old_obj.material[i] != NULL)
            this->material[i] = old_obj.material[i]->clone();
        else
            this->material[i] = NULL;
    }
    std::cout << "Character copy constructor called\n";
}
Character& Character::operator=(const Character &ref)
{
    if (&ref == this)
        return *this;
    clear();
    this->name = ref.name;
    for (int i = 0; i < 4; i++)
    {
        if(ref.material[i] != NULL)
        {
            delete this->material[i];
            this->material[i] = ref.material[i]->clone();
        }
        else
            this->material[i] = NULL;
    }
    return *this;
}

void Character::clear()
{
    C_struct* current = head;
    while (current != NULL)
    {
        C_struct* next_node = current->next;
        delete current->node;
        delete current;
        current = next_node;
    }
    head = NULL;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        if (material[i] != NULL)
            delete material[i];
    }
    clear();
    std::cout << "Character destructor called\n";
}
std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (m == NULL)
        return;
    for (int i = 0; i < 4; i++)
    {
        if (this->material[i] == NULL)
        {
            material[i] = m;
            break;
        }
    }
}
void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || this->material[idx] == NULL)
        return;
    C_struct *new_node = new C_struct;
    new_node->node = this->material[idx];
    new_node->next = head;
    head = new_node;
    this->material[idx] = NULL;
}
void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx <= 3 && this->material[idx] != NULL)
        this->material[idx]->use(target);
}