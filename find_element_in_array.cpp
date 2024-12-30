#include <iostream>

using namespace std;

int find(int number, int tab[], int size)
{
    int index;
    for(int i = 0; i < size; i++)
    {
        
        if(tab[i] == number)
        {
            index = i;
            break;
        }else{
            index = -1;
        }
    }
    return index;
}




int main()
{
    int arr[] = { 1, 8, 10, 16, 4, 2 };
    int size = sizeof(arr)/sizeof(*arr);
    cout << find(4, arr, size);

}