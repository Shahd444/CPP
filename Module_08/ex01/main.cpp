#include "Span.hpp"

int main()
{
    Span sp1 = Span(3);

    sp1.addNumber(30);
    sp1.addNumber(11);
    sp1.addNumber(8);

    std::cout << "sp1 shortest: " << sp1.shortestSpan() << std::endl;
    std::cout << "sp1 longest: " << sp1.longestSpan() << std::endl;

    Span sp2 = Span(1);

    sp2.addNumber(1);

    try
    {
        std::cout << "sp2 shortest: " << sp2.shortestSpan() << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<int> big_vec(100000);
    for (int i = 0; i < 100000; ++i)
        big_vec[i] = i;


    Span sp3 = Span(100000);
    sp3.addNumber(big_vec.begin(), big_vec.end());

    std::cout << "sp3 shortest: " << sp3.shortestSpan() << std::endl;
    std::cout << "sp3 longest: " << sp3.longestSpan() << std::endl;

    return 0;
}