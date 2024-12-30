#include <iostream>

struct Vector2
{
    float x, y;
};

struct Vector4
{
    union // ma tylko pamiec przeznaczona na jednego czlonka 
    {   
        struct // pierwszy czlonek ( 4 x 4bytes = 16 bytes )
        {
            float x, y, z, w;
        };
        struct // drugi czlonek ale okupujacy dokladnie ta sama pamiec co pierwszy czlonek ( 2obj x 8bytes = 16bytes )
        {
            Vector2 a, b; // a odpowiada pamieci x,y      b odpowiada pamieci z,w
        };
    };
};

void PrintVector(const Vector2& vector)
{
    std::cout << vector.x << ", " <<  vector.y << std::endl;
}

int main()
{
    Vector4 obj;
    obj = { 1.0f, 2.0f, 3.0f, 4.0f };
    
    PrintVector(obj.a);
    PrintVector(obj.b);

}