#include "easyFind.hpp"


int main()
{
    std::vector<int> arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.push_back(40);
    arr.push_back(20);
 
    std::list<int> my_list;
    my_list.push_back(100);
    my_list.push_back(300);
    my_list.push_back(200);
    my_list.push_back(300);

    try
    {
        std::vector<int>::iterator res = easyFind(arr, 20);
        std::cout << "found in vector: " << *res << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    
    try
    {
        std::list<int>::iterator res = easyFind(my_list, 400);
        std::cout << "found in list: " << *res << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}
