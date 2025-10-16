# ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <iomanip>
// #include <sys/time.h>

class PmergeMe
{
private:
  std::vector<int> vector_num;
  std::vector<int> vector_big;
  std::vector<int> vector_small;
  int vector_leftover;
  std::deque<int> deque_num;
  std::deque<int> deque_big;
  std::deque<int> deque_small;
  int deque_leftover;
  bool digitCheck(std::string num);

public:
  PmergeMe();
  PmergeMe(const PmergeMe& old_obj);
  PmergeMe& operator=(const PmergeMe& ref);
  ~PmergeMe();

  void handleInput(int ac, char** av);
  void sortVector();
  std::vector<int> recursiveVector(std::vector<int>& main_chain);
  void insertSmallVector();
  void insertLeftoverVector();
  void groupPairsVector(const std::vector<int>& vector_num, std::vector<int>& vector_small, std::vector<int>& vector_big, int& leftover);
  void printVector(const std::vector<int>& vector_num);

  void sortDeque();
  std::deque<int> recursiveDeque(std::deque<int>& main_chain);
  void insertSmallDeque();
  void insertLeftoverDeque();
  void groupPairsDeque(const std::deque<int>& deque_num, std::deque<int>& deque_small, std::deque<int>& deque_big, int& leftover);
  void printDeque(const std::deque<int>& deque_num);
};



#endif