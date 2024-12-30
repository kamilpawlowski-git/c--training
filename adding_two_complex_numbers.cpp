#include <iostream>

struct Complex
{
    int re;
    int im;

    Complex operator+(const Complex& rhs)
    {
        Complex lhs;
        lhs.re = this->re + rhs.re;
        lhs.im = this->im + rhs.im;
        return lhs;
    }

    void Print()
{
    std::cout << this->re << " + i" << this->im << std::endl; 
}
};

Complex add(Complex& number1, Complex& number2)
{
    Complex result;
    result = number1 + number2;
    return result;
}

int main()
{
    Complex kamil = { 2, 8 };
    Complex martyna = { 10, 13 };
    Complex result = add(kamil, martyna);
    result.Print();
}