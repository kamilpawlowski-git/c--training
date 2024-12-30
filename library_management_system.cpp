#include <iostream>
#include <string>
#include <sstream>

class Book
{
private:
    std::string m_Title;
    std::string m_Author;
    int m_NumOfPages;
    int m_PublishedInYear;
    bool m_isAvailable;
public:
    Book(std::string name, std::string author, int pages, int year, bool available)
            : m_Title(name), m_Author(author), m_NumOfPages(pages), m_PublishedInYear(year), m_isAvailable(available)  {}
    ~Book() {}

    void ChangeAvailability()
    {
        m_isAvailable = !m_isAvailable;
    }

    void Print() const
    {
        std::cout << "Title: " << m_Title <<  std::endl;
        std::cout << "Author: " << m_Author << std::endl;
        std::cout << "Pages: " << m_NumOfPages << std::endl;
        std::cout << "Published in: " << m_PublishedInYear << std::endl;
        std::cout << "Availability: " << m_isAvailable << std::endl;
        std::cout << std::endl;
    }

    std::string GetTitle() const
    {
        return m_Title;
    }

    void lendBook(std::string& collector)
    {   
        if(collector == m_Title)
        {
            std::cout << "Ksiazka pomyslnie wypozyczona!" << std::endl;
            ChangeAvailability();
        }
    }
};



int main()
{
    Book book1("Sherlock Holmes", "Christian Conan Doyle", 200, 1980, true);
    Book book2("Dzieci z Bullerbyn", "Astrid Lindgren" , 150, 1981, true);
    Book book3("Lalka", "Boleslaw Prus", 500, 1940, true);

    std::stringstream ss;

    std::cout << "Ktora z ponizszych ksiazek chcesz wypozyczyc?" << std::endl;
    std::cout << std::endl;
    book1.Print();
    book2.Print();
    book3.Print();
    std::cout << "Wpisz tytul ksiazki ktora chcialbys wypozyczyc: ";
    std::cin >> ss
    book1.lendBook(collector);
    book2.lendBook(collector);
    book3.lendBook(collector);
    

     

    



}