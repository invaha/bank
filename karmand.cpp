#include "karmand.h"
#include "bank.h"
#include<ctime>
bool date_check(int year, int month, int day)
{
    if(year < 1250)
    {
        return true;
    }
    if(year > 1401)
    {
        return true;
    }
    if((month < 1) || (month > 12))
    {
        return true;
    }
    if((day < 1) || (day > 31))
    {
        return true;
    }
    if((month == 12) && (day > 29))
    {
        return true;
    }
    if((month > 6) && (month != 12) && (day > 30))
    {
        return true;
    }
    return false;
}
Karmand::Karmand()
{

}
Karmand::Karmand(Bank*bank)
{
    my_bank = bank;
    m_user_name = s_karmand_user_name;
    s_karmand_user_name += 9;
    m_personal_number = s_personal_number;
    s_personal_number++;
    m_password = s_karmand_password;
    s_karmand_password += 7;
}
void Karmand::set_bank(Bank*bank)
{
    my_bank = bank;
}
Karmand::Karmand(long long base_hogog, string first_name, string last_name, int year, int month, int day, Bank *bank)
    :m_my_birth(year,month,day)
{
    my_bank = bank;
    m_base_hogog = base_hogog;
    m_first_name = first_name;
    m_last_name = last_name;
    m_num_of_ezafe_kar = 0;
    m_user_name = s_karmand_user_name;
    s_karmand_user_name += 9;
    m_num_of_morakhasy = 0;
    m_personal_number = s_personal_number;
    s_personal_number++;
    m_password = s_karmand_password;
    s_karmand_password += 7;
}
void Karmand::hesab_action(Hesab& hesab)
{
    hesab.change_work();
}
void Karmand::morakhasy(int hour)
{
    if(m_num_of_morakhasy + hour > 15)
    {
        int max_num_morakhsy;
        if(m_num_of_morakhasy > 15)
        {
            max_num_morakhsy = m_num_of_morakhasy;
        }
        else
        {
            max_num_morakhsy = 15;
        }
        cout << "\nyou have finished your morakhasi hours !!!\n";
        cout << "your hogog will be : "
            << m_base_hogog - (100000 * (m_num_of_morakhasy + hour - max_num_morakhsy));
        if(m_base_hogog - (100000 * (m_num_of_morakhasy + hour - max_num_morakhsy)) >= 0)
        {
            cout << "\ndo you want ? (if yes press y)";
            char temp;
            cin >> temp;
            if(temp == 'y'||temp == 'Y')
            {
                m_base_hogog = m_base_hogog - (100000 * (m_num_of_morakhasy + hour - max_num_morakhsy));
                m_num_of_morakhasy += hour;
            }
        }
        else
        {
            cout << "\nthis means we can not let you \n";
        }
    }
    else
    {
        m_num_of_morakhasy += hour;
        cout << "You can make morakhasy for ";
        if((15 - m_num_of_morakhasy) > 0)
        {

            cout << 15 - m_num_of_morakhasy << " hours";
        }
        else
        {
            cout << "0 hours";
        }
    }
}
void Karmand::ezafe_kar(int hour)
{
    if(m_num_of_ezafe_kar + hour > 12)
    {
        cout << "\nsorry you can now do " << 12 - m_num_of_ezafe_kar << " hours only\n";
    }
    else
    {
        m_num_of_ezafe_kar += hour;
        m_base_hogog += (120000 * (hour));
        cout << "\nYour new hogog : " << m_base_hogog << "\n";
    }
}
void Karmand::remove_hesab()
{
    string national_code;
    do
    {
        cout << "\nnational code : ";
        cin >> national_code;
    }while(national_code.length() != 10);
    if(my_bank->search_moshtary(national_code) == -1)
    {
        cout << "\nwe have not you !!!\n";
    }
    else
    {
        int andis = my_bank->search_moshtary(national_code);
        if(my_bank->m_moshtarian.at(andis).get_hesabs().size() == 0)
        {
            cout << "you have not any hesab to delete it ,so we will delete you from moshtarian\n";
            my_bank->m_moshtarian.erase(my_bank->m_moshtarian.begin() + andis);
        }
        else if(my_bank->m_moshtarian.at(andis).get_hesabs().size() == 1)
        {
            cout << "you had only a hesab ,so we will delete you from mooshtarian\n";
            my_bank->m_moshtarian.at(andis).get_hesabs().erase(
                        my_bank->m_moshtarian.at(andis).get_hesabs().begin() + 0);
            my_bank->m_moshtarian.erase(my_bank->m_moshtarian.begin() + andis);
        }
        else
        {
            cout << "these are your hesabs :\n";
            my_bank->m_moshtarian.at(andis).print_all_hesabs();

            unsigned int choice;
            do
            {
                cout << "\nwhich one do you want to delete  ? ";
                cin >> choice;
            }while((choice < 1)||(choice > (my_bank->m_moshtarian.at(andis).get_hesabs().size()) ));
            my_bank->m_moshtarian.at(andis).get_hesabs().erase(
                        my_bank->m_moshtarian.at(andis).get_hesabs().begin() + choice - 1);
        }
    }
}
void Karmand::eftetah_hesab()
{
    cout << "\nEnter these to make a new hesab:\n";

    string national_code;
    do
    {
        cout << "national code : ";
        cin >> national_code;
    }while(national_code.length() != 10);
    if(my_bank->search_moshtary(national_code) == -1)
    {
        cout << "\n\nwe want to add you to our bank ,so enter the : \n";
        cout << "name : ";
        string name;
        cin >> name;
        cout << "family : ";
        string last_name;
        cin >> last_name;
        int year;
        int month;
        int day;
        do
        {
            cout << "your birth year : ";
            cin >> year;
            cout << "your birth month : ";
            cin >> month;
            cout << "your birth day : ";
            cin >> day;
        }while(date_check(year,month,day));
        my_bank->m_moshtarian.push_back(Moshtari(name,last_name,year,month,day,national_code));
        cout << "\n\nnow you are our moshtary ! \n";
        cout << "lets to open an account : \n";
        long long money;
        do
        {
            cout << "\nhow much money you want to add to your new account : (at least 50000T)";
            cin >> money;
        }while(money < 50000);
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        int y_year =1900 + local_time->tm_year;
        int m_month =1 + local_time->tm_mon;
        int d_day = local_time->tm_mday;
        Hesab temp_hesab(national_code,y_year,m_month,d_day,money);
        my_bank->m_moshtarian.at(my_bank->m_moshtarian.size() - 1).make_new_hesab(temp_hesab);
        cout << "\nyou can use :\nusername : " << my_bank->get_moshtarian().at(my_bank->get_moshtarian().size() - 1).get_user_name();
        cout << "\npassword : "<<my_bank->get_moshtarian().at(my_bank->get_moshtarian().size() - 1).get_pass_word();
    }
    else
    {
        int year;
        int month;
        int day;
        long long money;
        time_t ttime = time(0);
        tm *local_time = localtime(&ttime);
        year = 1900 + local_time->tm_year;
        month = 1 + local_time->tm_mon;
        day = local_time->tm_mday;
        do
        {
            cout << "\nhow much money you want to add to your new account : (at least 50000T)";
            cin >> money;
        }while(money < 50000);
        Hesab temp_hesab2(national_code,year,month,day,money);
        my_bank->m_moshtarian.at(my_bank->search_moshtary(national_code)).make_new_hesab(temp_hesab2);
    }
}
int Karmand::get_s_personal_number()
{
    return s_personal_number;
}
void Karmand::show_info(string national_code)
{
    my_bank->m_moshtarian.at(my_bank->search_moshtary(national_code)).print_all();
}
void Karmand::print()
{
    cout << "name : " << m_first_name << " " << m_last_name << "\n";
    cout << "birth day : ";
    m_my_birth.print_date();
    cout << "username : " << m_user_name << "\n";
    cout << "password : " << m_password << "\n";
    cout << "personal code : " << m_personal_number << "\n";
    cout << "base hogog : " << m_base_hogog << "\n";
    cout << "hours of morakhasy : " << m_num_of_morakhasy << "\n";
    cout << "hours of ezafe kar : " << m_num_of_ezafe_kar << "\n";
}
int Karmand::get_personal_num()
{
    return m_personal_number;
}
int Karmand::get_pass_word()
{
    return m_password;
}
long long int Karmand::get_user_name()
{
    return m_user_name;
}
int Karmand::get_num_of_ezafe_kar()
{
    return m_num_of_ezafe_kar;
}
int Karmand::get_num_of_morakhasy()
{
    return m_num_of_morakhasy;
}
