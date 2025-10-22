# Module 0 > ex01 > My Awesome Phonebook

- **Turn in files**  : `Makefile`, `*.cpp`, `*.hpp`
- **Executable Name**: `./app (Anything)`
- **Allowed**        : `None`
- **Forbidden**        : `Dynamic allocation`

## 📝Class Requirement 
- **Class**: Contact
  - Private members: `first name`, `last name`, `nickname`, `phone number`, `dark secret`

- **Class**: PhoneBook
  - Array that store **max** of `8 contacts`.


## 📝Program Behaviour
- On start-up, phonebook is empty
- Prompt user for input
  - `ADD` : save new contact
    - Request user information one field at a time
    - Saved contact can't have empty fields
    - If user entered the 9th contact, save/overwrite the oldest contact

  - `SEARCH` : select and display contact info
    - Prompt user for which entry to display
    - display requirement
      - 4 columns: `index`, `first name`, `last name`, `nickname`
      - Text must br right-aligned
      - Each colum must be 10 characters wide sperated by `|`
      - If text longer than column, truncate it and replace last displayable character with dot `.`
    - After that , prompt user again for the next contact
    - If wrong input or index out of range, behave accordingly

  - `EXIT` : quit program



## 🤔Lesson learned
- Create basic classes
- Usage of `private` and `public` class members
- Implement setters and getters
- How to instantiate a class to create an object
- Use `<iomannip>` to format ::cout output
- Issue with `std::cin`. Use `std::getline` instead

## 🧪Dummy contacts

**1**
``` 
John 
Doe 
Johnny 
012-3456789 
I once ate an entire pizza in one sitting
```

**2**
``` 
Jane 
Smith 
Janey
017-9876543
I secretly love reality TV
``` 

**3**
``` 
David 
Lee 
Dave 
019-1234567 
Im afraid of clowns
``` 

**4**
``` 
Sarah 
Jones 
Sally 
014-7654321 
I once sang karaoke in public and sounded terrible
``` 

**5** 
``` 
Michael 
Brown 
Mike 
016-8765432
I still sleep with a teddy bear
``` 

**6**
``` 
Emily 
Davis 
Em 
011-2345678 
I can whistle
``` 

**7** 
``` 
Daniel 
Moore 
Dan 
013-5432109 
Im secretly a fan of country music
``` 

**8**
``` 
Olivia 
Wilson 
Liv 
018-9012345 
I once tripped and fell in front of a crowd
``` 

**9**
``` 
James 
Taylor 
Jim 
019-6789012 
I can tell a joke to save my life
``` 

**10**
``` 
Chloe 
Anderson 
Chloe 
017-4321098 
Im afraid of heights
```