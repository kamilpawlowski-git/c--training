#include <iostream>

using namespace std;

class Smartphone
{   
    public:
        virtual void TakeASelfie() = 0;
        virtual void MakeACall() = 0;
};  

class Android : public Smartphone
{
    void TakeASelfie()
    {
        cout << "Android selfie taken\n";
    }

    void MakeACall()
    {
        cout << "Android called" << endl;
    }
};

class iPhone : public Smartphone
{
    void TakeASelfie()
    {
        cout << "iPhone selfie taken\n";
    }

    void MakeACall()
    {
        cout << "iPhone called" << endl;
    }
};

int main()
{
    Smartphone* s1 = new Android();
    s1->TakeASelfie();
    s1->MakeACall();

    Smartphone* s2 = new iPhone();
    s2->TakeASelfie();
    s2->MakeACall();
}