#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include "Level.h"

using namespace std;

class BasicTile : public ITile
{
private:
    char _character;
    bool _canEnter;
public:
    BasicTile(char ch, bool canEnter) : _character(ch), _canEnter(canEnter) {}

    virtual char GetCharacter() { return _character; }
    virtual bool CanEnter(IEntity& entity) { return _canEnter; }
    virtual void Enter(IEntity& entity) { }
};

class BasicEntity : public IEntity
{
private:
    char _character;
    Position _position;

public:
    BasicEntity(char ch) : _character(ch), _position(0, 0) {}
    virtual char GetCharacter() { return _character; }
    virtual Position& GetPosition() { return _position; }
    virtual void SetPosition(Position& position) { _position = position; }
    virtual void Collide(IEntity& entity) { } 
};


int main()
{
    Level level(20, 20);
    BasicTile empty(' ', true);
    BasicTile wall('#', false);

    level.SetTiles(empty, Position(0, 0), Position (19, 19));
    level.SetTiles(wall, Position(0, 0), Position(0, 19));
    level.SetTiles(wall, Position(0 ,0), Position(19, 0));
    level.SetTiles(wall, Position(19, 0), Position(19, 19));
    level.SetTiles(wall, Position(0, 19), Position(19, 19));

    BasicEntity player('$');
    level.SetEntity(player, Position(1, 1));

    char input;

    level.RenderAll();
    while((input = _getch()) != 27)
    {
        auto pos = player.GetPosition();
        if(input == 'w' || input == '\x18')
            level.MoveEntity(player, Position(pos.GetX(), pos.GetY() - 1));
        else if(input == 'a' || input == '\x19')
            level.MoveEntity(player, Position(pos.GetX() - 1, pos.GetY()));
        else if(input == 's' || input == '\x1B')
            level.MoveEntity(player, Position(pos.GetX(), pos.GetY() + 1));
        else if(input == 'd' || input == '\x1A')
            level.MoveEntity(player, Position(pos.GetX() + 1, pos.GetY()));
        
    } 

    cin.get();
    return 0;
}