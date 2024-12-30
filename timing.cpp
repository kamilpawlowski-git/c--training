#include <iostream>
#include <chrono>
#include <thread>

struct Timer
{
    std::chrono::high_resolution_clock::time_point start, end;
    std::chrono::duration<float> duration;

    Timer()
    {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer()
    {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;

        float ms = duration.count() * 1000.0f;
        std::cout << "Timer took " << ms << "ms" << std::endl;
    }
};

void Function()
{
    Timer timer;

    for(int i = 0; i < 100; i++)
        std::cout << "Hello" << std::endl;
}

int main()
{
    /*
    using namespace std::literals::chrono_literals;

    auto start = std::chrono::high_resolution_clock::now(); // zapisuje do zmiennej obecny czas
    std::this_thread::sleep_for(1s); // usypia program na jedna sekunde
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << "s" <<  std::endl;
    */

    Function(); // do zmierzenia ile cos czasu zajmuje (w naszym wypadku do zobaczenia ile czasu potrzeba na 100 razy)
    //printownie "Hello" lepiej uzyc struktury, ktora czas rozpoczecia zawiera w konstruktorze, a czas zakonczenia w 
    //destruktorze struktury
    
    std::cin.get();
}