#include <iostream>

int     main(int ac, char **av)
{
        if (ac < 2)
                std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        else
        {
                for(int i = 1; i < ac; i++)
                {
                        std::string input = av[i];
                        for(size_t j = 0; j < input.size(); j++)
                                std::cout << (char)toupper(input[j]);
                }
                std::cout << std::endl;
        }
        return (0);
}