#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int d = 2;

    std::vector<int> v = { 2, 7, 13, 14, 23 };
    std::for_each(v.begin(), v.end(), [d /* &d */](int x)
    {
        if(x % d == 0)
        {
            std::cout << x << " is divisible by " <<  d << std::endl;
        }else
        {
            std:: cout << x << " is not divisible by " <<  d << std::endl;
        }
        //jesli chcemy zmodyfikowac "d" musimy podac d jako referencje komentarz wyzej w kwadratowym nawiasie
        // d = 10; <--- OKAY
    });

    
}