/*
 * project:bank
 * name:karmand.h
 * this file handles the workers in the bank
 */
#ifndef KARMAND_H
#define KARMAND_H


#include "date.h"
#include "hesab.h"


class Bank;

class Karmand
{
public:
    //friend ship relationships needed
    friend istream &operator >> (istream & in,Karmand & obj);
    friend ostream &operator << (ostream & out,const Karmand & obj);

    //constructor
    Karmand(Bank * bank);
    Karmand();
    Karmand(long long base_hogog,string first_name,string last_name,int year,int month,int day,Bank* bank);

    //all needed methods
    void hesab_action(Hesab & hesab);
    void show_info(string national_code);
    void ezafe_kar(int hour);
    void morakhasy(int hour);
    void eftetah_hesab();
    void print();
    void remove_hesab();

    //getter
    int get_personal_num();
    long long int get_user_name();
    int get_pass_word();
    int get_num_of_ezafe_kar();
    int get_num_of_morakhasy();
    static int get_s_personal_number();

    //setter
    void set_bank(Bank * bank);
protected:
    Bank* my_bank;
    static long long int s_karmand_user_name;
    static int s_karmand_password;
    static int s_personal_number;
    int m_personal_number;
    long long m_base_hogog;
    int m_num_of_ezafe_kar;
    int m_num_of_morakhasy;
    string m_first_name;
    string m_last_name;
    Date m_my_birth;
    long long int m_user_name;
    int m_password;
};
#endif // KARMAND_H
