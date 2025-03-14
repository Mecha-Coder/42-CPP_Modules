/* Lesson-10
- static data member (shared between objects)
- how to declare and call static data member
- how to use static function to target static data memebers
   - can i use other function to access static member?
*/

#include <iostream>
using namespace std;



class Alpha {
public: 
    int a,b;
    static int stat;
    // static int test2; <---error if no declaration

    Alpha() {
        a = 5;
        b = 5;
        stat++;
    }

    int test() {return stat;} // testing none-static function on static data

    static int get_static()  // static function
    {
        // int total = a + stat;  // Can have none-static data
        //             ↑
        int total = stat;
        return total;
    } 
};

int Alpha::stat = 0;

int main()
{
    Alpha a1;

    cout << a1.stat << "\n";
    cout << Alpha::stat << "\n";
    // cout << "check test : " << Alpha::test2 << "\n";

    cout << "-------------------------\n";
    Alpha a2;

    cout << a1.stat << "\n";
    cout << a2.stat << "\n";

    cout << "-------------------------\n";
    cout << "testing access of none-static function on static data " << a1.test() << "\n";
    cout << Alpha::get_static() << "\n";
}   