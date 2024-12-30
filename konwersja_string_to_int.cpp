#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string str = "69420 456";
    stringstream ss;
    ss << str;

    int x;
    ss >> x;
    int y;
    ss >> y;
    cout << x << " " << y;
}