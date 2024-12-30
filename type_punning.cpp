#include <iostream>

// 2.
struct Entity
{
    int x, y;
};

int main()
{
    // 1.
    int a = 50;
    double value = a;
    std::cout << value << std::endl;

    // 2.
    Entity e = { 5, 8 };
    int* position = (int*)&e; // int* position to tak naprawde tablica, utworza sie dwa pointery jeden indeks [0] drugi [1]
    std::cout << position[0] << ", " << position[1] << std::endl;

    //zobacz jak sprawnie i smiesznie mozna sie poruszczac po pamieci
    int z = *(int*)((char*)&e + 4);
    std::cout << z << std::endl;

    //zauwaz ze otrzymalismy 8, dlaczego?
    /*
    otoz bierzemy adres pamieci &e, czyli miejsce w pamieci gdzie zaczyna sie struct, czyli tam gdzie znajduje sie 
    zmienna int x, pozniej zmieniamy ja do char* (char*)&e   (char*) jest wielkosci 1 byte, dodajemy 4 ((char*) + 4) zeby ruszyc sie z pamiecia o 4
    miejsca (zauwaz ze wyladowalismy idealnie na adresie pamieci gdzie jest y ze struct), nastepnie chcemy zeby ten
    pointer byl pointerem typu int (int*)((char*)&e + 4), a na samym koncu chcemy wziac wartosc na ktora wskazuje ten
    pointer czyli dodajemy gwiazke na poczatku *(int*)((char*)&e + 4) i dlatego mamy 8 czyli wartosc pamieci w ktorej
    znajduje sie y ze structa :D
    */
}