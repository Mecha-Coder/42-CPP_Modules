#include <iostream>
#include <list>
using namespace std;

/*
Method
========
- describe the behaviour of an object
- it's just a function inside class

Constructor
===========
- A special method that will be invoke each time we create an object
- Constructor has the same name as the class
- Make initializing the data easier
- No return type
*/

class YouTubeChannel {
public:
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishVideoTitle;

    YouTubeChannel(string name, string ownerName) {  // <---- creating a constructor
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
    }

    void getInfo() {
        int i = 0;
        cout << "Name      : " << Name << "\n";
        cout << "OwnerName : " << OwnerName << "\n";
        cout << "SubscribeCount : " << SubscriberCount << "\n";
        cout << "Video: \n";
        for(string videoTitle: PublishVideoTitle)
        {
            cout << i << " --> " << videoTitle << "\n";
            i++;
        }
    }
};

int main()
{
    
    YouTubeChannel obj1("Demonology", "The Occult");   //<--- here is how to call the constructor
    obj1.PublishVideoTitle.push_back("Hail satan");
    obj1.PublishVideoTitle.push_back("How to perform blood sacrifice");
    
    YouTubeChannel obj2("Art", "Martin");
    obj2.PublishVideoTitle.push_back("Type of sketches");
    obj2.PublishVideoTitle.push_back("Sketch isometric view");


	
    obj1.getInfo();
    printf("-----------------------------------------------------\n");
    obj2.getInfo();
}
