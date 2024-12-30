#include <iostream>
#include <string>

using namespace std;

int addBinary(string a, string b)
{
    int A = stoi(a, 0, 2); //(string, pozycja od ktorej zaczynamy, (system binarny; osemkowy; dziesietny; szesnastkowy itd))
    int B = stoi(b, 0, 2);
    cout << A << endl;
    cout << B << endl;
    return A + B;

}

int main()
{
    string a = "11";
    string b = "1";
    cout << addBinary(a, b);
}