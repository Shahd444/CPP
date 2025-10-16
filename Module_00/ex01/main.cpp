#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    std::string input;

    while (1)
    {
        std::cout << "enter a command ADD SEARCH EXIT: ";
        std::getline(std::cin, input);
        if (input == "ADD")
            phonebook.addcommand();
        else if (input == "SEARCH")
            phonebook.searchcommand();
        else if (input == "EXIT")
        {
            std::cout << "Exit\n";
            break;
        }
        else
            std::cout << "this command doesn't exist.\n";
    }
    
}
