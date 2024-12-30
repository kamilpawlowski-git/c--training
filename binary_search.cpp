#include <iostream>

using namespace std;

int binarySearch(int* array, int size, int x)
{   
    int index = (size - 1)/2;
    cout << "size: " << size << endl;
    cout << "index: " << index << endl;
    while(array[index] != x)
    {
        static int count = 0;
        if(array[index] > x)
        {   
            size = index; //4
            index /= 2; //2
            cout << "index in if: " << index << endl;
        }else
        {
            index = (index + size)/2;
            cout << "index in else: " << index << endl;
        }
        count++;
        if(count > size/2)
        {
            cout << "nie ma takiej liczby" << endl;
            index = -1;
            break;
        }
    }
    return index;
}

int main()
{   
    //               0   1  2    3   4   5   6   7     8    9    10   11   12   13   14   15
    int array[] = { 10, 20, 30, 50, 60, 80, 110, 130, 140, 170, 190, 200, 220, 230, 240, 250 };
    int size = sizeof(array)/sizeof(*array);
    cout << binarySearch(array, size, 220);
}