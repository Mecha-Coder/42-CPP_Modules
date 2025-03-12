#include <iostream>
#include <list>
using namespace std;

/*
classes vs objects
===================
-   class represent a template
-   variable create by that template

class - Fruit (general representation)
object - Apple, Grape, etc.
__________________________________________________________________

Class
=======
constructor & destructor 
& attributes & behaviours

What are attributes - state / data of the object
What are behaviours - take action like mofifty data / print value
-                      just like a function
__________________________________________________________________

syntax to make a class in C++
=============================

class CamelCase   <--- user defined datatype  (similar to struct)
{
	// add members;

}; <-- semicolon

__________________________________________________________________

How to create object after defining your class
==============================================

  ClassName   object_name
-     ↑            ↑           
   datatype     variable
_________________________________________________________________ 

Access member in that object 
============================

object_name.member_name
-          ↑
-        dot(.)
_________________________________________________________________

Member Access (a.k.a Access Modifier)
=============
By default members in a class are set to private
private - member can only be access within the class
public - can access inside and outside the class

class YouTubeChannel
{
public:  <------------ put this to access outside the class
	string Name;
	string OwnerName;
	int SubscriberCount;
};


*/

class YouTubeChannel {
public:
	string Name;
	string OwnerName;
	int SubscriberCount;
	list<string> PublishVideoTitle;
};

int main()
{
	int i = 0;
	YouTubeChannel obj;
	obj.Name = "Demonology";
	obj.OwnerName = "The Occult";
	obj.SubscriberCount = 50000000;
	obj.PublishVideoTitle = {"Demon hierarchy in hell", "How to conjure demons"};

	cout << "Name      : " << obj.Name << "\n";
	cout << "OwnerName : " << obj.OwnerName << "\n";
	cout << "SubscribeCount : " << obj.SubscriberCount << "\n";
	cout << "Video: \n";
	for(string videoTitle: obj.PublishVideoTitle)
	{
		cout << i << " --> " << videoTitle << "\n";
		i++;
	}
}
