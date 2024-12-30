#include <iostream>

using namespace std;

bool isEqual(int tab1[], int size1, int tab2[], int size2)
{   
    if (size1 != size2)
    {
        return false;
    }else
    {
        for(int i = 0; i < size1; i++)
        {
            if(tab1[i] != tab2[i])
            {
                return false;
                break;
            }
        }
        return true;
    }
}

int main()
{
    int arr1[] = { 2, 5, 7, 10 };
    int arr2[] = { 2, 5, 7, 10 };
    int arr3[] = { 2, 5, 9, 10 };
    int arr4[] = { 2, 5, 7 };

    cout << isEqual(arr1, sizeof(arr1)/sizeof(*arr1), arr2, sizeof(arr2)/sizeof(*arr2));
}