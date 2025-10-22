# Module 1 > ex03 > Unnecessary violence

- **Turn in files**  : `Makefile`, `main.cpp`, `Weapon.hpp`, `Weapon.cpp`, `HumanA.hpp`, `HumanA.cpp`, `HumanB.hpp`, `HumanB.cpp`
- **Executable Name**: `./violence(--Anything--)`
- **Allowed**        : `None`
- **Forbidden**        : `None`

## Class design
**Class**: `Weapon`
- Private: `string type`
- Public: `const getType(void)` , `void setType(std::string n)`

**Class**: `HumanA`, `HumanB`
- Private: `string name` `Weapon type`
- Public: `void attack()`
- Class A and B are almost the same. The difference, constructor A takes both name & weapon. While, constructor B take only name. 

## 📝Program Behaviour
- If  implementation is correct, executing the following code will print
```C++
int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

}
```
1) `<name>` attacks with their `<crude spiked club>`
2) then `<name>` attacks with their `<some other type of club>`

## 🤔Lesson learned
- apply reference to object & pointer to object

## 🧪Expected Results
```bash
Bob attacks with their crude spiked club
Bob attacks with their some other type of club
Jim attacks with their crude spiked club
Jim attacks with their some other type of club
```


