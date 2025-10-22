#include <iostream>
using namespace std;

/*
Array
=====
- is a type of collection (data structure) element of the same type
- how to store element of different type in the same array[]

dynamic allocation
=================
new Student [size]
*/

class Student {
public:    
    string Name;
    int Age;  // Changed from char to int
    char Gender;
    float ProgrammingGrade;

    Student() {}
    ~Student() { cout << "Destroy " << Name << "\n\n"; }

    Student(const string &name, int age, char gender, float grade) {
        Name = name;
        Age = age;  // Fixed order
        Gender = gender;
        ProgrammingGrade = grade;
    }
};
    
void printInfo(Student *s, int size)
{
    cout << "Print out student\n-------------------\n";
    for (int i = 0; i < size; i++)
    {
        cout << "STUDENT " << i + 1  << "\t";

        cout << "Name  : " << s[i].Name << "\t";
        cout << "Gender: " << s[i].Gender << "\t";
        cout << "Age   : " << s[i].Age << "\t";
        cout << "Grade : " << s[i].ProgrammingGrade << "\t";
        cout << "\n";
    }
}
    
int main()
{
    int size;
    cout << "Number of students: ";
    cin >> size;

    Student *student = new Student[size];  // Dynamically allocated array
    
    for (int i = 0; i < size; i++)
    {
        cout << "STUDENT " << i + 1 
                << "\n==========\n";

        cout << "Name  : ";
        cin >> student[i].Name;
        cout << "Gender: ";
        cin >> student[i].Gender;
        cout << "Age   : ";
        cin >> student[i].Age;  // Now correctly stores an int
        cout << "Grade : ";
        cin >> student[i].ProgrammingGrade;
        cout << "\n---------------------------------\n";
    }

    printInfo(student, size);

    delete [] student;  // Correctly deletes the allocated memory
}