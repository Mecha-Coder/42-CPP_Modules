#include <iostream>
#include <string>

#define CONTACT_SIZE 8

class Contact
{
    public:
        std::string name;
        std::string phone_number;
    
        Contact(std::string& n, std::string& p) 
            : name(n), phone_number(p) {} 

};


class PhoneBook
{
    private:
        int current;
        Contact *list[8];

    public:
        PhoneBook() : current(0) {} 

        void create_contact(const std::string& name, const std::string& phone_number)
        {
            if (current < 8) 
                list[current++] = new Contact(name, phone_number); 
            else 
            {
                // Handle case where phonebook is full 
                // (e.g., replace oldest contact) 
            }
        }

        ~PhoneBook()
        {
            int i;

            i = -1;
            while (++i < 8) {
                delete list[i]; 
        }
    }
};
