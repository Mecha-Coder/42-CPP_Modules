#include <iostream>
#include <string>
using namespace std;

/*
Copy constructor vs Assignment operator
========================================

- copy constuction used when you are creating new object based on an existing object

- assignment operator replacing value of existing object based on other object
*/


class Movie{
public:
    string Name;
    string Genre;
    float Rating;
    int ActorCount;
    string *Actors;

    Movie(string name, string genre, float rating) {
        Name = name;
        Genre = genre;
        Rating = rating;
        ActorCount = 0;
        Actors = new string[ActorCount];
    }

    Movie(){
        Name = "";
        Genre = "";
        Rating = 0;
        ActorCount = 0;
        Actors = new string[ActorCount];      
    }

    ~Movie(){
        delete [] Actors;
        Actors = nullptr;
    }

    Movie(const Movie &original){  // <--- Movie(Movie original)  infinate loop because it call itsself
        Name = original.Name;
        Genre = original.Genre;
        Rating = original.Rating;
        ActorCount = original.ActorCount;
        Actors = new string[ActorCount];
        for (int i = 0; i < ActorCount; i++)
            Actors[i] = original.Actors[i];
    }

    Movie& operator=(const Movie &original)
    {    
        if (&original != this)  // <---- prevent self destruction
        {
            Name = original.Name;
            Genre = original.Genre;
            Rating = original.Rating;
            ActorCount = original.ActorCount;
    
            delete [] Actors;
            Actors = new string[ActorCount];
            for (int i = 0; i < ActorCount; i++)
                Actors[i] = original.Actors[i];
        }
        return *this;
    }

    void AddActor(string newActorName)
    {
        string *newActors = new string[ActorCount + 1];
        for (int i = 0; i < ActorCount; i++)
            newActors[i] = Actors[i];
        newActors[ActorCount] = newActorName;
        
        delete [] Actors;
        Actors = newActors;
        ActorCount++;
    }

    void PrintInfo() {
        cout << "Movie: " << Name << "\n";
        cout << "Genre: " << Genre << "\n";
        cout << "Rating: " << Rating << "\n";
        cout << "Actors: " << "\n";
        for (int i=0; i < ActorCount ; i++)
            cout << Actors[i] << "\n";
        cout << "--------------------\n\n";
    }
};

int main()
{
    Movie movie1("The Dark Knight", "Action", 9.5);
    Movie movie2("The Lion King", "Animation", 8);

    movie1.AddActor("Christian Bale");
    movie1.AddActor("Heath Leager");

    Movie movie3;
    Movie movie4(movie1);

    movie4.PrintInfo();

    movie2.AddActor("Saldina Nurak");
    movie2.AddActor("Denzel W.");
    movie2.AddActor("Leo DiCaprio");

    movie4 = movie2;
    //movie4.operator=(movie2)
    movie4.PrintInfo();

    Movie movie5 = movie1;
    movie5 = movie2;
}

