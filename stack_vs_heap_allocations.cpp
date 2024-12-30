#include <iostream>

struct Vector3
{
    float x, y, z;
};

int main()
{
    int value = 5; //stack
    
    //heap
    int* hvalue = new int; //opcjonalnie: int* hvalue = new int(10);
    *hvalue = 5;
    
    //heap array
    int* harray = new int[5];

    //heap object
    Vector3* hvector = new Vector3;

    /*
    wnioski:
    alokacja na stacku jest szybsza, czemu? bo ustawiamy wszystko jedno za drugim "stackujemy" jak w minecraftcie
    dane jedna po drugiej
    duzo wiecej instrukcji potrzeba do alokacji na heapie niz na stacku, alokowanie na stacku to jedna instrukcja
    heap: wolniejszy, ale: 1)zywotnosc danych zalezy od nas, to my musimy zwolnic pamiec, 2)dynamiczna alokacja,
    kiedy nie znamy rozmiaru danych (bo np. to uzytkownik cos wpisuje) lepiej dac na heap, 3)duze struktury danych
    na heap, bo na stacku ejst ograniczona wielkosc, 4)
    */


}