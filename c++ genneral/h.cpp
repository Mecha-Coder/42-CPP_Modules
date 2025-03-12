#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
Operator overloading

What is operator function
==========================
- define how a certain operator will behave with a specific datatype

Example: redefine '+'
======================
4 + 5;
car1 + car2;

Insertion operation 
======================
- work with 2 end
  
   cout << obj1
-    ↑      ↑ 

Math operator (* / - + >= <= == != +=)
========================
- implemetation method is different that << insertion
- only pass 1 argument
*/

struct YouTubeChannel{
    string Name;
    int SubscribeCount;

    YouTubeChannel(string name, int subscribeCount)
    {
        Name = name;
        SubscribeCount = subscribeCount;
    }
};

struct MyCollection{
    list<YouTubeChannel> myChannels;

    // Member function
    // Receive 1 parameter
    void operator+=(YouTubeChannel &channel) // <------ math operator overload
    {
        this->myChannels.push_back(channel);
    }
};

// Global function
// Receive 2 parameter
// When to copy or pass by reference 
// When want to reflect changes back && expensive to copy consume lot of data
ostream& operator<<(ostream &out, YouTubeChannel &channel) // <--- passing by reference (passing original, not a copy)
{
    out << "Name: " << channel.Name << "\n"
        << "SubscribeCount:" << channel.SubscribeCount << "\n";
    return (out);
}

ostream& operator<<(ostream &out, MyCollection &mycollection)
{
    for(YouTubeChannel channel: mycollection.myChannels)
    {
        out << channel.Name << "\n"
            << channel.SubscribeCount << "\n"
            << "**********************************\n";
    }
    return (out);
}


int main()
{
    YouTubeChannel obj1 = YouTubeChannel("CodeBeauty", 75000);
    YouTubeChannel obj2 = YouTubeChannel("2nd Channel", 80000);
    // cout << obj1 << obj2 << 55;
    // cout << "------------------------\n";
    // operator<<(cout, obj1); // <<----- invoke overload operator
    MyCollection myCollection;
    myCollection += obj1;    // <<----------- interesting usage
    myCollection += obj2;

    
    cout << "---------------------------------------------\n";
    cout << myCollection;

    cin.get();
}