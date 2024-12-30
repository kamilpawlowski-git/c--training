#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork()
{
    using namespace std::literals::chrono_literals; // potrzebne do: std::this_thread::sleep_for(1s);

    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
  
    while(!s_Finished)
    {
        std::cout << "Working..\n";
        std::this_thread::sleep_for(1s); // do aktualnego watku zeby po zrobieniu cout: Working.. nic nie robil przez 1s czyli 1 sekunde
    }
    
}

int main()
{
    std::thread worker(&DoWork);

    std::cin.get();
    s_Finished = true;

    worker.join(); // czeka na skonczenie poprzedniego watku
    std::cout << "Thread id: " << std::this_thread::get_id() << std::endl;
    std::cout << "Finished" << std::endl;

    std::cin.get();
}