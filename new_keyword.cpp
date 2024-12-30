#include <iostream>

using namespace std;


class User{
    public:
    string name;
};

int main()
{
    int* x = new int (5);
    cout << "The pointer " << x << " points to " << *x << endl;
    delete x;

    //User u;
    //u.name = "Kamil Pawłowski"; <----- tradycyjny sposob, ale jak to zrobic z "new"? rozwiazanie ponizej:

    //1. sposob
    User* u = new User();
    (*u).name = "Kamil Pawłowski";
    cout << (*u).name << endl;

    //2. sposob
    u->name = "Nie Kamil Pawłowski, tu Martyna Rogozik";
    cout << u->name << endl;

    delete u;
    

}