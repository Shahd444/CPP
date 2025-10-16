#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>


class RPN
{
private:
    std::stack<int> stack;
public:
    RPN();
    RPN(const RPN& old_obj);
    RPN& operator=(const RPN& ref);
    ~RPN();
    void handleCalculation(std::string input);
};




# endif