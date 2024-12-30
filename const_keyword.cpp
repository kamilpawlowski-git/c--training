#include <iostream>
#include <string>

using namespace std;

class Person
{
    const int _age; //nie mozna zmienic po zainizjalizowaniu

    mutable int whoa; //bez slowka mutable zmienna whoa nie moglaby zostac zmieniona w funckji getage() const, slowkiem mutable okrelsmay specjalnie ze ta zmienna moze zostac zmodyfikowana w takiej funkcji

public:
    Person(int age) : _age(age) {} //constructor only by initialization list because of const int _age

    int GetAge() const //nie mozna w funckji const zmieniac zmiennych dopoki nie zostaly one zadeklarowane jako mutable, ewentualnie mozna zadeklarowac  zainicjalizowac lokolanie zmienna i ja zmieniac w tej funkcji
    {   
        int siema;
        siema = 0;
        siema++;
        whoa++; //zmienna whoa jest mutable int
        return _age; 
    }
};

int GetInt(const string& prompt) //dzieki const nie mozemy zmienic tego parametru, w tym przypadku nie chcemy go zmieniac wiec warto go dodac, najlepsza opcja do podawania string'ow w c++
{
    cout << prompt;
    return 10;
}

int main()
{
    Person p1(10);
    Person p2(20);

    cout << p1.GetAge() << endl;
    cout << p2.GetAge() << endl;

    int a = 10;
    int b = 20;

    const int* ptrToConstInt=  &a; // moge zrobic: ptrToConstInt = &b, ale nie nie moge juz zrobic *ptrToConstInt = 30, bo to ma byc stala wartosc, czyli wartosc jest const nie poitner, pointer mozemy zmienic na inny adres
    int* const constIntPtr = &a; // moge zrobic: *constIntPtr = 30, ale nie moge zmienic na co wskazuje pointer: constIntPtr = &b <---- zakazane!
    const int* const constPtrToConstInt = &a; // nie moge ani zmienic jego adresu ani wartosci

    string Kamil = "Kamil";
    GetInt(Kamil);
    GetInt("Kamil"); //bez dodania const do deklaracji parametru funkcji to wywolanie nie byloby mozliwe, usun const a zobaczysz podekreslenie oznaczajce blad

    const Person p3(30);
    cout << p3.GetAge() << endl; // jesli mamy zadeklarowany obiekt ktory jest "const" metoda ktora wykonujmey na tym obieckie rowneiz musimy byc const

}