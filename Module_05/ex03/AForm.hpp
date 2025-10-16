#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool sign;
    const int grade_s;
    const int grade_e;
    
public:
    AForm();
    AForm(const std::string name ,int grade_s, int grade_e);
    AForm(const AForm &old_obj);
    AForm& operator =(const AForm &ref);
    std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    virtual ~AForm();
    void beSigned(const Bureaucrat& b);
    void execute(Bureaucrat const& executor) const;
    virtual void execution() const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw(); 
    };
    
    class FormNotSignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);


# endif