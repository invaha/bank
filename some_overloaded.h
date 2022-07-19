/*
 * project:bank
 * name:some_overloded.h
 * this is some >> and<< overloded forms for our classes
 * to read and write in or from texts
 */
#ifndef SOME_OVERLOADED_H
#define SOME_OVERLOADED_H


#include"bank.h"

ostream &operator << (ostream & out,const Modir & obj)
{
    out << obj.m_first_name << " "
       << obj.m_last_name << " "
       << obj.m_my_birth << " "
       << obj.m_base_hogog << " "
       << obj.m_personal_number << " "
       << obj.m_user_name << " "
       << obj.m_password << " "
       << obj.m_num_of_morakhasy << " "
       << obj.m_num_of_ezafe_kar;
    return out;
}

ostream &operator << (ostream & out,const Bank & obj)
{
    out << obj.m_name_of_here << " "
       << obj.m_num_of_here;
    return out;
}

ostream &operator << (ostream & out,const Date & obj)
{
    out << obj.m_year << " " << obj.m_month << " " << obj.m_day;
    return out;
}

ostream &operator << (ostream & out,const Hesab & obj)
{
    out << obj.m_hesab_number << " " << obj.m_owner_national_code << " " << obj.m_date_of_start << " "
      << obj.m_mojodi << " " << int(obj.m_is_working);
    return out;
}

ostream &operator << (ostream & out,const Karmand & obj)
{
    out << obj.m_first_name << " "
       << obj.m_last_name << " "
       << obj.m_my_birth << " "
       << obj.m_base_hogog << " "
       << obj.m_personal_number << " "
       << obj.m_user_name << " "
       << obj.m_password << " "
       << obj.m_num_of_morakhasy << " "
       << obj.m_num_of_ezafe_kar;
    return out;
}

ostream &operator << (ostream & out,const Moshtari & obj)
{
    out << obj.m_first_name << " "
       << obj.m_last_name << " "
       << obj.m_national_code << " "
       << obj.m_my_birth << " "
       << obj.m_user_name << " "
       << obj.m_password << " "
       << obj.my_hesabs.size() << "\n";
    for(unsigned int q = 0;q < obj.my_hesabs.size();q++)
    {
        out << obj.my_hesabs.at(q) << "\n";
    }
    return out;
}

istream &operator >> (istream & in, Bank & obj)
{
    in >> obj.m_name_of_here >> obj.m_num_of_here;
    return in;
}

istream &operator >> (istream & in,Date & obj)
{
    in >> obj.m_year >> obj.m_month >> obj.m_day;
    return in;
}

istream &operator >> (istream & in,Modir & obj)
{
    in >> obj.m_first_name
       >> obj.m_last_name
       >> obj.m_my_birth
       >> obj.m_base_hogog
       >> obj.m_personal_number
       >> obj.m_user_name
       >> obj.m_password
       >> obj.m_num_of_morakhasy
       >> obj.m_num_of_ezafe_kar;
    return in;
}

istream &operator >> (istream & in,Hesab & obj)
{
    int temp;
    in >> obj.m_hesab_number >> obj.m_owner_national_code >> obj.m_date_of_start >> obj.m_mojodi >> temp;
    if(temp == 1)
    {
        obj.m_is_working = true;
    }
    else
    {
        obj.m_is_working = false;
    }
    Hesab::s_hesab_number += 8;
    return  in;
}

istream &operator >> (istream & in,Karmand & obj)
{
    Karmand::s_personal_number++;
    Karmand::s_karmand_password += 7;
    Karmand::s_karmand_user_name += 9;
    in >> obj.m_first_name
       >> obj.m_last_name
       >> obj.m_my_birth
       >> obj.m_base_hogog
       >> obj.m_personal_number
       >> obj.m_user_name
       >> obj.m_password
       >> obj.m_num_of_morakhasy
       >> obj.m_num_of_ezafe_kar;
    return in;
}

istream &operator >> (istream & in,Moshtari & obj)
{
    Moshtari::s_moshtary_password += 13;
    Moshtari::s_moshtary_user_name += 19;
    in >> obj.m_first_name
       >> obj.m_last_name
       >> obj.m_national_code
       >> obj.m_my_birth
       >> obj.m_user_name
       >> obj.m_password;
    unsigned int temp;
    in >> temp;
    for(unsigned int q = 0;q < temp;q++)
    {
        obj.my_hesabs.resize(obj.my_hesabs.size() + 1);
        in >> obj.my_hesabs.at(obj.my_hesabs.size() - 1);
    }
    return in;
}

#endif // SOME_OVERLOADED_H
