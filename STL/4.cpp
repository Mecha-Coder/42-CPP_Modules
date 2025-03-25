/*
- Container: stack - FILO 

empty
size
top
push
pop
*/

#include <stack>
#include <iostream>
using namespace std;

void printStack(stack<int> numStack)
{
    if (numStack.empty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";
    cout << "Stack size is " << numStack.size() << endl;

    while (!numStack.empty()) {
        cout << numStack.top() << endl;
        numStack.pop();
    }
    cout << "---------------------------------\n";
}

int main()
{
    stack<int> numStack;

    printStack(numStack);
    numStack.push(5);
    numStack.push(19);
    printStack(numStack);
    numStack.pop();
    printStack(numStack);
}