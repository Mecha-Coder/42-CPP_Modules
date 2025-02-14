#include "Animal.hpp"

//---------------------------------------------------------------------
// Constructor & Destructor

Animal::Animal() :type("<blank>")  
{cout << "Animal: default constructor called\n";}

Animal::~Animal() {cout << "Animal: destructed\n";}

//---------------------------------------------------------------------
// Methods

void Animal::makeSound()const {cout << "Animal: random sound\n";}
string Animal::getType() const {return this->type;}
