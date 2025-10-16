#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat james("James", 200);
        james.incrementGrade();
        james.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Bureaucrat lul("lul", 0);
        lul.incrementGrade();
        lul.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    return 0;
}
