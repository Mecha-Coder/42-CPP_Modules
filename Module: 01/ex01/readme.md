# Module 1 > ex01 > Moar brainz

- **Turn in files**  : `Makefile`, `main.cpp`, `Zombie.hpp`, `Zombie.hpp`, `zombieHorde.cpp`
- **Executable Name**: `./zombie_horde(--Anything--)`
- **Allowed**        : `None`
- **Forbidden**        : `None`

## 📝Class design (same as ex00)
- **Class**: Zombie
    - Private: `string name`
    - Public: `void announce(void)`
    - announce() function prints <`name`>: BraiiiiizzzZ...
    
    `Example   Foo: BraiiiiizzzZ...`
    - Destructor that print zombie name

## 📝Program Behaviour
- Implement these function  `Zombie* zombieHorde( int N, std::string name );`
- Allocate N Zombie objects in a single allocation
- Initialize each zombie with the name passed as parameter.
- Function returns pointer to the first zombie

## 🤔Lesson learned
- allocate the zombies in an array
- dynamic allocation require default constructor

## 🧪Expected Results


