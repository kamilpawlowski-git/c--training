#include <iostream>

using namespace std;

char GetSquareChar(int index, BoardSquare::E square)
    {
        switch(square)
        {
            case(BoardSquare::X) return 'X';
            case(BoardSquare::O) return 'O';
        }

        return index + '0';
    }

int main()
{
    int zmienna = 1;

    cout << GetSquareChar(zmienna);
}