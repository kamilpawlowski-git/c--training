#include <iostream>

using namespace std;

int main()
{
    //0+1 = 1 | 1+1 = 2 | 1+2 = 3 | 2+3 = 5 | 3+5 = 8   0,1,1,2,3,5,8,13,21,34..

    int N;
    cout << "Podaj liczbe: ";
    cin >> N;
    
    int sum = 0;
    int result;
    for(int i = 0; i < N; i++)
    {   
        static int number1 = 0;
        static int number2 = 1;

        result = number1 + number2;
        
        sum += result;

        number1 = number2;
        number2 = result;
    }
    cout << sum << " " << result;
    

}