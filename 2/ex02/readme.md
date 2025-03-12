# Module 2 > ex02 > Now we're talking

- **Turn in files**  : `Makefile`, `main.cpp`, `Fixed.hpp`, `Fixed.cpp`
- **Executable Name**: `./useful_fix_point(--Anything--)`
- **Allowed**        : `roundf (from <cmath>)`
- **Forbidden**        : `None`

## Class desgin (Add more feature from ex00)

**Class**: `Fixed`

- Public: 
    - 6 comparison operators: >, <, >=, <=, == and !=.
    - 4 arithmetic operators: +, -, *, and /
    - pre-increment and post-increment ++value, value++
    - pre-decrement and post-decrement --value, value--
    - `static member function min`: returns a reference to the smallest value
    - `static const member function min`:
    - `static member function max`: returns a reference to the biggest value
    - `static const member function man`


## 📝Program Behaviour
- More feature 
    - comparison between fixed-point 
    - increment/decrement fixed-point

```c++
#include <iostream>
int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;
    
    std::cout << Fixed::max( a, b ) << std::endl;
}
```

```bash
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
```

## 🤔Lesson learned
- More Ad-hoc polymorphism - Function & Operator overloading 

## 🧪Expected Results
`


