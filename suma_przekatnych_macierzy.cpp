#include <iostream>
#include <cmath>

using namespace std;

void count_diagonals(int matrix[], int size)
{
    int sum_1 = 0;
    int sum_2 = 0;
    int length = sqrt(size + 1);
    for(int i = 0; i < size; i++) //0, 4, 8
    {   
        if(i % (length + 1) == 0)
        {
            sum_1 += matrix[i];
        }
        if((i % (length - 1) == 0) && i <= length * length - length && i != 0){
            sum_2 += matrix[i];
        }
    }
    cout << sum_1 << " " << sum_2 <<  endl;
}

int main()
{
    int matrix[] = { 1, 2, 3,     //3x3 = 2, 4, 6      //4x4 = 3, 6, 9, 12
                     4, 5, 6,
                     7, 8, 9 };
    int size = sizeof(matrix)/sizeof(*matrix);
    count_diagonals(matrix, size);

    int matrix2 [] = { 1, 2, 3, 4,
                       5, 6, 7, 8,
                       9, 10, 11, 12,
                       13, 14, 15, 16 };
    int size2 = sizeof(matrix2)/sizeof(*matrix2);
    count_diagonals(matrix2, size2);

}