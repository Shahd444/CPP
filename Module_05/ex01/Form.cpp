#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    :name(""), sign(false), grade_s(150), grade_e(150)
{

}
Form::Form(std::string name ,int grade_s, int grade_e)
    :name(name), sign(false), grade_s(grade_s), grade_e(grade_e)
{
    if (grade_s < 1 || grade_e < 1)
        throw Form::GradeTooHighException();
    if (grade_s > 150 || grade_e > 150)
        throw Form::GradeTooLowException();

}
Form::Form(const Form& old_obj)
    :name(old_obj.name), sign(old_obj.sign), grade_s(old_obj.grade_s), grade_e(old_obj.grade_e)
{

}
Form& Form::operator=(const Form& ref)
{
    if (&ref == this)
        return *this;
    this->sign = ref.sign;
    return *this;
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->sign;
}

int Form::getSignGrade() const
{
    return this->grade_s;
}

int Form::getExecGrade() const
{
    return this->grade_e;
}

Form::~Form()
{

}
const char* Form::GradeTooHighException::what() const throw()
{
    return ("grade is too high!\n");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("grade is too low!\n");
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() <= grade_s)
    {
        sign = true;
    }
    else
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
    return out << "Form name: " << obj.getName() << ", signed status: " << std::boolalpha << obj.getSign() << ", grade to sign it: " << obj.getSignGrade() << ", grade to execute it: " << obj.getExecGrade() << '\n';
}