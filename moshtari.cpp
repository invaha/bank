#include "moshtari.h"
Moshtari::Moshtari(){}
Moshtari::Moshtari(string first_name, string last_name,
         int year, int month, int day,string national_code):m_my_birth(year,month,day)
{
    m_national_code = national_code;
    m_password = s_moshtary_password;
    s_moshtary_password += 13;
    m_user_name = s_moshtary_user_name;
    s_moshtary_user_name += 19;
    m_last_name = last_name;
    m_first_name = first_name;
}
void Moshtari::afzayeshe_mojodi(Hesab& temp_hesab,long long temp)
{
    temp_hesab.plus_to_mojodi(temp);
}
void Moshtari::bardasht(Hesab& temp_hesab,long long temp)
{
    temp_hesab.bardasht(temp);
}
void Moshtari::print_just_main_info()
{
    cout << "name : " << m_first_name << " " << m_last_name << "\n";
    cout << "national code : " << m_national_code << "\n";
    cout << "birth day : ";
    m_my_birth.print_date();
    cout << "username : " << m_user_name<<"\n";
    cout << "password : " << m_password<<"\n";
}
void Moshtari::print_all()
{
    cout << "name : " << m_first_name << " " << m_last_name << "\n";
    cout << "national code : " << m_national_code << "\n";
    cout << "birth day : ";
    m_my_birth.print_date();
    cout << "username : " << m_user_name << "\n";
    cout << "password : " << m_password << "\n";
    if(my_hesabs.size() != 0)
    {
        for(unsigned int q = 0 ;q < my_hesabs.size();q++)
        {
            cout << "*****  hesab  " << q + 1 << "*****\n";
            my_hesabs[q].print();
            cout << "\n";
        }
    }
}
void Moshtari::print_all_hesabs()
{
    if(my_hesabs.size() != 0)
    {
        for(unsigned int q = 0;q < my_hesabs.size();q++)
        {
            cout << "*****  hesab  " << q + 1 << "*****\n";
            my_hesabs[q].print();
            cout << "\n";
        }
    }
}
string Moshtari::get_national_code()
{
    return m_national_code;
}
void Moshtari::make_new_hesab(Hesab &hesab)
{
    my_hesabs.push_back(hesab);
}
int Moshtari::get_pass_word()
{
    return m_password;
}
long long int Moshtari::get_user_name()
{
    return m_user_name;
}
vector<Hesab>& Moshtari::get_hesabs()
{
    return my_hesabs;
}
