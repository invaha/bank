/*
 * project:bank
 * name:date.h
 * this file handles the dates in the bank
 */
#ifndef DATE_H
#define DATE_H


#include <iostream>
#include<vector>


class Modir;

using namespace std;

class Date
{
public:
    //friend ship relationships needed
    friend istream & operator >> (istream & in, Date & obj);
    friend ostream & operator << (ostream & out, const Date & obj);

    //constructor
    Date(int year, int month, int day);
    Date();

    //print method
    void print_date();

private:
    int m_year;
    int m_month;
    int m_day;
};
#endif // DATE_H
