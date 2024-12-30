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
        Stalmate,
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
        _squares = new BoardSquare::E[width * width];
        for(auto i = 0; i < GetTotalSquares(); i++)
        {
            _squares[i] = BoardSquare::Empty;
        }
    }

    ~Board()
    {
        delete [] _squares;
    }

    int GetWidth() { return _width; }
    int GetTotalSquares() { return _width * _width; }

    BoardSquare::E GetSquare(int index) //przyda sie do ocenienia kto wygra
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
    public:
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
        WinningPlayer::E winningPlayer, currentPlayer = WinningPlayer::X;
        while( (winningPlayer = _ruleEngine.HasWon(_board)) == WinningPlayer::None)
        {
            Render();
            cout << "\n";

            int input;
            cout << "Move for " << (currentPlayer == WinningPlayer::X ? 'X' : 'O') << ": ";
            cin >> input;
            cin.ignore();

            input -= 1;
            if (input < 0 || input > _board.GetTotalSquares() || _board.GetSquare(input) != BoardSquare::Empty)
            {
                cout << "Invalid move\n";
                continue;
            }

            _board.SetSquare(input, currentPlayer == WinningPlayer::X ? BoardSquare::X : BoardSquare::O);
            currentPlayer = currentPlayer == WinningPlayer::X ? WinningPlayer::O : WinningPlayer::X;
        }

        return winningPlayer;
    }

    private:
    void Render()
    {
        for(auto i = 1; i <= _board.GetTotalSquares(); i++)
        {
            cout << GetSquareChar(i, _board.GetSquare(i - 1)) << " ";
            if ((i % _board.GetWidth()) == 0)
                cout << "\n";
        }
    }

    char GetSquareChar(int index, BoardSquare::E square)
    {
        switch (square)
        {
            case BoardSquare::X : return 'X';
            case BoardSquare::O : return 'O';
        }

        return index + '0'; //staje sie znakiem ascii
    }
};

class NullRuleEngine : public IRuleEngine
{
    private:
    int GetIndexForXY(int x, int y, int width)
        {
            return y * width + x;
        }

    public:
    virtual WinningPlayer::E HasWon(Board& board)
    {
        // horizontal
        for(int y = 0; y < board.GetWidth(); y++)
        {
            int firstIndex = GetIndexForXY(y, 0, board.GetWidth());
            BoardSquare::E allOfType = board.GetSquare(firstIndex);

            if(allOfType == BoardSquare::Empty)
                continue;

            WinningPlayer::E winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O; 
        
            for(int x = 1; x < board.GetWidth(); x++)
            {
                if(allOfType != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
                {
                    winningPlayer = WinningPlayer::None;
                    break;
                }
            }
            
            if(winningPlayer != WinningPlayer::None)
                return winningPlayer;
        }

        // vertical
        for(int x = 0; x < board.GetWidth(); x++)
        {   
            int firstIndex = GetIndexForXY(x, 0, board.GetWidth());
            BoardSquare::E allOfType = board.GetSquare(firstIndex);

            if(allOfType == BoardSquare::Empty)
                continue;

            WinningPlayer::E winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

            for(int y = 1; y < board.GetWidth(); y++)
            {
                if(allOfType != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
                {
                    winningPlayer = WinningPlayer::None;
                    break;
                }
            }

            if(winningPlayer != WinningPlayer::None)
                return winningPlayer;
        }

        // left cross
        WinningPlayer::E resultLCross = WinningPlayer::None;
        for(int x = 1; x < board.GetWidth(); x++)
        {
            int firstIndex = 0;
            BoardSquare::E allOfType = board.GetSquare(firstIndex);

            if(allOfType == BoardSquare::Empty)
                    break;
            
            WinningPlayer::E winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

            for(int y = 1; y < board.GetWidth(); y++)
            {   
                if(x == y)
                {
                    if(allOfType != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
                    {
                        winningPlayer = WinningPlayer::None;
                        break;
                        // return WinningPlayer::None;
                    }
                }
            }
            if(winningPlayer == WinningPlayer::None)
            {
                resultLCross = winningPlayer;
                break;
            }

            resultLCross = winningPlayer;
        }
        if(resultLCross != WinningPlayer::None)
                return resultLCross;
        
        
        // right cross
        WinningPlayer::E resultRCross = WinningPlayer::None;
        for(int x = 0; x < board.GetWidth() - 1; x++)
        {
            int firstIndex = board.GetWidth() - 1;
            BoardSquare::E allOfType = board.GetSquare(firstIndex);

            if(allOfType == BoardSquare::Empty)
                break;

            WinningPlayer::E winningPlayer = allOfType == BoardSquare::X ? WinningPlayer::X : WinningPlayer::O;

            for(int y = 2; y >= 1; y--)
            {       
                if(x + y == board.GetWidth() - 1)
                {
                    if(allOfType != board.GetSquare(GetIndexForXY(x, y, board.GetWidth())))
                    {
                        winningPlayer = WinningPlayer::None;
                        break;
                    }
                }
            }
            if(winningPlayer == WinningPlayer::None)
            {
                resultRCross = winningPlayer;
                break;
            }
            
            resultRCross = winningPlayer;
        }
        
        if(resultRCross != WinningPlayer::None)
                return resultRCross;
        


        return WinningPlayer::None;
    }
};

int main()
{
    Board board(3);
    NullRuleEngine ruleEngine;
    Game game(board, ruleEngine);

    game.Run();

    return 0;
}