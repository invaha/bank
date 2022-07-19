/*
 * project:bank
 * name:moshtari.h
 * this file handles the clients in the bank
 */
#ifndef MOSHTARI_H
#define MOSHTARI_H


#include "hesab.h"
#include <iostream>
#include<vector>


using namespace std;

class Moshtari
{
public:
    //friend ship relationships needed
    friend istream &operator >> (istream & in,Moshtari & obj);
    friend ostream &operator << (ostream & out,const Moshtari & obj);

    //cunstructor
    Moshtari();
    Moshtari(string first_name,string last_name,int year,int month,int day,string national_code);

    void afzayeshe_mojodi(Hesab& temp_hesab,long long temp);
    void bardasht(Hesab& temp_hesab,long long temp);
    void print_all();
    void print_all_hesabs();
    void print_just_main_info();
    void make_new_hesab(Hesab & hesab);

    //getter
    long long int get_user_name();
    int get_pass_word();
    vector<Hesab> & get_hesabs();
    string get_national_code();
private:
    static long long int s_moshtary_user_name;
    static int s_moshtary_password;
    string m_national_code;
    string m_first_name;
    string m_last_name;
    Date m_my_birth;
    long long int m_user_name;
    int m_password;
    vector<Hesab>my_hesabs;
};

#endif // MOSHTARI_H
