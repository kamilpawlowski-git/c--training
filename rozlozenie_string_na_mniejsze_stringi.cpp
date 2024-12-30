#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void simple_tokenizer(string s)
{
    stringstream ss(s);
    cout << "ss: " << s << endl;
    string word;
    while(ss >> word)
    {
        cout << word << endl;
    }
}

int main()
{
    string str("Kamil Pawlowski najlepszy napasatnik Polski");
    simple_tokenizer(str);
}