#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &old_obj);
    Bureaucrat& operator =(const Bureaucrat &ref);
    ~Bureaucrat();
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form& f);

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& obj);

# endif
