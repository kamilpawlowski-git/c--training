#include <iostream>
#include <string>
#include <vector>

/*
rok - podany przez uzytkownika
miesiac - musi byc nazwa do display'u, musze przeksztalcic go na liczbe oraz musze przypisac mu liczbe dni
dzien - nazwa do display
*/
struct Month
{
    std::vector<std::string> m_Month = { "January", "February", "March", "April", 
                                          "May", "June", "July", "August",
                                          "September", "October", "November", "December" };
    
    std::vector<int> m_DaysInAMonth;

    int m_HowManyDays;
    Month(int x) : m_HowManyDays(x) {}
    ~Month() {}
};

struct DayOfTheWeek
{
    std::vector<std::string> m_DayOfTheWeek = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
};

void PrintCalendar(int year, int dayArray[])
{
    Month example_month(31); // liczba w nawiasie nie ma tu znaczenia

    //year offset, bazowy rok 2024
    int yearOffset = 0;
    int yearsAfter2024;
    int yearsBefore2024;

    if(year > 2024)
        yearsAfter2024 = year - 2024;
    else
        yearsBefore2024 = 2024 - year;

    while(yearsAfter2024 != 0)
    {
        if((2024 + yearsAfter2024 - 1) % 4 == 0)
        {
            yearOffset += 2;
        }
        else    
            yearOffset++;
        
        yearsAfter2024--;
    }

    yearOffset = yearOffset % 7;

    while(yearsBefore2024 != 0)
    {
        if((2024 - yearsBefore2024) % 4 == 0)
        {
            yearOffset += 2;
        }
        else
        {
            yearOffset++;
        }

        yearsBefore2024--;
    }

    yearOffset = 7 - (yearOffset % 7);

    //int rok_przestepny = (year % 4 == 0) ? 29 : 28;
   
    for(int m = 0; m < example_month.m_Month.size(); m++)
    {
        int last_i;
        static int offset = 0 + yearOffset;
        static int offsetINPROGRESS = 0;
        if(m >= 1)
            offset = offsetINPROGRESS;
        
        std::cout << std::endl;
        std::cout << "---------" << example_month.m_Month[m] << "---------" << std::endl;
        DayOfTheWeek dayoftheweek;
        for(int i = 0; i < dayoftheweek.m_DayOfTheWeek.size() ; i++)
        {
            std::cout << dayoftheweek.m_DayOfTheWeek[i] << " ";
        }
        std::cout << std::endl;

        // offset na poczatku miesiaca (czy zaczynamy od poniedzialku, od wtorku itd..)
        for(int i = 0; i < offset; i++)
            std::cout << "    ";
        
        // drukowanie dni tygodnia
        for(int i = 1; i <= dayArray[m]; i++)
        {   
            
            if((i + offset) % 7 != 0)
                if(i <= 9)
                {
                    std::cout << i << "   ";
                }
                else
                {
                    std::cout << i << "  ";
                }   
            else
            {
                if(i != dayArray[m])
                    std::cout << i << std::endl;
                else
                    std::cout << i;
                
                last_i = i;
            }
            offsetINPROGRESS = i - last_i;
        }
    }
    
}

int main()
{   
    int year;
    std::cout << "What year do you want to see?: ";
    std::cin >> year; 

    int daysFebruary = (year % 4 == 0) ? 29 : 28;
    int daysArray[] = { 31, daysFebruary, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    PrintCalendar(year, daysArray);       
}