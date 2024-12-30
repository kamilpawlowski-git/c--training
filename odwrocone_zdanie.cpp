#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentance = "Quick brown fox";
    string temp;

    for(int i = 0; i < sentance.size(); i++)
    {
        temp[i] = sentance[sentance.size() - 1 - i];
        cout << temp[i];
    }

}