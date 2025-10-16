#include "Zombie.hpp"

int main()
{
    int N = 5;
    int i = 0;

    Zombie* horde = zombieHorde(N, "walking dead");
    while (i < N)
    {
        horde[i].announce();
        i++;
    }
    delete[] horde;
}
