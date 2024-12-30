#include <iostream>

using namespace std;

void change(int* x)
{
    *x = 22;
}

int main()
{
    int x = 5;
    int* y = &x;
    
    cout << y << endl; //adres zmiennej "x"
    cout << *y << endl; //wartosc zmiennej "x", czyli 5
    cout << &y << endl; //adres zmiennej "y", w ktorej przechowywane sa informacje na temat zmiennej "x"

    //jesli chcemy zmienic na co wskazuje zmienna "y", to robimy to w takk sposob:
    int z = 10;
    y = &z;
    cout << y << endl; //adres zmiennej "z"
    cout << *y << endl; //wartosc zmiennej "z", czyli 10
    cout << &y << endl; // adres zmiennej "y", w ktorej przechowywane sa informacje na temat zmiennej "z"

    //wykorzystanie fukcnji change
    int siema = 5;
    change(&siema); //podaje adres do zmiennej "siema" do fukcji "change"
    cout << siema << endl;

    //alokowanie dynamiczne pamieci
    int* temperature = new int(31); //dajemy na heap
    cout << *temperature << endl; //pokaze sie wartosc zmiennej, czyli "31"
    cout << temperature << endl; //dostanie adres pamieci na ktora wskazuje zmienna
    delete temperature; //jestesmy odpowiedzialni za zwolenienie pamieci podczas uzywania dynamicznego alkowania pamieci
    


}