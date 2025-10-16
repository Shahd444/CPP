#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>


struct Data
{
    int num;
    std::string str;
};


class Serializer
{
private:
    Serializer();
    Serializer (const Serializer& old_obj);
    Serializer& operator =(const Serializer& ref);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};


# endif