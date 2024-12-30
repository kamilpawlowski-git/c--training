#include <iostream>

// mysl przewodnia: tablice to pointery!

int main()
{
    int* array = new int[50]; // rezerwacja 50 x 4 (bo int) = 200 bytes pamieci | singledimensional array
    int** a2d = new int*[50]; // tu rowniez | multidimensional array

    array[0] = 2; // array pointeruje na int bo jest int*
    a2d[0] = nullptr; // a2d pointeruje na pointer do int, czytaj to tak: (int*)*

    // tworzenie two dimensional array to nic innego jak utowrzenie tablicy w tablicy
    for(int i = 0; i < 50; i++)
    {
        int* inner_array = new int[50]; // za kazdym razem tworzymy nowa tablice
        a2d[i] = inner_array;
    }

    // jesli chcemy ja usunac nie mozemy zrobic po prostu: delete[] a2d   bo zrobimy memmory leak, nalezy zrobic to tak:
    for(int i = 0; i < 50; i++)
        delete[] a2d[i];
        

    // tworzenie three dimensional array tablica w tablicy w tablicy
    int*** a3d = new int**[50];
    for(int i = 0; i < 50; i++)
    {
        a3d[i] = new int*[50];
        for(int j = 0; j < 50; j++)
        {
            a3d[i][j] = new int[50];
            /* inaczej:
            int** ptr = a3d[i];
            ptr[j] = new int[50];
            */
        }
    }
}