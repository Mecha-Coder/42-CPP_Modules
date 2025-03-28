#include <set>
#include <iostream>
#include <vector>


void addMore(std::vector<int> number)
{
    std::cout << "Testing the water\n";
    for (std::vector<int>::iterator i = number.begin(); i != number.end(); i++)
        std::cout << *i << "\n";
}

int main() 
{
    addMore({12,3 321,3213, 321});
}


// void example()
// {
//     std::set<int> s;
//     s.insert(10);
//     s.insert(3);
//     s.insert(25);
//     s.insert(1);
//     s.insert(8);

//     for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
//         std::cout << *it << " ";
//     }
//     std::cout << std::endl;

//     std::cout << *s.begin() << "\n";
//     std::cout << *s.rbegin() << "\n";
//     std::cout << "Size of set : " << s.size() << "\n";
// }


