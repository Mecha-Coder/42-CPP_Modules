/

--> data_type* pointer_variable = new data_type;

// Allocates memory for an integer
int* ptr = new int;
*ptr = 10;

// Allocates memory for a double and initializes it with 3.14
double* dptr = new double(3.14);

// Allocates memory for an object of class
MyClass* obj = new MyClass();

// Allocates an array of 10 integers
int* arr = new int[10];

// release memory
delete ptr; 
delete dptr; 
delete obj; 
