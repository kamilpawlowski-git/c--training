#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

int binaryToDecimal(string input)
{  
    stringstream ss;
    ss << input;
    int x;
    ss >> x;

    int size = input.size();
    int sum = 0;

    for(int i = 0; i < size; i++)
    {
        int one_or_zero = (x % 10);
        x /= 10;
        sum += one_or_zero * pow(2, i);
    }
    return sum;
}

int main()
{
    string binaryInput = "1011"; // 11 w systemie "10"
    cout << binaryToDecimal(binaryInput);
}