#include <iostream>

using namespace std;

void swap(int& x, int& y)
    {
        int temp;
        temp = x;
        x = y;
        y = temp;
    }

int main(){
    
    int a = 5;
    int b = 10;

    cout << a << endl;
    cout << b << endl;
    
    swap(a, b);

    cout << a << endl;
    cout << b << endl;

}