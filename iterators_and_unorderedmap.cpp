#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    for(int i = 0; i < values.size(); i++)
    {
        std::cout << values[i] << std::endl;
    }       

    //to samo co wyzej tylko prosciej i ladniej
    for(int value : values)
        std::cout << value << std::endl;
    
    //to samo tylko trudniej, ale to tojest zriobione "under the hood"
    for(std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
    {
        std::cout << *it << std::endl;
    }


    //unordered_map podstawowa deklaracja
    std::unordered_map<std::string, int> map;
    map["Kamil"] = 5;
    map["C++"] = 2;

    //unordered_map lepsza deklaracja, ze wzgeldu na dlugosc przypisujemy podstawowa deklaracje do "ScoreMap" (jest krocej i szybciej) :D
    using ScoreMap = std::unordered_map<std::string, int>;
    for(ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        const std::string& key = it->first;
        const int& value = it->second;

        std::cout << key << " = " << value << std::endl;
    }

    std::cout << std::endl;

    for(auto kv : map)
    {
        const std::string& key = kv.first;
        const int& value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }

    std::cout << std::endl;

    for(auto [key, value] : map)
    {
        std::cout << key << " = " << value << std::endl;
    }


}