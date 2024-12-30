#include <iostream>

using namespace std;


int main(){
    int a = 5;
    int b = 10;

    void swap(int& x, int& y)
    {
        int temp;
        temp = x;
        y = x;
        x = temp;
    }
    
    swap(a, b);
    cout << a << endl;
    cout << b << endl;
}