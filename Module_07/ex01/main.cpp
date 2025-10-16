#include "iter.hpp"

template <typename T>
void toUpper(T &c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
}

template <typename T>
void toLower(T &c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
}

template <typename T>
void print(T p)
{
    std::cout << p << std::endl;
}

template<typename T>
void increment(T &n)
{
    n -= 1;
}

int main()
{
    int arr[] = {1, 2, 3};
    char c[] = {'a', 'b', 'c', 'd'};
    const std::string str[] = {"Hello", "How Are You", "GoodBye"};

    iter(arr, 3, increment<int>);
    iter(arr, 3, print<int>);

    iter(c, 4, toUpper<char>);
    iter(c, 4, print<char>);

    iter(str, 3, print<const std::string>);

    return 0;
}