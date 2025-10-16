#include "Bureaucrat.hpp"

int main()
{
    try
    {
       Form paper("paper", -1, 0);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    try
    {
        Form form("form", 5, 12);
        Bureaucrat james("James", 2);
        james.signForm(form);
        std::cout << form;
        Bureaucrat lul("lul", 15);
        lul.signForm(form);
        std::cout << form;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
