#include <iostream>

using namespace std;

void spin(int array[], int k, int size)
{
    int new_array[size];
    for(int i = 0; i < size; i++) // 0  1  2  3  4  5
    {
        if((i + k) <= (size - 1))
        {
            new_array[i + k] = array[i];
        }else{
            int index = (k - (size - i));
            new_array[index] = array[i];
        }
    }

    for(int i = 0; i < size; i++)
    {
        cout << new_array[i] << " ";
    }
}

int main()
{
    int array[] = { 10, 11, 7, 33, 5, 1 };
    int k = 3;
    int size = sizeof(array)/sizeof(*array);

    spin(array, k, size);

    
}