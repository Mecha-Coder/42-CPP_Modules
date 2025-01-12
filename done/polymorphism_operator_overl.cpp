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

    MyString operator+(const MyString& other) const 
    {return MyString(str + other.str);}
};

int main() 
{
    MyString s1("Hello, ");
    MyString s2("world!");
    MyString s3 = s1 + s2;
    std::cout << s3.str << std::endl;
}


/*
class Time
{
    private:
        int hour;
        int min;

    public:
        Time(int h, int m) : hour(h), min(m) {}
        
        void show_time(void)
        {std::cout << hour << ":" << min<< std::endl;}

        Time operator+(const Time& other) const
        {            
            int new_min  = (min + other.min) % 60;
            int new_hour = (hour + other.hour) + (min + other.min) / 60;
            return Time(new_hour, new_min);
        }
};

int main() 
{
    Time t1(6, 40);
    Time t2(2, 35);
    Time t3 = t1 + t2;
    t3.show_time();
}
*/