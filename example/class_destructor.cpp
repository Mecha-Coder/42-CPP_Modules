/*
Use for clean-up
- Deallocating memory that was dynamically allocated
- Closing files that were opened by the object

class MyClass 
{
    public:
        // ... other members ...
        ~MyClass() { 
            // Cleanup code 
        } 
};

- same name as the class, but it is prefixed with a tilde (~)
- does not have any return type (not even void).
- It does not take any argument
*/

class MyClass 
{
    public:
        int* data;

        MyClass(int size) {data = new int[size];}

        // Deallocate dynamically allocated memory
        ~MyClass() { delete[] data;}
};

int main()
{
    MyClass obj(10);
}