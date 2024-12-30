#include <iostream>

using namespace std;

class Instrument
{
    public:
        //virtual powoduje ze wykonuje sie metoda ktora nie jest virtual (ta znajduje sie dalej w klasach ktore dziedziczyly), jesli nie ma innej niz virtual wykonuje sie virtual
        virtual void MakeSound()
        {
            cout << "Instrument is playing...\n";
        }
};

class Accordion : public Instrument
{
    void MakeSound()
    {
        cout << "Accordian is playing...\n";
    }
};

class AnimalNoise
{
    public:
        //pure virtual function = abstract class because there has to be at least one virtual class to aquire that naming
        virtual void MakeSound() = 0;
};

class Bear : public AnimalNoise
{
    public: 
    void MakeSound()
    {
        cout << "fuck" << endl;
    }
};

int main()
{
    Instrument* i1 = new Accordion();
    //Instrument i1; //to nie jest to samo! co linijka wyzej! nie robi tego samego
    //Accordion i1; //to rozwiazanie to tez nie to samo chyba ze damy public dla MakeSound w class Accordion
    i1->MakeSound();

    //pokazuje blad ale dziala
    AnimalNoise* ptr = new Bear();
    ptr->MakeSound();

}

