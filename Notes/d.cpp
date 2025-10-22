#include <iostream>
#include <list>
using namespace std;

/*
Inheritance
==============
- inheritance also have access modifier 
- syntax for inheritance

class parent_class : <modifier> child_class 
-               Parent    Child
-               ======   =======
inherit_public  public    public
                protected protected
(Note: Private is alway not able to access)


How to make attribute accessible in the derived class
======================================================
- use protected access modifier

Benefit of inheritance 
- create a general class
- child class is specific 
- car (general) 
|---- electic car
|---- petrol car
*/


class YouTubeChannel {
private:  
    string Name;
    int SubscriberCount;
    list<string> PublishVideoTitle;
protected:
    string OwnerName;
public:
    YouTubeChannel(string name, string ownerName) {
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
    void Subscribe() {SubscriberCount++;}
    void Unsubscribe() 
    {   
        if (SubscriberCount > 0)
            SubscriberCount--;
    }
    void PublishVideo(string title)
    {PublishVideoTitle.push_back(title);}
};

class CookingYouTubeChannel : public YouTubeChannel {
public:
    CookingYouTubeChannel(string name, string ownerName)
    : YouTubeChannel(name, ownerName) {}

    void Practice()
    {cout << OwnerName  << " is practice cooking, learn new recipe...\n";}
};

int main()
{
    CookingYouTubeChannel obj1("Amy's Kitchen", "Amy");
    CookingYouTubeChannel obj2("John's Kitchen", "John");

//     obj1.PublishVideo("Apple Pie");
//     obj1.PublishVideo("Chocolate cake");
//     obj1.Subscribe();
//     obj1.Subscribe();
//     obj1.getInfo();
    obj1.Practice();
    obj2.Practice();
}