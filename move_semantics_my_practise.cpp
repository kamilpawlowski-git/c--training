#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    int m_Size;
    char* m_Data;

public:
    String() = default;
    String(const char* string)
    {
        cout << "Created!" << endl;
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String& other)
    {
        cout << "Copied!" << endl;
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    String(String&& other) noexcept
    {
        cout << "Moved!" << endl;
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }
    ~String()
    {
        cout << "Destroyed!" << endl;
        delete m_Data;
    }
    
    void Print()
    {
        for(int i = 0; i < m_Size; i++)
        {
            cout << m_Data[i];
        }
    }
};

class Entity
{
private:
    String m_Name;

public:
    Entity(const String& name) : m_Name(name) {}
    Entity(String&& name) : m_Name((String&&)name) { cout << "entity constructor temp" << endl; }

    void PrintName()
    {
        m_Name.Print();
        cout << endl;
    }
    ~Entity()
    {
        cout << "Entity destroyed!" << endl;
    }
};

int main()
{
    Entity entity(String("Kamil"));
    entity.PrintName();

    String string = "Hello";
    // String dest = string; //kopiowanie! nie chcemy tego
    String dest(move(string)); // String dest((String&&)string); <--- to samo!

    cin.get();
}