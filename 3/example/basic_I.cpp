#include <iostream>
#include <string>

/*
  Derived class (child)
    - the class that inherits from another class
  
  Base class (parent)
    - the class being inherited from

  To inherit from a class, use the : symbol
  [class Car: public Vehicle]
*/


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

class Rectangle: public Shape
{
  public:
    int getArea(){return (getHeight() * getWidth());}
};


int main()
{
    Rectangle rect;

    rect.setWidth(5);
    rect.setHeight(7);

    std::cout << "Total area " << rect.getArea() << "\n";
    return (0);
}
