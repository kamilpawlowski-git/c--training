#include <iostream>
#include <string>
#include <list>

using namespace std;

class car
{
    public:
        int price;

        car operator + (const car &any_car)
        {
            car final;
            final.price = price + any_car.price;
            return final;
        }

        void printPrice()
        {
            cout << price << endl;
        }
};

struct YouTubeChannel
{
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount)
    {
        Name = name;
        SubscribersCount = subscribersCount;
    }
};

ostream& operator << (ostream& COUT, YouTubeChannel& ytChannel)
{
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}

struct MyCollection
{
    list<YouTubeChannel> myChannels;

    void operator += (YouTubeChannel& channel)
    {
        this->myChannels.push_back(channel);
    }
};

void operator << (ostream& COUT, MyCollection collection)
{
    for(YouTubeChannel one_by_one : collection.myChannels)
    {
        COUT << one_by_one << endl;
    }
}

int main()
{   
    //class car
    car porsche911;
    porsche911.price = 1200;

    car bwmz4;
    bwmz4.price = 2400;

    car how_much = porsche911 + bwmz4;

    how_much.printPrice();

    //struct YouTubeChannel
    YouTubeChannel yt1 = YouTubeChannel("CodeBeauty", 75000);
    cout << yt1;
    //operator<<(cout, yt1); //drugi sposob na wywolanie tego co linijka wyzej, skomplikowane jak cholera

    YouTubeChannel yt2 = YouTubeChannel("My second channel", 80000);

    cout << yt1 << yt2;

    //struct MyCollections
    MyCollection myCollection;
    myCollection += yt1;
    cout << myCollection;
    
}