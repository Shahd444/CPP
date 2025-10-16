#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
private:
    T* arr;
    size_t num;
public:
    Array()
    {
        arr = NULL;
        num = 0;
    }

    Array(unsigned int n)
    {
        num = n;
        arr = new T[num]();
    }

    Array(const Array& old_obj)
    {
        num = old_obj.num;
        arr = new T[num]();
        for (size_t i = 0; i < num; i++)
        {
            arr[i] = old_obj.arr[i];
        }
    }

    Array &operator =(const Array & ref)
    {
        if (&ref == this)
            return *this;
        num = ref.num;
        delete[] arr;
        arr = new T[num]();
        for (size_t i = 0; i < num; i++)
        {
            arr[i] = ref.arr[i];
        }
        return *this;
    }

    T& operator[](unsigned int index) //overload the subscript operator
    {
        if (index >= num)
            throw std::out_of_range("index is out of range!\n");
        return arr[index];
    }

    const T& operator[](unsigned int index) const
    {
        if (index >= num)
            throw std::out_of_range("index is out of range!\n");
        return arr[index];
    }

    ~Array()
    {
        delete[] arr;
        arr = NULL;
    }

    size_t size() const
    {
        return num;        
    }
};

# endif
