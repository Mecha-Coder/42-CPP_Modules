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
void reMerge(I begin, I middle, I end)
{
    std::vector<int> temp;

    I left = begin;
    I right = middle;

    while (left != middle && right != end)
    {
        if (*left < *right)
            temp.push_back(*left++);
        else
            temp.push_back(*right++);
    }

    temp.insert(temp.end(), left, middle);
    temp.insert(temp.end(), right, end);

    std::copy(temp.begin(), temp.end(), begin);
}

template <typename I>
void mergeSort(I begin, I end)
{
    size_t Size = std::distance(begin, end);
    if (Size <= 1) return;

    I middle = begin;
    for (size_t i = 0; i < Size / 2; ++i)
        ++middle;

    mergeSort(begin, middle);
    mergeSort(middle, end);
    reMerge(begin, middle, end);
}

int main(int ac, char **av)
{
    if (ac < 2) 
    {
        cerr << "Error: Please provide a sequence of numbers as arguments.\n";
        return 1;
    }

    vector<int> arr;
    fill_array(ac, av, arr);

    cout << "\nOriginal Array\n";
    showNumber(arr);

    mergeSort(arr.begin(), arr.end());

    cout << "\nArray After Sorting\n";
    showNumber(arr);

    return 0;
}
