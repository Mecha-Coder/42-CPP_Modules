# Module 0 > ex00 > Megaphone

- **Turn in files**  : `Makefile`, `megaphone.cpp`
- **Executable Name**: `./megaphone`
- **Allowed**        : `None`
- **Forbidden**        : `None`


## 📝Requirement
- Write a program to accept string arguments
- Prints all string in UPPERCASE

## 🤔Lesson learned
- Familiar with I/O in C++ using `string` and `toupper`

## 🧪Expected Results

- **Argument Count**: 1  
  ```bash
  ./megaphone "shhhhh... I think the students are asleep..."

   SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
  ```


- **Argument Count**: 3  
  ```bash
  ./megaphone Damnit " ! " "Sorry students, I thought this thing was off."

  DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
  ```


- **Argument Count**: 0  
  ```bash
  ./megaphone

  * LOUD AND UNBEARABLE FEEDBACK NOISE *
  ```