#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <stdbool.h>
#include <exception>
// #include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool sign;
    const int grade_s;
    const int grade_e;
    
public:
    Form();
    Form(std::string name ,int grade_s, int grade_e);
    Form(const Form &old_obj);
    Form& operator =(const Form &ref);
    std::string getName() const;
    bool getSign() const;
    int getSignGrade() const;
    int getExecGrade() const;
    ~Form();
    void beSigned(const Bureaucrat& b);

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
    
};

std::ostream& operator<<(std::ostream& out, const Form& obj);


# endif