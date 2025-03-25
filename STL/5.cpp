/*
- Queue _ FIFO

push 
back
front
pop
*/

#include <iostream>
#include <queue>
using namespace std;

void printQueue(queue<int> myQueue) {
    while (!myQueue.empty()) {
        cout << myQueue.front() << endl;
        myQueue.pop();
    }
}

int main()
{
    queue<int> myQueue;
    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);

    cout << "Size is " << myQueue.size() << endl;
    cout << "First element is " << myQueue.front() << endl;
    cout << "Last element is " << myQueue.back() << endl;

    cout << "My queue\n========\n";
    printQueue(myQueue);
}