#include <iostream>

using namespace std;

class Position
{
private:
    int _x;
    int _y;

public:
    int GetX() const { return _x; }
    int GetY() const { return _y; }

    void SetX(int x) { _x = x; }
    void SetY(int y) { _y = y; }
};

void Blegh(const Position& pos)
{
    //pos.SetX(100); // nie mozemy, poniewaz pos jest referencja const nie mozemy nic zmieniac

    Position& pos2 = const_cast<Position&>(pos); //to rozwiazanie jest top, const_cast to takie narzedzie do "rozbrajania" consta, dzieki temu mozemy przypisac adres do innej zmiennej i za jej pomoca wplynac na jej wartosc
    pos2.SetX(100);
}

int main()
{
    Position pos;
    pos.SetX(19);
    pos.SetY(20);

    Blegh(pos);

    cout << pos.GetX();

    cin.get();
    return 0;
}