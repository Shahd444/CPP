#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& old_obj)
{
  *this = old_obj;
}

RPN& RPN::operator=(const RPN& ref)
{
  (void)ref;
  return *this;
}

RPN::~RPN() {}

void RPN::handleCalculation(std::string input)
{
    std::stringstream ss(input);
    std::string token;
    int res;
    while (ss >> token)
    {
        if (token.size() == 1 && isdigit(token[0]))
            stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: not enough elements in stack\n";
                exit (1);                
            }
            int second = stack.top();
            stack.pop();
            int first = stack.top();
            stack.pop();
            if (token == "+")
                res = first + second;
            else if (token == "-")
                res = first - second;
            else if (token == "*")
                res = first * second;
            else
            {
                if (second == 0)
                {
                    std::cerr << "Error: can't divide by zero\n";
                    exit(1);
                }
                res = first / second;
            }
            stack.push(res);
        }
        else
        {
            std::cerr << "Error\n";
            exit (1);
        }
    }
    if (stack.size() != 1)
    {
        std::cerr << "Error\n";
        exit (1);
    }
    std::cout << stack.top() << "\n";
}

