/*
 * project:bank
 * name:modir.h
 * this file handles the boss in the bank
 */
#ifndef MODIR_H
#define MODIR_H


#include <iostream>
#include<vector>
#include"karmand.h"


using namespace std;

class Modir:public Karmand
{
public:
    //friend ship relationships needed
    friend istream &operator >> (istream & in, Modir & obj);
    friend ostream &operator<<(ostream & out,const Modir & obj);

    //constructor
    Modir(Bank * bank);
    Modir(long long base_hogog,string first_name, string last_name,int year, int month, int day,Bank*bank);

    //all deeded functions
    void show_info_modir(int personal_code);
    void add_karmand(Karmand & karmand);
    void remove_karmand(int personal_num);
};
#endif // MODIR_H
