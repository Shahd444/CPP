#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
  exchange = -1;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& old_obj)
{
  *this = old_obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& ref)
{
  if (this != &ref)
    this->data_map = ref.data_map;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}


bool validate_date(std::string date)
{
  if (date.size() != 10)
    return 1;
  if (date[4] != '-' || date[7] != '-')
    return 1;
  std::string year = date.substr(0, 4);
  std::string month = date.substr(5, 2);
  std::string day = date.substr(8, 2);

  std::stringstream ssy(year);
  std::stringstream ssm(month);
  std::stringstream ssd(day);

  int year_v;
  int month_v;
  int day_v;

  if (!(ssy >> year_v) || !(ssm >> month_v) || !(ssd >> day_v))
    return 1;
  if (year_v < 2009)
    return 1;
  if (month_v < 01 || month_v > 12)
    return 1;
  if (day_v < 01 || day_v > 31)
    return 1;
  if ((month_v == 4 || month_v == 6 || month_v == 9 || month_v == 11) && day_v > 30)
    return 1;
  if (month_v == 2 && day_v > 28)
    return 1;
  return 0;
}

std::string trim(const std::string& str)
{
  size_t start = str.find_first_not_of(" \t");
  size_t end = str.find_last_not_of(" \t");
  if (start == std::string::npos)
    return "";
  return str.substr(start, end - start + 1);
}


void BitcoinExchange::handleData(const std::string& filename)
{
  std::ifstream datafile(filename.c_str());
  if (!datafile)
  {
    std::cerr << "couldn't open file\n";
    exit(1);
  }
  std::string line;
  std::getline(datafile, line);
  while (std::getline(datafile, line))
  {
    size_t sep = line.find(',');
    if (sep == std::string::npos)
      continue;
    std::string date = line.substr(0, sep);
    std::string val = line.substr(sep + 1);
    val = trim(val);
    std::stringstream ss(val);
    double value;
    ss >> value;
    data_map.insert(std::make_pair(date, value));
  }
}

void BitcoinExchange::handleInput(const std::string& filename)
{
  std::ifstream infile(filename.c_str());
  if (!infile)
  {
    std::cerr << "couldn't open file\n";
    exit(1);
  }
  std::string line;
  std::getline(infile, line);
  std::string first_line = trim(line);
  if (first_line != "date | value")
  {
    std::cerr << "Error: first line must be date | value\n";
    exit(1);
  }
  while(std::getline(infile, line))
  {
    size_t sep = line.find('|');
    if (sep == std::string::npos)
    {
      std::cerr << "Error: bad input => " << line << "\n";
      continue;
    }
    std::string date = line.substr(0, sep);
    date = trim(date);
    if (validate_date(date) == 1)
    {
      std::cerr << "Error: bad input => " << date << "\n";
      continue;
    }  
    std::string val = line.substr(sep + 1);
    val = trim(val);
    std::stringstream ss(val);
    double amount;
    ss >> amount;

    if (amount < 0)
    {
      std::cerr << "Error: not a positive number.\n";
      continue;
    }
    if (amount > 1000)
    {
      std::cerr << "Error: too large a number.\n";
      continue;
    }

    handleOutput(date, amount);
  }
}

void BitcoinExchange::handleOutput(std::string date, double amount)
{
  for (it = data_map.begin(); it != data_map.end(); ++it)
  {
    if (it->first > date)
      break;
    exchange = it->second;
  }
  if (exchange < 0)
  {
    std::cerr << "Error: invalid value for " << date << "\n";
    return;
  }
  double res = amount * exchange;
  std::cout << date << " => " << amount << " = " << res << "\n";
}