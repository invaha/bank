#include "hesab.h"

Hesab::Hesab(){}
Hesab::Hesab(string owner_national_code,int year,int month,int day,long long int mojodi)
    :m_date_of_start(year,month,day)
{
    m_is_working = true;
    m_hesab_number = s_hesab_number + 8;
    s_hesab_number += 8;
    m_mojodi = mojodi;
    m_owner_national_code = owner_national_code;
}
void Hesab::plus_to_mojodi(long long temp)
{
    m_mojodi += temp;
}
void Hesab::bardasht(long long int temp)
{
    if(m_is_working)
    {
        m_mojodi -= temp;
    }
    else
    {
        cout << "\nthis hesab is not active ,so you can not di this\n";
    }
}
bool Hesab::check_is_working()
{
    return m_is_working;
}
void Hesab::print()
{
    cout << "national code of owner : " << m_owner_national_code << "\n";
    cout << "hesab number : " << m_hesab_number << "\n";
    cout << "date of start : ";
    m_date_of_start.print_date();
    cout << "mojodi : " << m_mojodi<<"\n";
    if(check_is_working())
    {
        cout << "this heasab is working\n";
    }
    else
    {
        cout<<"this hesab is not working\n";
    }
}
void Hesab::change_work()
{
    if(check_is_working())
    {
        m_is_working = false;
    }
    else
    {
        m_is_working = true;
    }
}
long long int Hesab::get_s_hesab_number()
{
    return s_hesab_number;
}
