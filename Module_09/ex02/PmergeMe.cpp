#include "PmergeMe.hpp"

PmergeMe::PmergeMe() 
{
  vector_leftover = -1;
  deque_leftover = -1;
}

PmergeMe::PmergeMe(const PmergeMe& old_obj)
{
  *this = old_obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& ref)
{
  if (this != &ref)
  {
    this->vector_num = ref.vector_num;
    this->vector_big = ref.vector_big;
    this->vector_small = ref.vector_small;
    this->vector_leftover = ref.vector_leftover;
    this->deque_num = ref.deque_num;
    this->deque_big = ref.deque_big;
    this->deque_small = ref.deque_small;
    this->deque_leftover = ref.deque_leftover;
  }
  return *this;
}

PmergeMe::~PmergeMe() {}

bool PmergeMe::digitCheck(std::string num)
{
  for (std::string::size_type i = 0; i < num.length(); i++)
  {
    if (!isdigit(num[i]))
      return 1;
  }
  return 0;
}

void PmergeMe::handleInput(int ac, char** av)
{
  for(int i = 1; i < ac; i++)
  {
    if(digitCheck(av[i]) == 1)
    {
      std::cerr << "Error\n";
      exit(1);
    }
    std::stringstream ss(av[i]);
    int num;
    ss >> num;
    if (num < 0)
    {
      std::cerr << "Error\n";
      exit(1);
    }
    vector_num.push_back(num);
    deque_num.push_back(num);
  }

  std::cout << "Before: ";
  printVector(vector_num);
  // printDeque(deque_num);


  clock_t vector_start = clock(); // measure CPU time
  sortVector();
  clock_t vector_end = clock();

  clock_t deque_start = clock();
  sortDeque();
  clock_t deque_end = clock();
  
  std::cout << "After: ";
  printVector(vector_num);
  // printDeque(deque_num);
  
  double vector_time = (double)(vector_end - vector_start) * 1000000 / CLOCKS_PER_SEC;
  double deque_time = (double)(deque_end - deque_start) * 1000000 / CLOCKS_PER_SEC;

  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << vector_num.size() << " elements with std::vector : " << vector_time << " us\n";
  std::cout << std::fixed << std::setprecision(5);
  std::cout << "Time to process a range of " << deque_num.size() << " elements with std::deque : " << deque_time << " us\n";
}

void PmergeMe::printVector(const std::vector<int>& vector_num)
{
  for (std::string::size_type i = 0; i < vector_num.size(); i++)
    std::cout << vector_num[i] << " ";
  std::cout << '\n';
}

void PmergeMe::sortVector()
{
  vector_big.clear();
  vector_small.clear();
  vector_leftover = -1;

  groupPairsVector(vector_num, vector_small, vector_big, vector_leftover);
  vector_big = recursiveVector(vector_big);
  insertSmallVector();
  insertLeftoverVector();
  vector_num = vector_big;
}

void PmergeMe::groupPairsVector(const std::vector<int>& vector_num, std::vector<int>& vector_small, std::vector<int>& vector_big, int& vector_leftover)
{
  for (std::string::size_type i = 0; i + 1 < vector_num.size(); i += 2)
  {
    int first = vector_num[i];
    int second = vector_num[i + 1];

    if (first > second)
    {
      vector_big.push_back(first);
      vector_small.push_back(second);
    }
    else
    {
      vector_big.push_back(second);
      vector_small.push_back(first);
    }
  }
  if (vector_num.size() % 2 != 0)
    vector_leftover = vector_num.back();
  else
    vector_leftover = -1;
}

std::vector<int> PmergeMe::recursiveVector(std::vector<int>& main_chain)
{
  if (main_chain.size() <= 1)
    return main_chain;

  if (main_chain.size() == 2) {
    if (main_chain[0] > main_chain[1])
      std::swap(main_chain[0], main_chain[1]);
    return main_chain;
  }

  std::vector<int> main_small;
  std::vector<int> main_big;
  int leftover = -1;

  for (std::size_t i = 0; i + 1 < main_chain.size(); i += 2)
  {
    if (main_chain[i] > main_chain[i + 1])
    {
      main_big.push_back(main_chain[i]);
      main_small.push_back(main_chain[i + 1]);
    }
    else
    {
      main_small.push_back(main_chain[i]);
      main_big.push_back(main_chain[i + 1]);
    }
  }
  if (main_chain.size() % 2 != 0)
    leftover = main_chain.back();
    
  main_big = recursiveVector(main_big);

  for (size_t i = 0; i < main_small.size(); i++)
  {
    int x = main_small[i];
    std::size_t start = 0;
    std::size_t end = main_big.size();

    while (start < end)
    {
      std::size_t middle = (start + end) / 2;
      if (x < main_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    main_big.insert(main_big.begin() + start, x);
  }

  if (leftover != -1)
  {
    int x = leftover;
    std::size_t start = 0;
    std::size_t end = main_big.size();

    while (start < end)
    {
      std::size_t middle = (start + end) / 2;
      if (x < main_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    main_big.insert(main_big.begin() + start, x);
  }

  return main_big;
}

std::vector<int> JacobsthalVector(int num)
{
    std::vector<int> pattern;
    if (num <= 1) 
        return pattern;

    int J_prev = 1;
    int J_curr = 3;
    
    std::vector<int> J_indices;
    J_indices.push_back(1); 
    
    while (J_curr < num)
    {
        J_indices.push_back(J_curr);
        int J_next = J_curr + 2 * J_prev;
        J_prev = J_curr;
        J_curr = J_next;
    }
    int prev_idx = 0;
    
    for (size_t k = 0; k < J_indices.size(); k++)
    {
        int current_idx_1based = J_indices[k];
        int current_idx = current_idx_1based - 1; // 0 based index

        if (current_idx >= num)
            current_idx = num - 1; 

        // Insert backwards from current_idx to prev_idx + 1
        for (int i = current_idx; i > prev_idx; --i)
        {
            if (i < num)
            {
                pattern.push_back(i);
            }
        }
        prev_idx = current_idx;
        // Check if cover full range
        if (current_idx_1based >= num)
            break;
    }
    
    // Add remaining indices
    if (prev_idx < num - 1)
    {
        for (int i = num - 1; i > prev_idx; --i)
            pattern.push_back(i);
    }
    return pattern;
}

void PmergeMe::insertSmallVector()
{
  if(vector_small.empty())
    return;

  int first_small = vector_small[0];
  
  std::size_t start = 0;
  std::size_t end = vector_big.size();
  std::size_t middle;

  while (start < end)
  {
    middle = (start + end) / 2;
    if (first_small < vector_big[middle])
      end = middle;
    else
      start = middle + 1;
  }
  vector_big.insert(vector_big.begin() + start, first_small);

  std::vector<int> pattern = JacobsthalVector(vector_small.size());
  for (std::size_t i = 0; i < pattern.size(); i++)
  {
    std::string::size_type y = pattern[i]; 
    if (y >= vector_small.size())
      continue;
      
    int x = vector_small[y];
  
    start = 0;
    middle = 0;
    end = vector_big.size(); 

    while (start < end)
    {
      middle = (start + end) / 2;
      if (x < vector_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    vector_big.insert(vector_big.begin() + start, x);
  }  
}

void PmergeMe::insertLeftoverVector()
{
  if (vector_leftover == -1)
    return;

  std::size_t start = 0;
  std::size_t middle = 0;
  std::size_t end = vector_big.size();

  while (start < end)
  {
    middle = (start + end) / 2;
    if (vector_leftover < vector_big[middle])
      end = middle;
    else
      start = middle + 1;
  }
  vector_big.insert(vector_big.begin() + start, vector_leftover);
  vector_leftover = -1;
}





void PmergeMe::printDeque(const std::deque<int>& deque_num)
{
  for (std::string::size_type i = 0; i < deque_num.size(); i++)
    std::cout << deque_num[i] << " ";
  std::cout << '\n';
}

void PmergeMe::sortDeque()
{
  deque_big.clear();
  deque_small.clear();
  deque_leftover = -1;

  groupPairsDeque(deque_num, deque_small, deque_big, deque_leftover);
  deque_big = recursiveDeque(deque_big);
  insertSmallDeque();
  insertLeftoverDeque();
  deque_num = deque_big;
}

void PmergeMe::groupPairsDeque(const std::deque<int>& deque_num, std::deque<int>& deque_small, std::deque<int>& deque_big, int& deque_leftover)
{
    for (std::string::size_type  i = 0; i + 1 < deque_num.size(); i += 2)
    {
        int first = deque_num[i];
        int second = deque_num[i + 1];

        if (first > second)
        {
            deque_big.push_back(first);
            deque_small.push_back(second);
        }
        else
        {
            deque_big.push_back(second);
            deque_small.push_back(first);
        }
    }
    if (deque_num.size() % 2 != 0)
        deque_leftover = deque_num.back();
    else
        deque_leftover = -1;
}

std::deque<int> PmergeMe::recursiveDeque(std::deque<int>& main_chain)
{
  if (main_chain.size() <= 1)
    return main_chain;

  if (main_chain.size() == 2) {
    if (main_chain[0] > main_chain[1])
      std::swap(main_chain[0], main_chain[1]);
    return main_chain;
  }

  std::deque<int> main_small;
  std::deque<int> main_big;
  int leftover = -1;

  for (std::size_t i = 0; i + 1 < main_chain.size(); i += 2)
  {
    if (main_chain[i] > main_chain[i + 1])
    {
      main_big.push_back(main_chain[i]);
      main_small.push_back(main_chain[i + 1]);
    }
    else
    {
      main_small.push_back(main_chain[i]);
      main_big.push_back(main_chain[i + 1]);
    }
  }
  if (main_chain.size() % 2 != 0)
    leftover = main_chain.back();
    
  main_big = recursiveDeque(main_big);

  for (size_t i = 0; i < main_small.size(); i++)
  {
    int x = main_small[i];
    std::size_t start = 0;
    std::size_t end = main_big.size();

    while (start < end)
    {
      std::size_t middle = (start + end) / 2;
      if (x < main_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    main_big.insert(main_big.begin() + start, x);
  }

  if (leftover != -1)
  {
    int x = leftover;
    std::size_t start = 0;
    std::size_t end = main_big.size();

    while (start < end)
    {
      std::size_t middle = (start + end) / 2;
      if (x < main_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    main_big.insert(main_big.begin() + start, x);
  }

  return main_big;
}

std::deque<int> JacobsthalDeque(int num)
{
    std::deque<int> pattern;
    if (num <= 1) 
        return pattern;

    int J_prev = 1;
    int J_curr = 3;
    
    std::deque<int> J_indices;
    J_indices.push_back(1); 
    
    while (J_curr < num)
    {
        J_indices.push_back(J_curr);
        int J_next = J_curr + 2 * J_prev;
        J_prev = J_curr;
        J_curr = J_next;
    }

    int prev_idx = 0;
    
    for (size_t k = 0; k < J_indices.size(); k++)
    {
        int current_idx_1based = J_indices[k];
        int current_idx = current_idx_1based - 1;

        if (current_idx >= num)
            current_idx = num - 1; 

        for (int i = current_idx; i > prev_idx; --i)
        {
            if (i < num)
            {
                pattern.push_back(i);
            }
        }
        prev_idx = current_idx;
        if (current_idx_1based >= num)
            break;
    }

    if (prev_idx < num - 1)
    {
        for (int i = num - 1; i > prev_idx; --i)
            pattern.push_back(i);
    }
    return pattern;
}

void PmergeMe::insertSmallDeque()
{
  if(deque_small.empty())
    return;

  int first_small = deque_small[0];
  
  std::size_t start = 0;
  std::size_t end = deque_big.size();
  std::size_t middle;

  while (start < end)
  {
    middle = (start + end) / 2;
    if (first_small < deque_big[middle])
      end = middle;
    else
      start = middle + 1;
  }
  deque_big.insert(deque_big.begin() + start, first_small);

  std::deque<int> pattern = JacobsthalDeque(deque_small.size());
  for (std::size_t i = 0; i < pattern.size(); i++)
  {
    std::string::size_type y = pattern[i]; 
    if (y >= deque_small.size())
      continue;
      
    int x = deque_small[y];
  
    start = 0;
    middle = 0;
    end = deque_big.size(); 

    while (start < end)
    {
      middle = (start + end) / 2;
      if (x < deque_big[middle])
        end = middle;
      else
        start = middle + 1;
    }
    deque_big.insert(deque_big.begin() + start, x);
  }  
}

void PmergeMe::insertLeftoverDeque()
{
  if (deque_leftover == -1)
    return;

  std::size_t start = 0;
  std::size_t middle = 0;
  std::size_t end = deque_big.size();

  while (start < end)
  {
    middle = (start + end) / 2;
    if (deque_leftover < deque_big[middle])
      end = middle;
    else
      start = middle + 1;
  }
  deque_big.insert(deque_big.begin() + start, deque_leftover);
  deque_leftover = -1;
}
