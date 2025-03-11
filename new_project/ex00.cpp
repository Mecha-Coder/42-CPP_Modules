#include <iostream>
#include <string>
using namespace std;

class Phone {
    string Name, Processor;
    int RAM; float Battery;
public:
    Phone(string name="Unknown", string processor="Unknown", int ram=0 , float battery=0.0f)
    : Name(name), Processor(processor), RAM(ram), Battery(battery)
    {}

    Phone(const Phone &other) {
        Name = other.Name;
        Processor = other.Processor;
        RAM = other.RAM;
        Battery = other.Battery;
    }

    void getInfo() {
        cout << "Name     : " << Name      << "\n"
             << "Processor: " << Processor << "\n"
             << "RAM      : " << RAM       << "GB\n"
             << "Battery  : " << Battery   << "Ah\n"
             << "\n\n";
    }
};

int main()
{
    Phone p1;
    p1.getInfo();

    Phone p2("Samsung Galaxy S7", "Snap Dragon 4.7hz", 8, 2.5);
    p2.getInfo();

    Phone p3(p2);
    p3.getInfo();
}
