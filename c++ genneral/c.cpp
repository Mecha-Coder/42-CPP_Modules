#include <iostream>
#include <list>
using namespace std;

/*
Encapsulation
==============

principle - attribute should be private
We use setters & getter (to expose) to access and maninulate these datas
*/


class YouTubeChannel {
private:  // <------------- hide using private access modifier
    string Name;
    string OwnerName;
    int SubscriberCount;
    list<string> PublishVideoTitle;
public:  // <---------------- expose this to the outside world
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
    void PublishVideo(string title) {PublishVideoTitle.push_back(title);}
};

int main()
{
    YouTubeChannel obj1("CodeBeauty", "Saldina");
    obj1.PublishVideo("C++ for beginners");
    obj1.PublishVideo("HTML & CSS for beginners");
    obj1.PublishVideo("C++ OPP");
    // obj1.Subscribe();
    // obj1.Subscribe();
    // obj1.Subscribe();
    obj1.Unsubscribe();
    obj1.getInfo();
}