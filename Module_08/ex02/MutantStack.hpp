#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <list>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack <T, Container>
{
public:
    MutantStack() {}
    MutantStack(const MutantStack &old_obj) : std::stack<T, Container>(old_obj) {}
    MutantStack& operator=(const MutantStack &ref)
    {
        if (this == &ref)
            return *this;
        std::stack<T, Container>::operator=(ref);
        return *this;
    }
    ~MutantStack() {}
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    iterator begin()
    {
        return this->c.begin();
    }
    iterator end()
    {
        return this->c.end();
    }
    const_iterator begin() const
    {
        return this->c.begin();
    }
    const_iterator end() const
    {
        return this->c.end();
    }
};

# endif