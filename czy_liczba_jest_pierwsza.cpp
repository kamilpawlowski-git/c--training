#include <iostream>

using namespace std;

int main()
{
    //2,3,5,7,11,13,17,19
    int liczba_pierwsza;
    cin >> liczba_pierwsza;
    cin.ignore();

    int count = 0;
    for(int i = 1; i <= liczba_pierwsza; i++)
    {   
        if( (liczba_pierwsza % i) == 0)
        {
            ++count;
        }
    }
    
    if(count == 2)
    {
        cout << liczba_pierwsza << " jest liczba pierwsza";
    }else
    {
        cout << liczba_pierwsza << " nie jest liczba pierwsza";
    }

    return 0;
}