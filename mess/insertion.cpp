#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib> // For atoi()
#include <algorithm>  // For std::copy

using namespace std;

template <typename T>
void showNumber(const T &arr)
{
    cout << "Numbers: ";
    for (typename T::const_iterator i = arr.begin(); i != arr.end(); ++i)
        cout << *i << " ";
    cout << "\n";
}

template <typename T>
void fill_array(int ac, char **av, T &arr)
{
    for (int i = 1; i < ac; i++)
        arr.push_back(atoi(av[i]));
}


template <typename I>
void insertSort(I begin, I end)
{
    I current = begin;
    while (++current != end)
    {
        int value = *current;
        I i = current;
        I j = current;

        while (j != begin && *(--j) > value)
            *(i--) = *j;
        
        if (value >= *j) *i = value;
        else             *j = value;
    }
}

int main(int ac, char **av)
{
    if (ac < 2) 
    {
        cerr << "Error: Please provide a sequence of numbers as arguments.\n";
        return 1;
    }

    std::deque<int> arr;
    fill_array(ac, av, arr);

    cout << "\nOriginal Array\n";
    showNumber(arr);

    insertSort(arr.begin(), arr.end());

    cout << "\nArray After Sorting\n";
    showNumber(arr);

    return 0;
}
