#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template<typename T>
typename T::iterator easyFind(T &arr, int num)
{
    typename T::iterator res = std::find(arr.begin(), arr.end(), num);
    if (res == arr.end())
    {
        throw "num not found!";
    }
    else
        return (res);
}



#endif
