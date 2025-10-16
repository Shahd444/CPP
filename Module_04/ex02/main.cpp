#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    // Animal animal;
    // animal.makeSound();
    delete j;
    delete i;
    std::cout << "-------------------------------------------\n";
    int num = 4;
    Animal* animal[num];
    for(int x = 0; x < num; x++)
    {
        if (x % 2 == 0)
        {
            std::cout << x << "\n";
            animal[x] = new Dog();
        }
        else
        {
            std::cout << x << "\n";
            animal[x] = new Cat();
        }
    }
    for(int y = 0; y < num; y++)
    {
        std::cout << y << "\n";
        delete animal[y];
    }
    return 0;
}
