#include "Intern.hpp"

Intern::Intern()
{
    
}

Intern::Intern(const Intern& old_obj)
{
    (void)old_obj;    
}

Intern &Intern::operator=(const Intern& ref)
{
    (void)ref;
    if (&ref == this)
        return *this;
    return *this;
}

const char* Intern::UnknownForm::what() const throw()
{
    return ("unknown form name.\n");
}

Intern::~Intern()
{

}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string knownNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    AForm* (*createForms[3])(const std::string&) = {&Intern::Shrubbery, &Intern::Robot, &Intern::President};

    for(int i = 0; i < 3; i++)
    {
        if(formName == knownNames[i])
        {
            std::cout << "Intern creates " << formName <<'\n';
            return createForms[i](target);
        }
    }
    throw UnknownForm();
}

AForm* Intern::Shrubbery(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::Robot(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::President(const std::string& target)
{
    return new PresidentialPardonForm(target);
}
