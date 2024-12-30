#include <iostream>

using namespace std;

void Whoa()
{
    static int count = 0; //gdybym nie dal "static" output bylby 1 1 1 1
    count++;
    cout << count << "\n";
}

int main()
{
    Whoa();
    Whoa();
    Whoa();
    Whoa();

    cin.get();
    return 0;

}