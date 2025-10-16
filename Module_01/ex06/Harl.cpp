#include "Harl.hpp"

void    Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}
void     Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}
void    Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n";
}
void     Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}
Harl::Harl()
{}
Harl::~Harl()
{}
void    Harl::filter(const std::string input)
{
    Harl harl;

    int type = -1;
    std::string types[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (input == types[i])
        {
            type = i;
            break;
        }
    }
    switch (type)
    {
    case 0:
        harl.debug();
    case 1:
        harl.info();
    case 2:
       harl.warning();
    case 3:
        harl.error();
        break;
    default:
        std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}
