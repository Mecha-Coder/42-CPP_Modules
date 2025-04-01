#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <cstdlib> // For atoi()
#include <algorithm>  // For std::copy
#include <sstream>

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

template <typename I>
void Ford_John_Sort(I begin, I end)
{
    if (std::distance(begin, end) == 1) return;
    if (std::distance(begin, end) == 2) {
        insertSort(begin, end);
        return;
    }

    I a = begin;
    I b = begin;
    b++;

    vector<int> large;
    vector<int> small;
    bool extra = false;

    while (true)
    {
        if (*a > *b) {large.push_back(*a); small.push_back(*b);}
        else         {large.push_back(*b); small.push_back(*a);}

        if (++a == end || ++b == end) break;
        if (++a == end || ++b == end) {extra = true; break;}
    }

    Ford_John_Sort(large.begin(), large.end());
    Ford_John_Sort(small.begin(), small.end());

    if (extra)
    {
        if (*a > large.front() && *a > small.back())
            large.push_back(*a);
        else 
            small.push_back(*a);
    }

    I lastcopy = std::copy(small.begin(), small.end(), begin);
    std::copy(large.begin(), large.end(), lastcopy);
    insertSort(begin, end);
}   

int main(int ac, char **av)
{
    if (ac < 2) 
    {
        cerr << "Error: Please provide a sequence of numbers\n";
        return 1;
    }

    vector<int> arr;
    fill_array(ac, av, arr);

    cout << "\nOriginal Array\n";
    showNumber(arr);

    Ford_John_Sort(arr.begin(), arr.end());

    cout << "\nArray After Sorting\n";
    showNumber(arr);

    return 0;
}
