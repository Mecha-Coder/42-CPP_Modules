/* Lesson-03
- operator overloading
- function vs operator overload for adding user_define datatype
*/


# include <iostream>
# include <string>
using namespace std; 


class ClassA {
    int weight;
public:
    ClassA() {}
    ClassA(int x) {weight = x;}

    int getWeight() const {return weight;}

    ClassA addWeight(const ClassA w2) {
        ClassA temp;
        temp.weight = weight + w2.weight;
        return (temp);
    }

    ClassA operator+(const ClassA w2) {
        ClassA temp;
        temp.weight = weight + w2.weight;
        return (temp);
    }

};

int main()
{
    int a=5, b=6, c=1;
    c = a + b + c; // 12

    ClassA person1(63);
    ClassA person2(74); // 137

    ClassA total1, total2; 
    
    total1 = person1.addWeight(person2);
    total2 = person1 + person2;

    cout << c << "\n";
    cout << "Person 1:" << total1.getWeight() << "\n";
    cout << "Person 2:" << total2.getWeight() << "\n";
}
