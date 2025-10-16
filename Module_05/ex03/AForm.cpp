#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    :name(""), sign(false), grade_s(150), grade_e(150)
{

}
AForm::AForm(std::string name ,int grade_s, int grade_e)
    :name(name), sign(false), grade_s(grade_s), grade_e(grade_e)
{
    if (grade_s < 1 || grade_e < 1)
        throw AForm::GradeTooHighException();
    if (grade_s > 150 || grade_e > 150)
        throw AForm::GradeTooLowException();

}
AForm::AForm(const AForm& old_obj)
    :name(old_obj.name), sign(old_obj.sign), grade_s(old_obj.grade_s), grade_e(old_obj.grade_e)
{

}
AForm& AForm::operator=(const AForm& ref)
{
    if (&ref == this)
        return *this;
    this->sign = ref.sign;
    return *this;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getSign() const
{
    return this->sign;
}

int AForm::getSignGrade() const
{
    return this->grade_s;
}

int AForm::getExecGrade() const
{
    return this->grade_e;
}

AForm::~AForm()
{

}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("grade is too high!\n");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("grade is too low!\n");
}

const char* AForm::FormNotSignedException::what() const throw()
{
    return ("form not signed!\n");
}

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= grade_s)
    {
        sign = true;
    }
    else
        throw AForm::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
    return out << "Form name: " << obj.getName() << ", signed status: " << std::boolalpha << obj.getSign() << ", grade to sign it: " << obj.getSignGrade() << ", grade to execute it: " << obj.getExecGrade() << '\n';
}

void AForm::execute(Bureaucrat const& executor) const
{
    if (!getSign())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    this->execution();
}