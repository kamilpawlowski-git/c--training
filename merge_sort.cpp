#include <iostream>
#include <string>

using namespace std;

void PrintArray(int array[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
}

void MergeSort(int array[], int size) // 3 4 5 9 12 18 19
{   
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < (size - 1); j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    PrintArray(array, size);
}

int main()
{
    int array[] = { 3, 5, 4, 80, 9, 19, 12, 18 };
    int size = sizeof(array)/sizeof(*array);
    MergeSort(array, size);


}