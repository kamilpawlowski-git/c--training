#include <iostream>
#include <vector>


void HelloWorld()
{
    std::cout << "Hello World" << std::endl;
}

void PrintValue(int value)
{
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)) // dzieki function pointer moge podac funkcje jako parametr
{
    for(int value : values)
        func(value);
}

int main()
{
    auto function = HelloWorld; // to: HelloWorld() nie dziala, bo funkcja zwraca void, inaczej nic, czemu
                                // w takim razie dziala: HelloWorld ? bo tak naprawde robimy to: &HelloWorld,
                                // bierzemy adres pamieci naszej funkcji
    void(*kamil)(); // alternatywny zapis tego co zrobilismy na latwizne za pomoca auto, void bo nasza funkcja 
                    // zwraca typ void; *kamil, bo skoro bierzemy adres naszej funkcji to musi to byc pointer
                    // kamil jest nazwa zmiennej (wiem, dziwna skladnia), ostatnie () zostawiam puste bo rowniez
                    // w naszej funkcji nie ma zadnych parametrow
    kamil = HelloWorld; // opcjonalnie: kamil = &HelloWorld (chyba tak bede wolal)

    function();
    function();

    // przyklad z zycia
    std::vector<int> values = { 1, 2, 3, 4, 5 };
    ForEach(values, PrintValue);
}