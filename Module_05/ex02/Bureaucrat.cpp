#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
    :name("")
{
    this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
    :name(name)
{
    this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

std::string Bureaucrat::getName() const
{
    return this->name;
}

Bureaucrat::Bureaucrat(const Bureaucrat &old_obj)
 :name(old_obj.name)
{
    this->grade = old_obj.grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &ref)
{
    if (&ref == this)
        return *this;
    this->grade = ref.grade;
    return *this;    
}

void Bureaucrat::incrementGrade()
{
    if (this->grade - 1 < 1)
    {
        throw Bureaucrat::GradeTooHighException();
    }
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade + 1 > 150)
    {
        throw Bureaucrat::GradeTooLowException();
    }
    this->grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("grade too low!");
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj)
{
    return out << obj.getName() << ", bureaucrat grade " << obj.getGrade();
}

void Bureaucrat::signForm(AForm& f)
{
    try
    {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't sign " << f.getName() << " because " <<e.what() << '\n';
    }
}

void Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << '\n';
    }
    catch(const std::exception& e)
    {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << '\n';
    }
}