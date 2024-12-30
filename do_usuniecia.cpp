#include <iostream>
#include <string>

using namespace std;

class kalkulator
{
private:
    int& _ilosc_przyciskow;
public:
    //dobre rozwiazanie, dziala
    kalkulator(int& przyciski) : _ilosc_przyciskow(przyciski) {}
    
    //zle rozwiazanie nie dziala, bo referencja musi byc zainicjalizowana
    /*
    kalkulator(int& przyciski)
    {
        _ilosc_przyciskow = przyciski;
    }
    */
};

int main()
{       

}