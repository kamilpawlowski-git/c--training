#include <iostream>
#include <fstream>

int main()
{
    std::ofstream file;

    file.open("moj_plik.txt");

    if(!file.is_open())
    {
        std::cout << "error in file creation" << std::endl;
        return 1;
    }
    std::cout << "file created successfully" << std::endl;

    file.close();
    return 0;

}