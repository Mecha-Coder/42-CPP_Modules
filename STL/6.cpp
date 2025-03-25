/*
Container - map (key value)
key arrange in ascending order
key need to be unique, while value don't
*/

#include <iostream>
#include <unordered_map> // <map> ordered
#include <map>
#include <list>
#include <string>
using namespace std;

void example1()
{
    unordered_map<int, string> myMap;
    myMap.insert(pair<int, string>(1, "Hello"));
    myMap.insert(pair<int, string>(5, "There"));
    myMap.insert(pair<int, string>(3, "Nice"));
    myMap.insert(pair<int, string>(1, "Day")); // <---did not overwrite

    for (auto pair: myMap)
        cout << pair.first << " - " << pair.second << endl;

    cout << "----------------------------------------\n";

    myMap[1] = "Change this please!";
    myMap.erase(5);
    auto it = myMap.find(3);
    cout << "Try find method: " << it->first << "::" << it->second << endl;

    for (auto pair: myMap)
        cout << pair.first << " - " << pair.second << endl;
}


void example2()
{
    map<string, list<string>> pokedex;
    
    list<string> pikachuAttack = {"thunder shock", "tail whip", "quick attack"};
    list<string> charmanderAttack = {"flame thrower", "scary face"};
    list<string> chikoritaAttack = {"razor leaf", "poison powder"};

    pokedex.insert(pair<string, list<string>>("Pikachu", pikachuAttack));
    pokedex.insert(pair<string, list<string>>("Charmander", charmanderAttack));
    pokedex.insert(pair<string, list<string>>("Chikorita", chikoritaAttack));

    for (auto pair: pokedex) 
    {
        cout << pair.first << " - ";
        for (auto attack:pair.second)
            cout << attack << ", ";
        cout << endl;
    }
}

int main()
{
    example1();
    //example2();  
}