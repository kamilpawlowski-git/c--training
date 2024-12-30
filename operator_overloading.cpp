#include <iostream>

using namespace std;

int main()
{
    class Point
    {
        public:
        int x;
        int y;

        //domyslne wartosci (patrz p10)
        Point ()                            //Point() : x{6}, y{9} {}
        {
            x = 6;
            y = 9;
        }

        //konstruktor (patrz p20)
        Point(int a, int b)                 //Point() : x{a}, y{b} {}
        {
            x = a;
            y = b;
        }


        Point operator + (const Point& p2)
        {
            Point p;
            p.x = x + p2.x;
            p.y = y + p2.y;
            return p;
        }

        //chcialem zrobic normalnego cout, ale wyskakuje blad z "<<", trzeba robic metode
        void printPoint()
        {
            cout << "x: " << x << " y: " << y << endl;
        }
    };

    Point p1;
    p1.x = 1;
    p1.y = 2;
    Point p2;
    p2.x = 5;
    p2.y = 10;

    Point p_result = p1 + p2;

    //metode zawsze wywolujemy na obiekcie, w tym przypadku na "p_result"
    p_result.printPoint();

    Point p10;
    p10.printPoint();

    Point p20(24, 7);
    p20.printPoint();

}