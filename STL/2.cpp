/*
Container - List
*/

#include <list>
#include <iostream>
using namespace std;


void example1() {
    list<int> myList;
    myList.push_front(10);
    myList.push_front(20);
    myList.push_back(120);

    // Output
    //  20 -> 10 -> 120

    // similar to  for (int i=0; i < 100 ;i++)
    // i = address, to print the value need to reference the value *address
    for (list<int>::iterator i=myList.begin() ; i!=myList.end() ; i++) {
        cout << *i << endl;
    }
    cout << "---------------------------------\n";
    myList.erase(myList.begin());

    for (list<int>::iterator i=myList.begin() ; i!=myList.end() ; i++) {
        cout << *i << endl;
    }
    cout << "---------------------------------\n";
    myList.clear();

    for (list<int>::iterator i=myList.begin() ; i!=myList.end() ; i++) {
        cout << *i << endl;
    }
}

void showRating(const list<int> &rating)
{
    for (list<int>::const_iterator i=rating.begin() ; i!=rating.end() ; i++) {
        cout << "Player rating: " << *i << endl;
    }
}

void inOrder(int newPlayer, list<int> &rating)
{
    for (list<int>::iterator i=rating.begin() ; i!=rating.end() ; i++) 
    {
        if (*i > newPlayer)
        {
            rating.insert(i, newPlayer);
            return;
        }
    }
    rating.push_back(newPlayer);
}

void example2() {
    list<int> allPlayer = {2,9,6,7,3,1,4,8,3,2,9,4};

    list<int> beginner; //rating: 1-5
    list<int> pros; //rating: 6-10

    for (list<int>::iterator i=allPlayer.begin() ; i!=allPlayer.end() ; i++) {
        if (*i < 6)
            inOrder(*i, beginner);
        else
            inOrder(*i, pros);
    }

    cout << "Beginner: " << endl;
    showRating(beginner);
    cout << "-------------------------\n";
    cout << "Pro: " << endl;
    showRating(pros);
}

int main()
{
    // example1();
    example2();
}
