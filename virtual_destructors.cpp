#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base Constructor" << std::endl;
    }
    virtual ~Base() // po co "virtual"?, jesli usune nie wywola sie destruktor class Derived i w przypadku 3. bede mial memory leak'a, bo nie wykona sie polecenie delete[] m_Array
    {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base
{
private:
    int* m_Array;
public:
    Derived()
    {
        m_Array = new int[10];
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived()
    {
        delete[] m_Array;
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main()
{   
    // 1.
    Base* base = new Base();
    delete base;
    std::cout << "---------------" << std::endl;
    // 2.
    Derived* derived = new Derived();
    delete derived;
    std::cout << "---------------" << std::endl;
    // 3.
    Base* poly = new Derived();
    delete poly;

    std::cin.get();

}
/*
wnioski: jesli wiemy ze nasza klasa bedzie mial wykorzystywana do dziedziczenia warto dac virtual destructor
*/