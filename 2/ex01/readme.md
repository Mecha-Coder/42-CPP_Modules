# Module 2 > ex01 > Useful fixed-point class

- **Turn in files**  : `Makefile`, `main.cpp`, `Fixed.hpp`, `Fixed.cpp`
- **Executable Name**: `./fix_point(--Anything--)`
- **Allowed**        : `roundf (from <cmath>)`
- **Forbidden**        : `None`

## Class desgin (Add more feature from ex00)

**Class**: `Fixed`

- Public:
    - `Parameterized Constructor`: takes constant integer
    - `Parameterized Constructor`: constant floating-point number
    - (both convert into corresponding fixed-point value)
    - `float toFloat( void ) const`: Convert fixed-point back to float
    - `int toInt( void ) const`: Convert fixed-point back to int

- None Member:
    - overload insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream

## 📝Program Behaviour
- Program that can except Integer and Float number, but stores them in fix-point number
- Able convert back to original number
- Implement overload << insertion on output stream

```c++
#include <iostream>
int main( void ) 
{
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}
```

```bash
Default constructor called
---------------------------------------------
Int constructor called
---------------------------------------------
Float constructor called
---------------------------------------------
Copy constructor called
---------------------------------------------
Copy assignment operator called <--- Not there
---------------------------------------------
Float constructor called
Copy assignment operator called
Destructor called
---------------------------------------------
a is 1234.43
b is 10
c is 42.4219
d is 10
---------------------------------------------
a is 1234 as integer
b is 10 as integer
c is 42 as integer
d is 10 as integer
---------------------------------------------
Destructor called
Destructor called
Destructor called
Destructor called
```

## 🤔Lesson learned
- Converting numbers to fixed point
- Implement Ad-hoc polymorphism - Function & Operator overloading 

## 🧪Expected Results
`


