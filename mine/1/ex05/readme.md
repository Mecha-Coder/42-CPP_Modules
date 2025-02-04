# Module 1 > ex05 > Harl 2.0

- **Turn in files**  : `Makefile`, `main.cpp`, `Harl.hpp`, `Harl.cpp`
- **Executable Name**: `./complain(--Anything--)`
- **Allowed**        : `None`
- **Forbidden**        : `None`

## Class desgin
**Class**: `Harl`
- Private: `void debug()`, `void info()`, `void warning()`, `void error()`
- Public: `void complain(std::string level)`
- This complain function is responsible to invoke the correct private member function based on the `level`

## 📝Program Behaviour
- Harl has to complain without using a forest of if/else if
- Level: `DEBUG` `INFO` `WARNING` `ERROR`
```c++
Harl harl
harl.complain("WARNING");

//Output:
I think I deserve to have some extra bacon for free. 
I’ve been coming for years whereas you started working here since last month.
```

## 🤔Lesson learned
- Use pointer to member function.

## 🧪Expected Results
`


