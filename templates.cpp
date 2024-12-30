#include <iostream>
#include <string>

//uzywamy kiedy potrzebujemy tej samej funkcji dla rozych typow zmiennych
// template nie istnieje dopoki nie wywolamy funckji, dlatego teoretycznie jesli zrobimy blad skladniowy, ale
// nie wywolamy funkcji wszystko ladnie sie skompiluje

template <typename T> 
void Print(T value)
{
    std::cout << value << std::endl;
}

// 2. warto uzywac z klasami, kiedy mamy tablice, ale nie wiemy ilu elementowna, przyklad pozniej:

template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int GetSize() const { return N; }
};

int main()
{
    Print(5); // moze tez specyfikowac typ: Print<int>(5)
    Print("Hello"); // Print<std::string>("Hello")
    Print(5.5f);

    // 2.
    Array<int, 5> array;
    std::cout << array.GetSize() << std::endl;
}