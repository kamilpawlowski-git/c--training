#include <iostream>

using std::cout, std::endl;


int SetValue(const int& value)
{   
    return value;
}

void printName(const std::string& name)
{
    cout << name << endl;
}

int main()
{
    int i = 10;
    int a = SetValue(i);
    int b = SetValue(10); //bez const w argumencie funckji nie ten zapis bedzie bledny, a blad jaki wyskoczy bedzie brzmial: initial value of reference to non-const must be an lvalueC/C++(461), "10" to nie lvalue, mysl: left value, czyli cos co ma swoj adres, "10" nie ma swojego adresu jest wartoscia
    cout << a << " " << b << endl;

    //drugi przyklad
    std::string firstName = "Kamil";
    std::string lastName = "Pawlowski";
    std::string fullName = firstName + lastName;
    printName(fullName);
    printName(firstName + lastName); //bez const w argumencie funkcji to nie bedzie dzialac, bo znowu zmienna musi miec adres pamieci, to wyrazenie sklada sie z dwoch zmiennych ulokowanych w roznych adresach pamieci


}