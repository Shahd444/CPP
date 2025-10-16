#include "Array.hpp"

int main ()
{
    // Array<int> a;
    // if (a.size() == 0)
    //     std::cout << "empty array\n";
    
    Array<int> a(5);
    Array<int> b = a;
    if (b.size() == 5)
        std::cout << "array is filled successfully\n";
    a[2] = 100;

    std::cout << "array a\n";
    for (size_t i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << '\n';
    }

    std::cout << "array b\n";
    for (size_t i = 0; i < b.size(); i++)
    {
        std::cout << b[i] << '\n';
    }

    const Array<int> c = b;
    int x = c[2];
    std::cout << x << '\n';
    // c[2] = 10;
    
    try
    {
        b[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b[1] = 13;
        for (size_t i = 0; i < b.size(); i++)
            std::cout << b[i] << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        b[100] = 44;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;    
}