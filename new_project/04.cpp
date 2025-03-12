/* Lesson-04
- Inheritance
*/

#include <iostream>
#include <string>
using namespace std;

//=====================================================================
// Rectangle class
//=====================================================================

class Rectangle
{
    protected: int Len, Width;
    public:
        Rectangle (int len, int width);
        virtual void getDetail();
        void area(); 
};

Rectangle::Rectangle(int len, int width) 
: Len(len), Width(width)
{
    if (Len <= 0 || Width <= 0) 
    {
        cerr << "Values must be greater than 0" << "\n";
        exit(EXIT_FAILURE);
    }
}

void Rectangle::getDetail()
{
    cout << "Length : " << Len << "\n"
         << "Width  : " << Width << "\n"; 
}

void Rectangle::area() 
{cout << "Area = " << Len * Width << "\n";}

//=====================================================================
// Cubiod class implementation
//=====================================================================

class Cubiod : public Rectangle 
{
    private: int Height;
    public:
        Cubiod(int len, int width, int height);
        void getDetail();
        void volume();
};

Cubiod::Cubiod(int len, int width, int height) 
: Rectangle(len, width) , Height(height)  
{
    if (Height < 0 ) 
    {
        cerr << "Height can't be negative value" << "\n";
        exit(EXIT_FAILURE);
    }
}

void Cubiod::getDetail() 
{
    cout << "Length : " << Len << "\n"
         << "Width  : " << Width << "\n"
         << "Height : " << Height << "\n"; 
}

void Cubiod::volume() 
{cout << "Volume = " << Width * Height * Len << "\n";}

int main()
{
    // Base class
    // Rectangle r(5, 0);
    Rectangle r(5, 6);
    r.getDetail();
    r.area();

    cout << "-----------------------------\n";

    // Derived class
    Cubiod c(3,4,2);
    c.getDetail();
    c.area();
    c.volume();
}
