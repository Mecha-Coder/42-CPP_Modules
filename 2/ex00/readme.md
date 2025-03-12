# Module 2 > ex00 > First Orthodox Canonical Form

- **Turn in files**  : `Makefile`, `main.cpp`, `Fixed.hpp`, `Fixed.cpp`
- **Executable Name**: `./ocf(--Anything--)`
- **Allowed**        : `None`
- **Forbidden**        : `None`

## Class desgin

**Class**: `Fixed`
- Private: 
    - `int fixed-point number`
    - `static const int fractional bits` = 8

- Public:
    - `Default constructor`: initializes fixed-point number value to 0
    - `Copy constructor`
    - `Copy assignment operator overload`
    - `Destructor`
    - `int getRawBits( void ) const`: function that return fixed-point number
    - `void setRawBits( int const raw )`: function that set the fixed-point number 

## 📝Program Behaviour
- Basic Class for converting numbers to fix-point number that follows OCF 

```c++
#include <iostream>

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;
    
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}
```

```bash
Default constructor called
--------------------------------------------
Copy constructor called
--------------------------------------------
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
--------------------------------------------
Default constructor called
--------------------------------------------
Copy assignment operator called
getRawBits member function called
--------------------------------------------
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
--------------------------------------------
Destructor called
Destructor called
Destructor called
```

## 🤔Lesson learned
- How to use OCF to desgin Classes

## 🧪Expected Results
`


