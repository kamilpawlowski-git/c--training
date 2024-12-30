#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
    public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

    YouTubeChannel ()
    {
        Name = "No-identified";
        OwnerName = "No-identified";
        SubscribersCount = 0;
        PublishedVideoTitles = {"No videos yet"};
    }

    YouTubeChannel (string name, string ownerName, int sub_count, list<string> videoTitles)
    {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = sub_count;
        PublishedVideoTitles = videoTitles;
    }

    void printFunction(void)
    {
        cout << "Name: " << Name << endl;
        cout << "OwnerName: " << OwnerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "Tiltes: ";
        for(string videoTitle : PublishedVideoTitles)
        {
            cout << videoTitle << endl;
        }
    }
};

int main()
{   
    //tradycyjnie nadanie zmiennych
    YouTubeChannel MrCityPL;
    MrCityPL.Name = "MrCityPL";
    MrCityPL.OwnerName = "Kamil Pawlowski";
    MrCityPL.SubscribersCount = 1800;
    MrCityPL.PublishedVideoTitles = {"C++ for beginners Video 1", "HTML & CSS Video 1", "C++ OOP Video 1"};

    //tradycyjne wywolanie
    cout << "Name: " << MrCityPL.Name << endl;
    cout << "OwnerName: " << MrCityPL.OwnerName << endl;
    cout << "SubscribersCount: " << MrCityPL.SubscribersCount << endl;
    cout << "Titles: ";
    for(string videoTitle : MrCityPL.PublishedVideoTitles)
    {
        cout << videoTitle << endl;
    }
    
    //tradycyjne nadanie zmiennych
    YouTubeChannel ReziPlayGames;
    ReziPlayGames.Name = "ReziPlayGames";
    ReziPlayGames.OwnerName = "Remigiusz Wierzgon";
    ReziPlayGames.SubscribersCount = 2000000;
    ReziPlayGames.PublishedVideoTitles = {"Minecraft na Modach", "Outlast 2" , "Kwadratowa Masakra"};

    //tradycyjne wywolanie
    cout << "Name: " << ReziPlayGames.Name << endl;
    cout << "OwnerName: " << ReziPlayGames.OwnerName << endl;
    cout << "SubscribersCount: " << ReziPlayGames.SubscribersCount << endl;
    cout << "Titles: ";
    for (string videoTitle : ReziPlayGames.PublishedVideoTitles)
    {
        cout << videoTitle << endl;
    }

    //nadanie zmiennych przez konstruktor
    YouTubeChannel Blowek ("Blowek", "Karol Gazwa", 35000000, {"Survival Games", "Cynamon Challange", "Meet-up Krakow"});

    //pokazanie danych poprzez metode
    Blowek.printFunction();
    


}