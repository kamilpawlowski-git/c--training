#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

void decimalToOctal(string& number)
{   
    int manual_size = 8;
    stringstream ss;
    int integer;
    ss << number;
    ss >> integer;
    cout << "integer: " << integer << endl;
    string octal = "";

    int carry;

    while(integer != 0)
    {   
        int _i;
        int _k;
        for(int i = 0; i < manual_size; i++)
        {   
            if(pow(8, i) > integer)
            {
                _i = i - 1;
                cout << "_i: " << _i << endl;
                break;
            }
            
        }
        for(int k = 0; k < manual_size; k++)
        {   
            if(k * pow(8, _i) > integer)
            {
                _k = k - 1;
                cout << "_k: " << _k << endl;
                break;
            }
        }   
        carry = _i;
        octal += to_string(_k);
        integer -= _k * pow(8, _i);    
    }
    cout << "carry: " << carry << endl;
    if(carry != 0)
    {   
        for(int i = 0; i < carry; i++)
        {
            int zero = 0;
            octal += to_string(zero);
        }
        
    }
    cout << "Octal value: " << octal << endl;
    
}

//druga metoda
void decimalToOctal2(string& liczba)
{
    stringstream ss;
    int number;
    ss << liczba;
    ss >> number;
    int array[10];

    int i = 0;
    while(number != 0)
    {
        array[i] = (number % 8);
        number /= 8;
        i++;

    }
for(int j = i - 1; j >= 0; j--)
{
    cout << array[j];
}

}

int main()
{
    string liczba = "256";
    decimalToOctal(liczba);
    decimalToOctal2(liczba);
}