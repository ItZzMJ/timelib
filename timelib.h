//
// Created by Jannik Möbius on 15.02.2021.
//

#ifndef TIMELIB_TIMELIB_H
#define TIMELIB_TIMELIB_H

void input_date(int *day, int *month, int *year);
int get_days_for_month(int month, int year);
int exists_date(int day, int month, int year);
int day_of_the_year(int day, int month, int year);
int min(int a, int b);
int max(int a, int b);
int vorzeichen(int c);
int is_leapyear(int jahr);

#endif //TIMELIB_TIMELIB_H
