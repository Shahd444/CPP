#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    srand(time(NULL));

    Intern employee;
    AForm* ref = NULL;

    ShrubberyCreationForm tree("apple tree");
    RobotomyRequestForm robot("robot");
    PresidentialPardonForm pardon("president");

    try
    {
        ref = employee.makeForm("ShrubberyCreationForm", "Bender");
        delete ref;
        ref = employee.makeForm("RobotomyRequestForm", "Bender");
        delete ref;
        ref = employee.makeForm("PresidentialPardonForm", "Bender");
        delete ref;
        ref = employee.makeForm("wrongform", "Bender");
        delete ref;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what();
    }

    return 0;
}