#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
    std::string target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& old_obj);
    PresidentialPardonForm& operator =(const PresidentialPardonForm& ref);
    ~PresidentialPardonForm();
    void execution() const;
};

# endif