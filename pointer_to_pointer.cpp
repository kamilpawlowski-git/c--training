#include <iostream>

using namespace std;


void printData(int size, char** data)
{
    for(int i = 0; i < size; i++)
    {
        cout << data[i] << endl;
    }
}
int main()
{
    int x = 10;
    int* p = &x;
    int** q = &p;

    cout << "adres x: " << &x << endl; 
    cout << "p: " <<  p << endl; //adres x
    cout << "q: " << q << endl; //adres p
    cout << "*p: " << *p << endl; //10
    cout << "*q: " << *q << endl; //adres x

    //pierwszy przyklad
    char* data[] = { "Hello my name is Caleb", "You're a Subscriber" };
    printData(sizeof(data)/sizeof(*data), data); //sizeof(data) = 16, bo przechouje jakby 2 adresy, sizeof(*data) = 8, bo przechouje adres tylko adresu data
    
    

}