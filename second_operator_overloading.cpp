#include <iostream>
#include <string>

using namespace std;

class Vector2
{
private:
    float _x, _y;

public:
    Vector2(float x, float y) : _x(x), _y(y) {}
    Vector2()
    {
        _x = 0;
        _y = 0;
    };

    float GetX() const { return _x; }
    float GetY() const { return _y; }

    Vector2 operator + (const Vector2& rhs)
    {
        Vector2 result;
        result._x = _x + rhs._x;
        result._y = _y + rhs._y;
        return result;
    }

    Vector2 operator - (const Vector2& rhs)
    {
        Vector2 result;
        result._x = _x - rhs._x;
        result._y = _y - rhs._y;
        return result;
    }

    bool operator == (const Vector2& rhs) const
    {
        if(_x == rhs._x && _y == rhs._y)
            return true;

        return false;
    }

    Vector2& operator += (const Vector2& rhs)
    {
        _x += rhs._x;
        _y += rhs._y;
        return *this; 
    }

    Vector2& operator ++ () // <- prefix
    {
        cout << "PREFIX\n";
        _x++;
        _y++;
        return *this;
    }

    //pierwszy sposob
    /* 
    Vector2& operator ++ (int) // <- postfix, (int) to tylko skladnia
    {
        cout << "POSTFIX\n";
        _x++;
        _y++;
        return *this;
    }
    */
    
    //drugi sposob
    Vector2 operator ++ (int)
    {
        Vector2 result(*this);
        operator ++ (); //uzycie funkcji z prefix
        return result;
    }
};  

ostream& operator << (ostream& out, const Vector2& rhs)
{
    out << "(" << rhs.GetX() << ", " <<  rhs.GetY() << ")";
    return out;
}

int main()
{
    Vector2 myObject1(1.0f, 2.0f);
    Vector2 myObject2(1, 2);

    Vector2 result = myObject1 + myObject2;
    cout  << result.GetY() << endl;

    
    bool isTrue = (myObject1 == myObject2);
    cout << "Is it true?: " << isTrue << endl;
    
    Vector2 vec;
    ++vec;
    vec++;

    cout << vec.GetX() << "\n" << vec.GetY() << endl;

    Vector2 vect(2, 2);
    cout << vect;
    
    return 0;
}