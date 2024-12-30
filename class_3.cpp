#include <iostream>
#include <list>

using namespace std;

class YouTubeChannel
{
    private: //dotepne tylko dla tej klasy
        string Name;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected: //dostepne dla klas dziedziczacych
        string OwnerName;
        int ContentQuality;
    public: //dostepne dla wszystkich
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

        void Subscribe()
        {
            ++SubscribersCount;
            ++ContentQuality;
        }

        void UnSubscribe()
        {
            if(SubscribersCount >= 1)
            {
                --SubscribersCount;
                --ContentQuality;
            }
        }

        void PublishVideo(string title)
        {
            PublishedVideoTitles.push_back(title);
        }

        void CheckAnalytics()
        {
            if (ContentQuality >= 2)
            {
                cout << Name << ": Great content, keep it up" << endl;
            } else {
                cout << Name << ": Try harder my friend" << endl;
            }
        }
};

class CookingYouTubeChannel : public YouTubeChannel
{
    public:
        //konstruktor nie jest bezposrednio dziedziczony, w koncu mozemy miec inne prywatne argumenty, jesli za wszelka cene chcemy konstruktor robimy to tak jak ponizej:
        CookingYouTubeChannel(string name, string ownerName, int sub_count, list<string> videoTitle) : YouTubeChannel(name, ownerName, sub_count, videoTitle) {}
};

int main()
{ 
    YouTubeChannel Blowek ("Blowek", "Karol Gazwa", 35000000, {"Survival Games", "Cynamon Challange", "Meet-up Krakow"});
    Blowek.printFunction();

    Blowek.UnSubscribe();
    Blowek.UnSubscribe();
    Blowek.PublishVideo("Kwadratowa Masakra Sezon 1 Odcinek 3");
    Blowek.printFunction();
    
    CookingYouTubeChannel EwaWachowicz("Ewa Wachowicz Gotuje", "Ewa Wachowicz", 1200, {"W moim malinowym chrusniaku"});
    EwaWachowicz.PublishVideo("Szarolotka mojej babci");
    EwaWachowicz.Subscribe();
    EwaWachowicz.Subscribe();
    EwaWachowicz.UnSubscribe();
    EwaWachowicz.printFunction();

    YouTubeChannel* ptr = &EwaWachowicz;
    YouTubeChannel* second_ptr = &Blowek;

    ptr->CheckAnalytics();
    second_ptr->CheckAnalytics();

}