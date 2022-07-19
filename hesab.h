/*
 * project:bank
 * name:hesab.h
 * this file handles the accounts in the bank
 */
#ifndef HESAB_H
#define HESAB_H


#include "date.h"
#include <iostream>
#include<vector>


using namespace std;

class Hesab
{
public:
    //friend ship relationships needed
    friend istream & operator >> (istream &in,Hesab & obj);
    friend ostream & operator << (ostream & out,const Hesab & obj);

    //constructor
    Hesab();
    Hesab(string owner_national_code,int year,int month,int day,long long int mojodi);

    //all needed methods
    void plus_to_mojodi(long long int temp);
    void bardasht(long long int temp);
    bool check_is_working();
    void print();
    void change_work();


    //getter
    static long long int get_s_hesab_number();
private:
    static long long int s_hesab_number;
    long long int m_hesab_number;
    string m_owner_national_code;
    Date m_date_of_start;
    long long int m_mojodi;
    bool m_is_working;
};
#endif // HESAB_H
