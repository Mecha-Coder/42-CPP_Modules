#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std;

template <typename I> 
I binarySearch(I begin, I end, int num)
{
    I middle = begin;
    
    if (begin == end)
        return begin;

    std::advance(middle, std::distance(begin, end) / 2);
    
    if (num > *middle)
        return binarySearch(++middle, end, num);
    if (num < *middle)
        return binarySearch(begin, --middle, num);
    return middle;
}


int main()
{
    std::list<int> num;
    
    num.push_back(0);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(6);
    num.push_back(10);
    num.push_back(15);

    std::list<int>::iterator i = binarySearch(num.begin(), num.end(), 1);
    cout << *i << "\n";
}