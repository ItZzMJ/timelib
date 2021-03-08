/**
 * Testfunktionen für die Bibliothek timelib.c
 * Autor: Jannik Möbius
 * Erstellt am: 19.01.21
 **/

#include "timelib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Testfunktion zum Testen der Bibliothek timelib.c
 */
int main()
{
    int daysOfMonth, dayOfYear;

    //Leeres Datum erzeugen
    Date date;

    printf("**** Test der neuen Funktionen ****\n");

    //Datum über CLI einlesen
    input_date(&date);

    //Überprüfen ob das Datum existiert
    if(exists_date(date)) {
        printf("Das Datum %d.%d.%d existiert.\n", date.day, date.month, date.year);
    } else  {
        printf("Das Datum %d.%d.%d existiert nicht.\n", date.day, date.month, date.year);
    }

    //Die Tage des Monats herausfinden
    daysOfMonth = get_days_for_month(date.month, date.year);
    printf("Der %d. Monat hat %d Tage.\n", date.month, daysOfMonth);

    //Den Tag des Jahres herausfinden
    dayOfYear = day_of_the_year(date);
    printf("Der %d.%d.%d ist der %d. Tag des Jahres.\n", date.day, date.month, date.year, dayOfYear);

    return 0;
}
