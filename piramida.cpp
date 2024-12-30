#include <iostream>

using namespace std;

void render(int width, int array[])
{   
    float temp = (float)width;
    int size = width * (temp/2 + 0.5);
    for(int i = 0; i < size; i++)
    {   
        cout << array[i] << " ";
        if((i+1) % width == 0)
        {
            cout << endl;
        }
    }
}

int main()
{
   
    int width = 5; 
    int array[] = { 1, 2, 3, 4, 5,
                    6, 7, 8, 9, 10,
                    11, 12, 13, 14, 15 };
    render(width, array);
}