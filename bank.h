/*
 * project:bank
 * name:bank.h
 * this file handles the bank
 */
#ifndef BANK_H
#define BANK_H


#include "karmand.h"
#include "modir.h"
#include "moshtari.h"
#include<fstream>


using namespace std;

class Bank
{
public:
    //friend ship relationships needed
    friend class Karmand;
    friend istream &operator>>(istream & in, Bank & obj);
    friend ostream &operator<<(ostream & out, const Bank & obj);
    friend class Modir;

    //constructor and distructor
    ~Bank();
    Bank();
    Bank(long long base_hogog, string first_name, string last_name,int year,int month,int day,
                    int num_of_here,string name_of_here);


    //getters
    vector<Karmand>&get_karmanan();
    vector<Moshtari>&get_moshtarian();
    Modir& get_modir();


    //search in whole bank functions
    int search_moshtary(string national_code);
    int search_karmand(int pesonal_code);
    int search_karmand(long long int username, int password);
    int search_moshtary(long long int username, int password);
private:
    vector<Karmand>m_karmandan;
    vector<Moshtari>m_moshtarian;
    string m_name_of_here;
    int m_num_of_here;
    Modir m_modir;
};

#endif // BANK_H
