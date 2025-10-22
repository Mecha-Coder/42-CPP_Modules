# Module 1 > ex04 > Sed is for losers

- **Turn in files**  : `Makefile`, `main.cpp`, `*.hpp`, `*.cpp`
- **Executable Name**: `./replace(--Anything--)`
- **Allowed**        : `None`
- **Forbidden**        : `std::string::replace`, `C file manipulation functions`

## 📝Program Behaviour
- Write a program that takes 3 arguments
```bash
./program filename s1 s2
```
- Open `<filename>` and copies its contain into a **new file** called `<filename>.replace`
- Find words matching `s1`, then replace it with `s2`

**Error Handling** 
- [x] Can't open file
- [x] Argument count != 3
- [x] Arguments are not blank 

## 🤔Lesson learned
- File I/O manipulation
- Use getline()

## 🧪Expected Results
Test cases
>./replace 1 line -----

>./replace 2 fun XXXXXXXXX

`s1 = line` `s2 = -----`
```bash
This is a line with the word "hello".
Another line with "hello" and "world".
A third line with "hello" and "world" again.
```

```bash
This is a ----- with the word "hello".
Another ----- with "hello" and "world".
A third ----- with "hello" and "world" again.
```


