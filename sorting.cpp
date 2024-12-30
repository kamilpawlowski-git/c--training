#include <iostream>
#include <vector>
#include <algorithm> // std::sort
#include <functional> // std::greater

int main()
{
    std::vector<int> values = { 3, 5, 1, 4, 2 };
    std::sort(values.begin(), values.end(), std::greater<int>()); 

    for(int value : values)
        std::cout << value << std::endl;
}