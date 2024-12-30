#include <iostream>

using namespace std;

void sort(int array[], int size)
{
    int count; //chujowo napisane
    while(count != 0)
    {   
        count = 0;
        int last_i;
        for(int i = 0; i < (size - 1); i++)
        {
            if(array[i] > array[i+1])
            {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                count++;
            }
            cout << array[i] << " ";
            last_i = i+1;
        }
        cout << array[last_i] << endl;
    }
}

int main()
{
    int array[] = { 1, 85, 41, 23, 11 };
    int size = sizeof(array)/sizeof(*array);
    sort(array, size);

}