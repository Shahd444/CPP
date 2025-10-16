#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F>
void iter(T *arr, size_t len, F fun)
{
    size_t i = 0;
    while (i < len)
    {
        fun(arr[i]);
        i++;
    }
}

# endif