# Module 1 > ex06 > Harl filter

- **Turn in files**  : `Makefile`, `main.cpp`, `Harl.hpp`, `Harl.cpp`
- **Executable Name**: `./harlFilter`
- **Allowed**        : `None`
- **Forbidden**        : `None`

## Class desgin (use back ex05)


## 📝Program Behaviour
- Create a program that take one of the four levels as argument
- Display all messages from this level and below it
- Example: `INFO` below it is `WARNING` & `ERROR` 
- Level: `DEBUG` `INFO` `WARNING` `ERROR`
- Special: `SWITCH` - don't display anything

```bash
> ./harlFilter "WARNING"

[ WARNING ]
I think I deserve to have some extra bacon for free.
Ive been coming for years whereas you started working here since last month.

[ ERROR ]
This is unacceptable, I want to speak to the manager now.

> ./harlFilter "I am not sure how tired I am today..."
[ Probably complaining about insignificant problems ]
```

## 🤔Lesson learned
- switch case without break [fall through]

## 🧪Expected Results



