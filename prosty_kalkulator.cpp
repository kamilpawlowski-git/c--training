#include <iostream>

using namespace std;

int main()
{
    int liczba1, liczba2;
    char dzialanie;
    cout << "Wprowadz 2 liczby calkowite oddzielone spacja: ";
    cin >> liczba1 >> liczba2;
    cout << "Wprowadz a dla dodawania,\ns dla odejmowania,\nm dla mnozenia,\nd dla dzielenia." << endl;
    cout << "Twoje dzialanie: ";
    cin >> dzialanie;

    switch(dzialanie)
    {
        case 'a':
        cout << liczba1 + liczba2;
        break;
        
        case 's':
        cout << liczba1 - liczba2;
        break;

        case 'm':
        cout << liczba1 * liczba2;
        break;

        case 'd':
        cout << liczba1 / liczba2;
        break;
    }
}