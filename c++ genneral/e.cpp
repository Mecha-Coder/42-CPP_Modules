#include <iostream>
#include <list>
using namespace std;

/*
Polymorphism
==============
- multiple forms
- using the parent class to access child class member (the use of pointers)

How to use object pointers
==============================
YouTubeChannel *test1 = &obj1;
test1->member_name();
}
*/


class YouTubeChannel {
private:  
    string Name;
    int SubscriberCount;
    list<string> PublishVideoTitle;
protected:
    string OwnerName;
    int contentQuality;
public:
    YouTubeChannel(string name, string ownerName) {
        Name = name;
        OwnerName = ownerName;
        SubscriberCount = 0;
        contentQuality = 0;
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
    void checkAnalytics()
    {
        if (contentQuality < 5)
            cout <<  Name << " has bad video quality\n";
        else
            cout << Name << " has a great content\n";
    }
};

class CookingYouTubeChannel : public YouTubeChannel {
public:
    CookingYouTubeChannel(string name, string ownerName)
    : YouTubeChannel(name, ownerName) {}

    void Practice()
    {
        cout << OwnerName  << " is practice cooking, learn new recipe...\n";
        contentQuality++;
    }
};

class SingingYouTubeChannel : public YouTubeChannel {
public:
    SingingYouTubeChannel(string name, string ownerName)
    : YouTubeChannel(name, ownerName) {}

    void Practice()
    {
        cout << OwnerName  << " is taking singing class, learn new song...\n";
        contentQuality++;
    }
};

int main()
{
    CookingYouTubeChannel obj1("Amy's Kitchen", "Amy");
    SingingYouTubeChannel obj2("JohnSings", "John");

//     obj1.PublishVideo("Apple Pie");
//     obj1.PublishVideo("Chocolate cake");
//     obj1.Subscribe();
//     obj1.Subscribe();
//     obj1.getInfo();
    obj1.Practice();
    obj2.Practice();
    obj2.Practice();
    obj2.Practice();
    obj2.Practice();
    obj2.Practice();

    YouTubeChannel *test1 = &obj1;
    YouTubeChannel *test2 = &obj2;

    test1->checkAnalytics();
    test2->checkAnalytics();
}