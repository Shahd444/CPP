#include "PmergeMe.hpp"

int main(int ac, char **av)
{
  if (ac < 2)
  {
    std::cerr << "wrong number of arguments\n";
    return 1;
  }
  PmergeMe merge;

  merge.handleInput(ac, av);
  
  return 0;
}