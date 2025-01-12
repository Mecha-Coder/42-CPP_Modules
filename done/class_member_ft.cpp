#include <iostream>

class Rectangle 
{
    private:
        double width;
        double height;

    public:
        double area()  {return (width * height);}

        void setDimensions(double w, double h)
        { 
            width = w; 
            height = h; 
        }
};

int main()
{
    Rectangle rect;

    rect.setDimensions(5.4, 3.1);
    std::cout << rect.area() << "\n" << std::endl;
}