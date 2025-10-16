#include " Zombie.hpp"

int main()
{
    Zombie* one = newZombie("yoshi");
    Zombie* two = newZombie("mario");
    one->announce();
    two->announce();
    randomChump("luigi");
    randomChump("peach");
    delete(one);
    delete(two);
}
