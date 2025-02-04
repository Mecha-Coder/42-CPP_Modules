#include <iostream>
#include <string>

/*
- class can also be derived from more than one base class
- comma-separated list
    [class NewClass: public ClassA, public ClassB]
*/


//---------------------------------------------------------------------
// Example

class ClassA
{
    public:
        void func_1() {std::cout << "This is Function A\n";}
};

class ClassB
{
    public: 
        void func_2() {std::cout << "This is Function B\n";}
};

class NewClass: public ClassA, public ClassB
{

};
//---------------------------------------------------------------------

class Shape
{
    private:
        int width;
        int height;

    public:
        void setWidth(int w){width = w;}
        void setHeight(int h){height = h;}
        int getWidth() {return (width);}
        int getHeight() {return (height);}
};


class PaintCost
{
    public:
        int getCost(int area) {return (area * 70);}
};


class Rectangle: public Shape, public PaintCost
{
  public:
    int getArea(){return (getHeight() * getWidth());}
};

//---------------------------------------------------------------------


int main()
{
    /*
    NewClass testing;

    testing.func_1();
    testing.func_2();
    */
    Rectangle rect;

    rect.setHeight(5);
    rect.setWidth(7);

    std::cout << "Total area: " << rect.getArea() << "\n";
    std::cout << "Total cost for painting: " << rect.getCost(rect.getArea()) << "\n";

}