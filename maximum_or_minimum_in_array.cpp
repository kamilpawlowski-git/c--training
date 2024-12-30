#include <iostream>

using namespace std;

int maximum(int tab1[], int size)
{
    int max = tab1[0];
    for(int i = 0; i < size; i++)
    {
        if(max < tab1[i])
        {
            max = tab1[i];
        }
    }
    return max;
}

int minimum(int tab1[], int size)
{
    int min = tab1[0];
    for(int i = 0; i < size; i++)
    {
        if(min > tab1[i])
        {
            min = tab1[i];
        }
    }
    return min;
}

int main()
{
    int array[] = { 2, 3, 6, 10, 212, 1, 26, 15 };
    int size = sizeof(array)/sizeof(*array);
    cout << maximum(array, size) << endl;
    cout << minimum(array, size) << endl;

}