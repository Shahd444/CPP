#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :target("default")
{

}
RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm ("RobotomyRequestForm", 72, 45), target(target)
{

}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& old_obj)
    :AForm (old_obj), target(old_obj.target)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
    if (&ref == this)
        return *this;
    this->target = ref.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void RobotomyRequestForm::execution() const
{
    std::cout << "some drilling noises\n";
    int res = rand() % 2;
    if (res == 1)
        std::cout << this->target << " has been robotomized\n";
    else
        std::cout << this->target << " robotomy failed\n";  
}