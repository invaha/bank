#include "modir.h"
#include "bank.h"
//Modir::Modir(){}
Modir::Modir(Bank*bank):Karmand(bank)
{

}
Modir::Modir(long long base_hogog,string first_name,string last_name,int year,int month,int day,Bank*bank)
    :Karmand(base_hogog,first_name,last_name,year,month,day,bank){}
void Modir::show_info_modir(int personal_code)
{
    if(my_bank->search_karmand(personal_code) == -1)
    {
        cout << "\nwe have not this one\n";
    }
    else if(my_bank->search_karmand(personal_code) == -2)
    {
        my_bank->m_modir.print();
    }
    else
    {
        my_bank->m_karmandan.at(my_bank->search_karmand(personal_code)).print();
    }
}
void Modir::add_karmand(Karmand& karmand)
{
    if(my_bank->search_karmand(karmand.get_personal_num()) == -1)
    {
        my_bank->m_karmandan.push_back(karmand);
    }
    else if(my_bank->search_karmand(karmand.get_personal_num() == -2))
    {
        cout << "\nthis personal number is for our modir\n";
    }
    else
    {
        cout << "\nwe have a karmand with this personal number\n";
    }
}
void Modir::remove_karmand(int personal_num)
{
    if(my_bank->search_karmand(personal_num) == -1)
    {
        cout << "\nwe have not such karmand\n";
    }
    else if(my_bank->search_karmand(personal_num) == -2)
    {
        cout << "\nyou can not delete you ._. \n";
    }
    else
    {
        int andis = my_bank->search_karmand(personal_num);
        my_bank->m_karmandan.erase(my_bank->m_karmandan.begin() + andis);
    }
}
