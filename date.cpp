#include "date.h"
Date::Date(){}
Date::Date(int year,int month,int day)
{
    m_day = day;
    m_month = month;
    m_year = year;
}
void Date::print_date()
{
    cout << m_year << '/' << m_month << '/' << m_day << endl;
}

