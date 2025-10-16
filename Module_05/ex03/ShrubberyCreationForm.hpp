#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm& old_obj);
    ShrubberyCreationForm& operator =(const ShrubberyCreationForm& ref);
    ~ShrubberyCreationForm();
    void execution() const;
};

# endif