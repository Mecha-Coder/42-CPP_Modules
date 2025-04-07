#include <vector>
#include <list>
#include <deque>
#include <iterator>

int main()
{
    std::vector<int> Vector;
    std::list<int> List;
    std::deque<int> Deque;
    int unpair = -1;
    int i;
    std::vector<int>::iterator begin = Vector.begin();
    std::vector<int>::iterator end = Vector.end();

    // Example: 7, 8, 27, 100, 11, 46, 2, 53, 0 (size: 9)

    // If element is zero or 1, not need to sort

    /* 1. Put odd aside
    - 9 % 2 = Is ODD
    - 7, 8, 27, 100, 11, 46, 2, 53, [0] <=
    - This singleton element will be sorted last. (Unpaired: 0)
    - Put it aside. If unpair = -1, mean size are even
    */
    if (Vector.size() % 2)
    {
        unpair = Vector.back();
        end--;
    }

        

    /* 2. Group elements into pair and sort
    - In each pair, ensure the first > second. If not, swap them
    
        Bofore: (7, 8) (27, 100) (11, 46) (2, 53) 
        After : (8, 7) (100, 27) (46, 11) (53, 2)
    */
   
    for (i = 0; i < ; i++)
    {
        if ()
    }

    3>
}