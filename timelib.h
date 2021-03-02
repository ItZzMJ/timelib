//
// Created by Jannik Möbius on 15.02.2021.
//

#ifndef TIMELIB_TIMELIB_H
#define TIMELIB_TIMELIB_H

//typedef damit man beim initialisieren anstatt "struct date" einfach nur "Date" schreiben kann
typedef struct
{
    int day;
    int month;
    int year;
} Date;
void input_date(Date *date);
int get_days_for_month(int month, int year);
int exists_date(Date date);
int day_of_the_year(Date date);
int min(int a, int b);
int max(int a, int b);
int vorzeichen(int c);
int is_leapyear(int jahr);

#endif //TIMELIB_TIMELIB_H
