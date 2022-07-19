#include "bank.h"
#include "some_overloaded.h"
Bank::Bank():m_modir(this)
{
    ifstream bank_input("bank.txt",ios::in);
    if(bank_input)
    {
        bank_input >> (*this);
        bank_input.close();
    }
    ifstream modir_input("modir.txt",ios::in);
    if(modir_input)
    {
        modir_input >> m_modir;
        modir_input.close();
    }
    ifstream karmandan_input("karmand.txt",ios::in);
    if(karmandan_input)
    {
        unsigned int temp;

        karmandan_input >> temp;
        for(unsigned int q = 0;q < temp;q++)
        {
            m_karmandan.resize(m_karmandan.size() + 1);
            karmandan_input >> m_karmandan.at(m_karmandan.size() - 1);
            m_karmandan.at(m_karmandan.size() - 1).set_bank(this);
        }
        karmandan_input.close();
    }
    ifstream moshtarian_input("moshtary.txt",ios::in);
    if(moshtarian_input)
    {
        unsigned int temp;
        moshtarian_input >> temp;
        for(unsigned int q = 0;q < temp;q++)
        {
            m_moshtarian.resize(m_moshtarian.size() + 1);
            moshtarian_input >> m_moshtarian.at(m_moshtarian.size() - 1);

        }
        moshtarian_input.close();
    }
}
Bank::Bank(long long base_hogog,string first_name,string last_name,int year,int month,int day,int num_of_here,string name_of_here)
    :m_modir(base_hogog,first_name,last_name,year,month,day,this)
{
    m_name_of_here = name_of_here;
    m_num_of_here = num_of_here;
}
Bank::~Bank()
{
    ofstream modir_file("modir.txt",ios::trunc);
    modir_file << m_modir;
    modir_file.close();

    ofstream bank_file("bank.txt", ios::trunc);
    bank_file << *this;
    bank_file.close();

    ofstream moshtarian_file("moshtary.txt", ios::trunc);
    moshtarian_file << m_moshtarian.size() << "\n";
    for(unsigned int q = 0;q < m_moshtarian.size();q++)
    {
        moshtarian_file << m_moshtarian.at(q);
        moshtarian_file << "\n";
    }
    moshtarian_file.close();

    ofstream karmand_file("karmand.txt", ios::trunc);
    karmand_file << m_karmandan.size() << "\n";
    for(unsigned int q = 0;q < m_karmandan.size();q++)
    {
        karmand_file << m_karmandan.at(q);
        karmand_file << "\n";
    }
    karmand_file.close();
}
int Bank::search_moshtary(string national_code)
{
    for(unsigned int q = 0;q < m_moshtarian.size();q++)
    {
        if(m_moshtarian.at(q).get_national_code() == national_code)
        {
            return q;
        }
    }
    return -1;
}
int Bank::search_karmand(int pesonal_code)
{
    for(unsigned int q = 0;q < m_karmandan.size();q++)
    {
        if(m_karmandan.at(q).get_personal_num() == pesonal_code)
        {
            return q;
        }
    }
    if(m_modir.get_personal_num() == pesonal_code)
    {
        return -2;
    }
    return -1;
}
int Bank::search_karmand(long long username, int password)
{
    for(unsigned int q = 0;q < m_karmandan.size();q++)
    {
        if((m_karmandan.at(q).get_user_name() == username)&&(m_karmandan.at(q).get_pass_word() == password))
        {
            return q;
        }
    }
    if((m_modir.get_user_name() == username)&&(m_modir.get_pass_word() == password))
    {
        return -2;
    }
    return -1;
}
int Bank::search_moshtary(long long int username,int password)
{
    for(unsigned int q = 0;q < m_moshtarian.size();q++)
    {
        if((m_moshtarian.at(q).get_user_name() == username)&&(m_moshtarian.at(q).get_pass_word() == password))
        {
            return q;
        }
    }
    return -1;
}
vector<Karmand>& Bank::get_karmanan()
{
    return m_karmandan;
}
vector<Moshtari> &Bank::get_moshtarian()
{
    return m_moshtarian;
}
Modir &Bank::get_modir()
{
    return m_modir;
}
