#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string liczba;
    cin >> liczba;
    cin.ignore();

    //przypadek kiedy liczba ma parzysta liczbe cyfr

    for(int i = 0; i < liczba.size(); i++)
    {
        int count = 0;
        if(liczba[i] != liczba[liczba.size() - 1 - i])
        {
            cout << liczba << " nie jest palindromem";
            break;
        }
        else if((liczba[i] == liczba[liczba.size() - 1 - i]) && (i != liczba.size() - 1))
        {
            continue;
        }
        else
        {
            cout << liczba << " jest palindromem";
        }
    }
}