/* Lesson-01: 
- Class creation and object instantiation
- Access specifier
- Access member with value and pointer .dot ->arrow
*/

#include <iostream>
#include <string>
using namespace std;

class House {
    int len, width;
public:
    void setData(int x, int y) {len = x; width = y;}
    void area() {cout << "Area of house is " << len * width << "\n";}
};

int main()
{
    House h1;
    h1.setData(300, 500);
    h1.area();

    //------------------------------
    
    House *h2 = new House();
    h2->setData(500, 600);
    h2->area();
    
    delete h2;
}
