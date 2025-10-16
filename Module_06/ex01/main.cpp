#include "Serializer.hpp"

int main()
{
    Data data;

    data.num = 1;
    data.str = "hello";

    std::cout << &data << '\n';

    uintptr_t raw = Serializer::serialize(&data);

    Data *ptr = Serializer::deserialize(raw);

    std::cout << "ptr: " << ptr << '\n';
    std::cout << "data address: " << &data << '\n';
    std::cout << "ptr num: " << ptr->num << '\n';
    std::cout << "data num: " << data.num << '\n';
    std::cout << "ptr str: " << ptr->str << '\n';
    std::cout << "data str: " << data.str << '\n';

    return 0;
}