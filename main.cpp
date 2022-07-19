/*
 * project:bank
 * name:main.cpp
 * this file handles the bank
 */
#include "bank.h"

long long int Hesab::s_hesab_number = 362734549000;
long long int Karmand::s_karmand_user_name = 9876543210;
long long int Moshtari::s_moshtary_user_name = 45546556;
int Moshtari::s_moshtary_password = 100000;
int Karmand::s_karmand_password = 1000;
int Karmand::s_personal_number = 100;
void file_time_and_date(ofstream & report);
bool date_check(int year,int month,int day);

int main()
{
    ofstream report("report.txt",ios::app);
    report << "\nprogram started ";
    file_time_and_date(report);
    Bank our_bank;
    char choice;
    do
    {
        cout << "1)karmand\n";
        cout << "2)Moshtary\n";
        cout << "q-exit\n";
        cout << "\nwhich want do you to do ? ";
        cin >> choice;
        if(choice == '1')
        {
            cout << "you want to enter as a karmand : \n";
            cout <<"Enter your username (just number ): ";
            long long int user_name;
            cin >> user_name;
            int pass_word;
            cout << "Enter your password (just number): ";
            cin >> pass_word;
            if(our_bank.search_karmand(user_name,pass_word) == -2)//modir
            {
                report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num() << " login ";
                file_time_and_date(report);
                cout << "you are modir : \n";
                char choice_;
                do
                {
                    cout << "\n*****************************************************\n";
                    cout << "\n1.morakhasy\n";
                    cout << "2.ezafe kar\n";
                    cout << "3.show information\n";
                    cout << "4.show all info about moshtary with national code\n";
                    cout << "5.eftetahe hesab\n";
                    cout << "6.remove hesab\n";
                    cout << "7.show all info about karmand with personal code\n";
                    cout << "8.add new karmand\n";
                    cout << "9.remove a karmand\n";
                    cout << "q.exit\n";
                    cout << "what do you want to do ? ";
                    cin >> choice_;

                    if(choice_ == '1')
                    {
                        int hour;
                        do
                        {
                            cout << "how many hours do you want ? ";
                            cin >> hour;
                        }while(hour < 0);
                        our_bank.get_modir().morakhasy(hour);
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " change its morakhasy to " << our_bank.get_modir().get_num_of_morakhasy()
                            << " hours ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '2')
                    {
                        int hour;
                        do
                        {
                            cout << "how many hours do you want ? ";
                            cin >> hour;
                        }while(hour < 0);
                        our_bank.get_modir().ezafe_kar(hour);
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " change its ezafe kar to " << our_bank.get_modir().get_num_of_ezafe_kar()
                            << " hours ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '3')
                    {
                        our_bank.get_modir().print();
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for show its information ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '4')
                    {
                        string national_code;
                        do
                        {
                            cout << "\nnational code : ";
                            cin >> national_code;
                        }while(national_code.length() != 10);
                        if(our_bank.search_moshtary(national_code) != -1)
                        {
                            cout << "\n__________________________________________\n";
                            our_bank.get_modir().show_info(national_code);
                        }
                        else
                        {
                            cout << "sorry,we have not some moshtary!\n";
                        }
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for show information of a karmand with " <<
                               "national code : " << national_code;
                        file_time_and_date(report);
                    }
                    else if(choice_ == '5')
                    {
                        our_bank.get_modir().eftetah_hesab();
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for eftetah a hesab";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '6')
                    {
                        our_bank.get_modir().remove_hesab();
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for remove a hesab";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '7')
                    {
                        unsigned int personal_num;
                        do
                        {
                            cout << "personal number : ";
                            cin >> personal_num;
                        }while((personal_num < 100));
                        our_bank.get_modir().show_info_modir(personal_num);
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for show information of a karmand with " <<
                               "personal code : " << personal_num;
                        file_time_and_date(report);
                    }
                    else if(choice_ == '8')
                    {
                        long long base_hogog;
                        string first_name;
                        string last_name;
                        int year;
                        int month;
                        int day;
                        cout << "Enter these to continue . . .\n";
                        cout << "First name : ";
                        cin >> first_name;
                        cout << "Last name : ";
                        cin >> last_name;
                        do
                        {
                            cout << "your birth date :\n";
                            cout << "year : ";
                            cin >> year;
                            cout << "month : ";
                            cin >> month;
                            cout << "day : ";
                            cin >> day;
                        }while(date_check(year,month,day));
                        do
                        {
                            cout << "base hogog : ";
                            cin >> base_hogog;
                        }while(base_hogog < 0);
                        Karmand temp_karmand(base_hogog,first_name,last_name,year,month,day,&our_bank);
                        our_bank.get_modir().add_karmand(temp_karmand);
                        cout << "\nhe/she can use :\nusername : " << our_bank.get_karmanan().at(our_bank.get_karmanan().size()-1).get_user_name();
                        cout << "\npassword : " << our_bank.get_karmanan().at(our_bank.get_karmanan().size()-1).get_pass_word();
                        cout << "\npersonal number : " << our_bank.get_karmanan().at(our_bank.get_karmanan().size()-1).get_personal_num();
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for add a new karmand to this bank";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '9')
                    {
                        int personal_num;
                        do
                        {
                            cout << "personal number : ";
                            cin >> personal_num;
                        }while(personal_num < 100);
                        our_bank.get_modir().remove_karmand(personal_num);
                        report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                             << " send a request for remove a karmand with personal num : "
                            << personal_num << " from this bank";
                        file_time_and_date(report);
                    }
                    else if(choice_ != 'q')
                    {
                        cout << "wrong input!\n";
                    }
                }while(choice_ != 'q');
                report << "\nmodir with personal code " << our_bank.get_modir().get_personal_num()
                     << " quited";
                file_time_and_date(report);
            }
            else if(our_bank.search_karmand(user_name,pass_word)==-1)
            {
                report << "\na try to login as a karmand with incorrect information";
                file_time_and_date(report);
                cout << "\n\nthere is no such karmand\n\n";
            }
            else
            {
                int andis = our_bank.search_karmand(user_name,pass_word);
                cout << "you are normal karmand :\n";
                report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis).
                        get_personal_num() << " login ";
                file_time_and_date(report);
                char choice_;
                do
                {
                    cout << "\n*****************************************************\n";
                    cout << "1.morakhasy\n";
                    cout << "2.ezafe kar\n";
                    cout << "3.show information\n";
                    cout << "4.show all info about moshtary with national code\n";
                    cout << "5.eftetahe hesab\n";
                    cout << "6.remove hesab\n";
                    cout << "q.exit\n";
                    cout << "what do you want to do ? ";
                    cin >> choice_;
                    if(choice_ == '1')
                    {
                        int hour;
                        do
                        {
                            cout << "how many hours do you want ? ";
                            cin >> hour;
                        }while(hour < 0);
                        our_bank.get_karmanan()[andis].morakhasy(hour);
                        report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis)
                                .get_personal_num()
                             << " change its morakhasy to " << our_bank.get_karmanan().at(andis)
                               .get_num_of_morakhasy()
                            << " hours ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '2')
                    {
                        int hour;
                        do
                        {
                            cout << "how many hours do you want ? ";
                            cin >> hour;
                        }while(hour < 0);
                        our_bank.get_karmanan().at(andis).ezafe_kar(hour);
                        report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis).get_personal_num()
                             << " change its ezafe kar to " << our_bank.get_karmanan().at(andis).get_num_of_ezafe_kar()
                            << " hours ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '3')
                    {
                        our_bank.get_karmanan().at(andis).print();
                        report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis).get_personal_num()
                             << " send a request for show its information ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '4')
                    {
                        string national_code;
                        do
                        {
                            cout << "\nnational code : ";
                            cin >> national_code;
                        }while(national_code.length() != 10);
                        if(our_bank.search_moshtary(national_code) != -1)
                        {
                            cout << "\n__________________________________________\n";
                            our_bank.get_karmanan()[andis].show_info(national_code);
                        }
                        else
                        {
                            cout << "sorry,we have not such moshtary!\n";
                        }
                        report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis).get_personal_num()
                             << " send a request for show information of a karmand with "<<
                               "national code : " << national_code;
                        file_time_and_date(report);
                    }
                    else if(choice_ == '5')
                    {
                        our_bank.get_karmanan()[andis].eftetah_hesab();
                        report << "\na karmand with personal code " << our_bank.get_karmanan()
                                .at(andis).get_personal_num()
                             << " send a request for eftetah a hesab";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '6')
                    {
                        our_bank.get_karmanan().at(andis).remove_hesab();
                        report << "\na karmand with personal code " << our_bank.get_karmanan().at(andis).get_personal_num()
                             << " send a request for remove a hesab";
                        file_time_and_date(report);
                    }
                    else if(choice_ != 'q')
                    {
                        cout << "Wrong input\n";
                    }
                }while(choice_ != 'q');
                report << "\na karmand with personal code " << our_bank.get_modir().get_personal_num()
                     << " quited";
                file_time_and_date(report);
            }
        }
        else if(choice == '2')
        {
            cout << "you want to enter as a moshtary : \n";
            cout << "Enter your username (just number): ";
            long long int user_name;
            cin >> user_name;
            int pass_word;
            cout << "Enter your password (just number): ";
            cin >> pass_word;
            if(our_bank.search_moshtary(user_name,pass_word) == -1)
            {
                report << "\na try to login as a moshtary with incorrect information";
                file_time_and_date(report);
                cout << "there is no such moshtary\n";
            }
            else
            {
                int andis = our_bank.search_moshtary(user_name,pass_word);
                cout << "you are normal moshtary :\n";
                report << "\na moshtary with national code " << our_bank.get_moshtarian().at(andis).get_national_code()
                     << " login ";
                file_time_and_date(report);
                char choice_;
                do
                {
                    cout << "1.plus mojody\n";
                    cout << "2.mines mojody\n";
                    cout << "3.show information and . . .\n";
                    cout << "q.exit\n";
                    cout << "what do you want to do ? ";
                    cin >> choice_;
                    if(choice_ == '1')
                    {
                        our_bank.get_moshtarian().at(andis).print_all_hesabs();
                        unsigned int choose;
                        do
                        {
                            cout << "\n\nwhich hesab  ? ";
                            cin >> choose;
                        }while((choose < 1) || (choose > our_bank.get_moshtarian()[andis].get_hesabs().size()));
                        cout << "how much money do you want to add ? ";
                        long long money;
                        do
                        {
                            cin >> money;
                        }while(money < 0);
                        our_bank.get_moshtarian().at(andis).afzayeshe_mojodi(our_bank.get_moshtarian()[andis].get_hesabs().at(choose-1),money);
                        report << "\na moshtary with national code " << our_bank.get_moshtarian().at(andis).get_national_code();
                        report << "have aded " << money << " to its hesab ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '2')
                    {
                        our_bank.get_moshtarian().at(andis).print_all_hesabs();
                        unsigned int choose;
                        do
                        {
                            cout << "\n\nwhich hesab  ? ";
                            cin >> choose;
                        }while((choose < 1) || (choose > our_bank.get_moshtarian()[andis].get_hesabs().size()));
                        cout << "how much money do you want to remove ? ";
                        long long int money;
                        do
                        {
                            cin >> money;
                        }while(money < 0);
                        our_bank.get_moshtarian().at(andis).bardasht(our_bank.get_moshtarian().at(andis).get_hesabs()[choose-1], money);
                        report << "\na moshtary with national code " << our_bank.get_moshtarian().at(andis).get_national_code();
                        report << "have removed " << money << " from its hesab ";
                        file_time_and_date(report);
                    }
                    else if(choice_ == '3')
                    {
                        report << "\na moshtary with national code " << our_bank.get_moshtarian().at(andis).get_national_code();
                        report << "have requested to show its information";
                        file_time_and_date(report);
                        our_bank.get_moshtarian().at(andis).print_just_main_info();
                        cout << "do you want to (show hesabs informations ?(if yes,press y)) : ";
                        char choice__;
                        cin >> choice__;
                        if((choice__ == 'y') || (choice__ == 'Y'))
                        {
                            our_bank.get_moshtarian().at(andis).print_all_hesabs();
                        }
                    }
                    else if(choice_ != 'q')
                    {
                        cout << "\nwrong input \n";
                    }
                }while(choice_ != 'q');
                report << "\na moshtary with national code " << our_bank.get_moshtarian().at(andis).get_national_code()
                     << " quited";
                file_time_and_date(report);
            }
        }
        else if(choice != 'q')
        {
            cout << "\nwrong input \n";
        }
    }while(choice != 'q');
    report << "\nprogram closed";
    file_time_and_date(report);
    report.close();
    cout << "\n\ngoodbye . . .\n";
    return 0;
}
void file_time_and_date(ofstream& report)
{
    report << " in date ";
    time_t ttime = time(0);
    tm *local_time = localtime(&ttime);
    report << (1900 + local_time->tm_year);
    report << '\\';
    report << (1 + local_time->tm_mon);
    report << '\\';
    report << ( local_time->tm_mday);
    report << " time ";
    report << (local_time->tm_hour)<<":";
    report << (local_time->tm_min)<<":";
    report << (local_time->tm_sec);
}
