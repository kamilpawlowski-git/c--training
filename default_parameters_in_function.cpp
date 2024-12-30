#include <iostream>

using namespace std;

int add(int a, int b, int c = 10) //default parametry zawsze na koncu, jesli dalibysmy int a = 3 i reszte zostawili taka samo wyskoczy nam blad
{
    return a + b + c;
}

int GetInt()
{
    return 10;
}

int GetInt(int a = 10)
{
    return a;
}


int main()
{
    cout << add(2, 4) << endl; //przy default parameter nie musimy podawac go w wywolaniu funckji, chyba ze chcemy go nadpisac (przyklad nizej)
    cout << add(2, 6, 25) << endl;

    //cout << GetInt() << endl; //bedzie blad, c++ nie wie ktorej funkcji ma uzyc
}