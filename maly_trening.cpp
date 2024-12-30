#include <iostream>

int main()
{
    int i = 1;
    loop:
        std::cout << i << std::endl;
        ++i;
        if(i < 10) 
            goto loop;
}