#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
private:
    static AForm* Shrubbery(const std::string& target);
    static AForm* Robot(const std::string& target);
    static AForm* President(const std::string& target);

public:
    Intern();
    Intern(const Intern& old_obj);
    Intern& operator =(const Intern& ref);
    ~Intern();
    AForm *makeForm(const std::string& formName, const std::string& target);

    class UnknownForm : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

# endif