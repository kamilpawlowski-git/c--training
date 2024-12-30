#include <iostream>
#include <string>

using namespace std;

struct BoardSquare
{
    enum E
    {
        X,
        O,
        Empty
    };
};

struct WinningPlayer
{
    enum E
    {
        X,
        O,
        Stalemate,
        None
    };
};

class Board
{   
    private:
    int _width;
    BoardSquare::E* _squares;

    public:
    Board(int width) : _width(width)
    {
    _squares = new BoardSquare::E[_width * _width];
    for(auto i = 0; i < GetTotalSquares(); i++)
    {
        _squares[i] = BoardSquare::Empty;
    }
    }

     ~Board()
    {
        delete [] _squares;
    }

    int GetTotalSquares() { return _width * _width; }
    int GetWidth(){ return _width; };

    BoardSquare::E GetSquare(int index)
    {
        return _squares[index];
    }

    void SetSquare(int index, BoardSquare::E square)
    {
        _squares[index] = square;
    }
};

class IRuleEngine
{
    virtual WinningPlayer::E HasWon(Board& board) = 0;  
};

class Game
{
    private:
    Board& _board;
    IRuleEngine& _ruleEngine;

    public:
    Game(Board& board, IRuleEngine& ruleEngine) : _board(board), _ruleEngine(ruleEngine) {}

    WinningPlayer::E Run()
    {
        while(winningPlayer == WinningPlayer);
    
    int input;
    cin >> input;
    cin.ignore();
    }


    private:
    void Render()
    {
        for(auto i = 1; i <= _board.GetTotalSquares(); i++)
        {   
            cout << GetSquareChar(i, _board.GetSquare(i - 1));
            if(i % _board.GetWidth() == 0)
            cout << "\n";
        }
    }
    
    char GetSquareChar(int index, BoardSquare::E square)
    {
        switch(square)
        {
            case(BoardSquare::X) : return 'X';
            case(BoardSquare::O) : return 'O';
        }

        return index + '0';
    }

};

int main()
{

}