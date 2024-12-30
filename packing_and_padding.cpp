#include <iostream>

#pragma pack(1) //pragma pack(1) sluzy do ograniczenia zuzycia pamieci

using namespace std;

int main()
{
    struct Base{
        char a; //1 byte
        char b; //1 byte
        int i; //4 bytes     //razem 6 bytes prawda? tylko wtedy jesli pragma pack jest wlaczony, zakomentuj pragma
                             //pack i zobacz co sie stanie, bedzie 8 byte pamiec bedzie wygladac nastepujaco:
                             //a|b|-|-|i|i|i|i, przy pragma packu wyglada tak: a|b||i|i|i|i
    };

    cout << sizeof(Base) << endl;

}
