#include <iostream>

using namespace std;

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{   
    int number1 = 22;
    int* ptr1 = &number1;
    int number2  = 10;
    int* ptr2 = &number2;

    swap(*ptr1, *ptr2);

    cout << "a: " << number1 << " " "b: " << number2 << endl;

}