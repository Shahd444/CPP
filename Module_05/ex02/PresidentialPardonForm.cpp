#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    :target("default")
{

}
PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm ("PresidentialPardonForm", 25, 5), target(target)
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& old_obj)
    :AForm (old_obj), target(old_obj.target)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
    if (&ref == this)
        return *this;
    this->target = ref.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::execution() const
{
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox\n";
}