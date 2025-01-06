#include <iostream>
#include <fstream> //provide classes for file input/output

/*
- ifstream: read from file
- ofstream: write to file
- fstream : Perform both input output
*/


int main()
{
    {
        int i = 0;
        std::string line;
        std::ifstream myFile("reading.txt");

        if (!myFile)
        {
            std::cerr << "Error. Can't open file" << std::endl;
            return 0;
        }

        while (std::getline(myFile, line) && ++i)
        {
            std::cout 
                << "#" << i << " --> " 
                << line << "\n" 
                << std::endl;
        }

        myFile.close();
    }
    {
        double pie = 3.142;
        std::ofstream myLog("writing.txt");
        
        myLog 
            << "This is some data."
            << " 1.12, "
            << pie
            << std::endl;
        myLog << "Another line of data." << std::endl; 
    }
}
