#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    Bureaucrat james("james", 150);
    Bureaucrat lul("lul", 30);
    Bureaucrat bob("bob", 1);

    ShrubberyCreationForm tree("apple tree");
    RobotomyRequestForm robot("robot");
    PresidentialPardonForm pardon("president");

    james.signForm(tree);
    james.signForm(robot);
    james.signForm(pardon);
    lul.signForm(tree);
    lul.signForm(robot);
    lul.signForm(pardon);
    bob.signForm(tree);
    bob.signForm(robot);
    bob.signForm(pardon);

    james.executeForm(tree);
    james.executeForm(robot);
    james.executeForm(pardon);
    lul.executeForm(tree);
    lul.executeForm(robot);
    lul.executeForm(pardon);
    bob.executeForm(tree);
    bob.executeForm(robot);
    bob.executeForm(pardon);

    return 0;
}