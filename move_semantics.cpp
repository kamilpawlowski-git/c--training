#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
    char* m_Data;
    int m_Size;
public:
    String() = default;
    String(const char* string)
    {
        printf("Created!\n");
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }
    String(const String& other)
    {
        printf("Copied!\n");
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }
    String(String&& other) noexcept
    {
        printf("Moved!\n");
        m_Size = other.m_Size;
        m_Data = other.m_Data;
        
        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~String()
    {   
        printf("Destroyed!\n");
        delete m_Data;
    }

    void Print()
    {
        for(int i = 0; i < m_Size; i++)
            printf("%c", m_Data[i]);
    }
};  

class Entity
{
private:
    String m_Name;
public: 
    Entity(String& name) : m_Name(name) {}
    Entity(String&& name) : m_Name((String&&)name) {}

    void printName()
    {
        m_Name.Print();
    }
};

int main()
{
    Entity entity(String("Cherno"));
    entity.printName();
}