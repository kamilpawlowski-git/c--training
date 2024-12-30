#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Inventory
{
    vector<string> _products;

public:
    Inventory(vector<string> products) : _products(products) {}

    void Print()
    {
        for(vector<string>::iterator i = _products.begin(); i != _products.end(); i++)
        {
            cout << (*i) << "\n";
            cout << "NON CONST!\n";
        }
    }

    void Print() const
    {
        for(vector<string>::const_iterator i = _products.begin(); i != _products.end(); i++)
        {
            cout << (*i) << "\n";
            cout << "CONST\n";
        }
    }
};


int main()
{   
    vector<string> initialProducts = {"Kamil", "Michal", "Dominik"};
    Inventory okay(initialProducts);

    okay.Print();
    cin.get();
}