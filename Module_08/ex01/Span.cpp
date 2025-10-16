#include "Span.hpp"

Span::Span(unsigned int N)
{
    this->N = N;
}
    
Span::Span (const Span& old_obj)
{
    this->N = old_obj.N;
    this->nums_vec = old_obj.nums_vec;
}

Span& Span::operator =(const Span& ref)
{
    if (this == &ref)
        return *this;
    this->N = ref.N;
    this->nums_vec = ref.nums_vec;
    return *this;
}

Span::~Span()
{}

void Span::addNumber(int num)
{
    if (nums_vec.size() >= N)
        throw std::runtime_error("Span is full");
    nums_vec.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if(nums_vec.size() < 2)
        throw std::runtime_error("not enough elements");
    std::vector<int> copy = nums_vec;
    std::sort(copy.begin(), copy.end());
    unsigned int min = UINT_MAX;
    for(size_t i = 0; i < copy.size() - 1; ++i)
    {
        unsigned int res = copy[i+1] - copy[i];
        if (res < min)
            min = res;
    }
    return min;
}

unsigned int Span::longestSpan() const
{
    if(nums_vec.size() < 2)
        throw std::runtime_error("not enough elements");
    unsigned int min = *std::min_element(nums_vec.begin(), nums_vec.end());
    unsigned int max = *std::max_element(nums_vec.begin(), nums_vec.end());
    unsigned int res = max - min;
    return res;
}