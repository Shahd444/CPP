#include "Base.hpp"

int main()
{
    srand(time(NULL));

    Base* b = generate();
    identify(b);
    identify(*b);
    
    delete(b);

    return 0;
}
