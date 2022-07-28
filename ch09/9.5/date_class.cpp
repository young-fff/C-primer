/*
*File : ch09/9.5/date_class.cpp
*Date : 2022-07-28
*Page : 328
*/

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <forward_list>
#include <deque>
#include <array>

using namespace std;

class Mydate
{
    public:
        Mydate (const string& d)
        {
            int format;
            int tag = 0;
            string numbers = "0123456789";
            if (d.find_first_of(",") != string::npos) {
                format = 1;
            } else if (d.find_first_of("/") != string::npos) {
                format = 2;
            } else if ((d.find_first_of(" ") != string::npos) && (d.find_first_of(",") == string::npos)) {
                format = 1;
                tag = 1;
            }
            switch(format) {
                case 1: 
                {
                    if (d.find("Jan") < d.size())   m_month = 1;
                    if (d.find("Feb") < d.size())   m_month = 2;
                    if (d.find("Mar") < d.size())   m_month = 3;
                    if (d.find("Apr") < d.size())   m_month = 4;
                    if (d.find("May") < d.size())   m_month = 5;
                    if (d.find("Jun") < d.size())   m_month = 6;
                    if (d.find("Jul") < d.size())   m_month = 7;
                    if (d.find("Aug") < d.size())   m_month = 8;
                    if (d.find("Sep") < d.size())   m_month = 9;
                    if (d.find("Oct") < d.size())   m_month = 10;
                    if (d.find("Nov") < d.size())   m_month = 11;
                    if (d.find("Dec") < d.size())   m_month = 12;

                    char ch = ' ';
                    if (0 == tag) {
                        ch = ',';  
                    }
                    m_day = stoi(d.substr(d.find_first_of(numbers), (d.find_first_of(ch) - d.find_first_of(numbers))));
                    m_year = stoi(d.substr(d.find_last_of(ch)+1, 4));
                    break;
                }
                case 2:
                {
                    m_day = stoi(d.substr(0, d.find_first_of("/")));
                    m_month = stoi(d.substr(d.find_first_of("/")+1, (d.find_last_of("/") - d.find_first_of("/"))));
                    m_year = stoi(d.substr(d.find_last_of("/")+1, 4));
                    break;
                }
                default:
                    m_year = 0;
                    m_month = 0;
                    m_day = 0;
                    break;
            }
        

        }
        void print() 
        {
            cout << m_year << "-" << m_month << "-" << m_day << endl;
        }
    private:
        unsigned m_year;
        unsigned m_month;
        unsigned m_day;
};
int main()
{
    Mydate d1("1/12/1997");
    Mydate d2("Jan 1 1900");
    Mydate d3("January 1,1900");
    d1.print();
    d2.print();
    d3.print();

    system("pause");
    return 0;
}