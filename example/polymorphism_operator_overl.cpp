/*
Ad-hoc polymorphism: ability of functions or operators to behave differently based on their argument types

commonly implemented using 
- function overloading - same function name 
- operator overloading - change behaviour of +,-,*
-                      - addTimes(t1, t2), you can simply use t1 + t2
*/

#include <iostream>
#include <string>

class MyString 
{
    public:
        std::string str;
        MyString(const std::string& s) : str(s) {}

    // Overloading + operator for concatenation
    MyString operator+(const MyString& other) const 
    { 
        return MyString(str + other.str); 
    }
};

class Time
{
    private:
        int hour;
        int min;

    public:
        Time(int h, int m) : hour(h), min(m) {}
        
        void show_time(void)
        {
            std::cout
                << hour << ":" << min
                << std::endl;
        }

        //      a    +  b 
        Time operator+(const Time& other) const
        {            
            int new_min  = (min + other.min) % 60;
            int new_hour = (hour + other.hour) + (min + other.min) / 60;
            return Time(new_hour, new_min);
        }
};

int main() 
{
    MyString s1("Hello, ");
    MyString s2("world!");
    MyString s3 = s1 + s2;
    std::cout << s3.str << std::endl;

    std::cout << "\n=================================\n" << std::endl;

    Time t1(10, 30); // 10:30
    Time t2(2, 45);  // 2:45
    Time t3 = t1 + t2; // t3 now holds the sum of t1 and t2

    std::cout << "t1 > ";
    t1.show_time();

    std::cout << "t2 > ";
    t2.show_time();

    std::cout << "t3 > ";
    t3.show_time();

    return 0;
}
