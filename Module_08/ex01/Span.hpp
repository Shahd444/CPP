#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

class Span
{
private:
    unsigned int N;
    std::vector<int> nums_vec;

public:
    Span(unsigned int N);
    Span (const Span& old_obj);
    Span& operator =(const Span& ref);
    ~Span();

    void addNumber(int num);
    template <typename MyIterator>
    void addNumber(MyIterator begin, MyIterator end)
    {
        for (MyIterator i = begin; i != end; i++)
            addNumber(*i);
    }

    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;

};

#  endif