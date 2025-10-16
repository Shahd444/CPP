#include "BitcoinExchange.hpp"


int main(int ac, char** av)
{
  if (ac != 2)
  {
    std::cerr << "Error: wrong number of arguments, try : ./btc input.txt\n";
    return 1;
  }
  BitcoinExchange btc;
  btc.handleData("data.csv");
  btc.handleInput(av[1]);
}