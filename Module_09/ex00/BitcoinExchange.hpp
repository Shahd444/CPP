#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
private:
  std::map<std::string, double> data_map;
  std::map<std::string, double>::iterator it;
  double exchange;

public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange& old_obj);
  BitcoinExchange& operator=(const BitcoinExchange& ref);
  ~BitcoinExchange();

  void handleData(const std::string& filename);
  void handleInput(const std::string& filename);
  void handleOutput(std::string date, double amount);

};

# endif