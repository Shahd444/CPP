#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    num_of_contact = 0;
}

void PhoneBook::addcommand()
{
    int index = num_of_contact % max_contact;
    std::string input;

    do {
        std::cout << "enter first name: ";
        std::getline(std::cin, input);
    } while(!isValidAlpha(input));
    contact[index].setFirstName(input);

    do {
        std::cout << "enter last name: ";
        std::getline(std::cin, input);
    } while(!isValidAlpha(input));
    contact[index].setLastName(input);

    do {
        std::cout << "enter nickname: ";
        std::getline(std::cin, input);
    } while(!isValidAlpha(input));
    contact[index].setNickname(input);

    do {
        std::cout << "enter phone number: ";
        std::getline(std::cin, input);
    } while(!isValidDigit(input));
    contact[index].setPhoneNumber(input);

    do {
        std::cout << "enter darkest secret: ";
        std::getline(std::cin, input);
    } while(input.empty() || hadDigit(input));
    contact[index].setDarkestSecret(input);

    num_of_contact++;
}

void PhoneBook::searchcommand()
{
    std::string input;

    if (num_of_contact == 0)
    {
        std::cout << "no contacts to show, add contacts\n";
        return ;
    }

    for(int i = 0; i < num_of_contact; i++)
    {
        std::string first_name = contact[i].getFirstName();
        std::string last_name = contact[i].getLastName();
        std::string nickname = contact[i].getNickname();

        if(first_name.length() > 10)
            first_name = first_name.substr(0, 9) + '.';
        if(last_name.length() > 10)
            last_name = last_name.substr(0, 9) + '.';
        if(nickname.length() > 10)
            nickname = nickname.substr(0, 9) + '.';
        std::cout << std::setw(5) << i + 1 << " | "
            << std::setw(10) << std::right << first_name << " | "
            << std::setw(10) << std::right << last_name << " | "
            << std::setw(10) << std::right << nickname << std::endl;
    }
    std::cout << "enter index of the contact to view info (1-" << num_of_contact << "): ";
    std::getline(std::cin, input);

    int index =  ft_stoi(input) - 1;
    if (index >= 0 && index < num_of_contact)
    {
        std::cout << "\nFirst name: " << contact[index].getFirstName() << std::endl;
        std::cout << "Last name: " << contact[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contact[index].getNickname() << std::endl;
        std::cout << "Phone number: " << contact[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest secret: " << contact[index].getDarkestSecret() << std::endl;
    }
    else 
    {
        std::cout << "invalid index. enter a valid index between 1 and " << num_of_contact << "." << std::endl;
    }
}