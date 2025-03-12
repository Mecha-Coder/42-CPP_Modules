/* Lesson-03
- operator overloading
- function vs operator overload for adding user_define datatype
*/

# include <iostream>
# include <string>
using namespace std; 

class ClassA {
    int weight; string person;
public:
    ClassA() : person("Unknown") {cout << person << " : Default constructor\n";}

    ClassA(int x, const string &p)  : weight(x), person(p) 
    {cout << "Parameterized constructor\n";}

    ~ClassA() {cout << person << ". I die\n";}

    int getWeight() const {return weight;}

    ClassA addWeight(const ClassA &w2) {
        ClassA temp;
        temp.weight = weight + w2.weight;
        return (temp);
    }

    ClassA operator+(const ClassA &w2) {
        ClassA temp;
        temp.weight = weight + w2.weight;
        return (temp);
    }

    int operator++()
    {return (++weight);}

    int operator--(int)
    {return (weight--);}
};

int main()
{
    int a=5, b=6, c=1;
    c = a + b + c; // 12

    ClassA person1(63, "Hello");
    cout << "-------------------------\n";
    ClassA person2(74, "There"); // 137
    cout << "-------------------------\n";

    ClassA total1, total2; 
    cout << "-------------------------\n";
    total1 = person1.addWeight(person2);
    cout << "-------------------------\n";
    total2 = person1 + person2 + person1;
    cout << "-------------------------\n";

    cout << c << "\n";
    cout << "Person_1 : " << total1.getWeight() << "\n";
    cout << "Person_2 : " << total2.getWeight() << "\n";

    cout << "-------------------------\n";
    
    cout << "pre-increment : " << ++person1 << "\n";
    cout << "post-decrement : " <<  person2-- << "\n";
    cout << "post-decrement : " <<  person2.getWeight() << "\n";

    cout << "-------------------------\n";
}
