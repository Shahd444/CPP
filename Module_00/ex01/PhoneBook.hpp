#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP
#include "main.hpp"
#include "Contact.hpp"

class PhoneBook
{
private:
    static const int max_contact = 8;
    Contact contact[max_contact];
    int num_of_contact;
public:
    PhoneBook();
    void addcommand();
    void searchcommand();
};

#endif