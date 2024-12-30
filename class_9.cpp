#include <iostream>

using namespace std;

class EquilateralTriangle
{
    private:
        float a;
        float circumference;
        float area;
    public:
        void setA(float length)
        {
            a = length;
            circumference = a*3;
            area = (1.73f * a * a) / 4;
        }

        //musimy zadeklarowac ze ta funkcja jest naszym przyjacielem
        friend void printResults(EquilateralTriangle);

        //dla klasy:
        friend class Homework;
        

};

void printResults(EquilateralTriangle et)
{
    cout << "circumference: " << et.circumference << endl;
    cout << "area: " << et.area << endl;
}

class Homework
{
    public:
    void printResults(EquilateralTriangle et)
    {
        cout << "circumference: " << et.circumference << endl;
        cout << "area: " << et.area << endl;
    }
};

int main()
{
    EquilateralTriangle et;
    et.setA(3);
    printResults(et);

    Homework h;
    h.printResults(et);
}

