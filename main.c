/**
 * Testfunktionen für die Bibliothek timelib.c
 * Autor: Jannik Möbius
 * Erstellt am: 19.01.21
 **/

#include "timelib.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Formatierte Ausgabe zum Testen der vorherigen Funktionen
 *
 * @param x
 * @param y
 * @param erg
 */
void ausgabe(int x, int y, int erg)
{
    if(y == NULL) printf(" %d\t", x);
    else printf(" %d, %d ", x,y);

    printf("\t| %d \n", erg);
}

/**
 * Testfunktion für Min-, Max-, und Vorzeichen-funktion
 * @return
 */
int testfunktion()
{
    printf("******** Funktionen-Test ********\n");

    printf("\n****** Min-Test ******\n");
    printf("Eingabe(x,y)\t| Ergebnis \n");
    printf("----------------+----------\n");

    int x = 15, y = 42;
    int erg = min(x,y);
    ausgabe(x,y,erg);

    x = 1312;
    y = 420;
    erg = min(x,y);
    ausgabe(x,y,erg);

    x = 62;
    y = x;
    erg = min(x,y);
    ausgabe(x,y,erg);


    printf("\n****** Max-Test ******\n");
    printf("Eingabe(x,y)\t| Ergebnis \n");
    printf("----------------+----------\n");

    x = 15, y = 42;
    erg = max(x,y);
    ausgabe(x,y,erg);

    x = 1312;
    y = 420;
    erg = max(x,y);
    ausgabe(x,y,erg);

    x = 62;
    y = x;
    erg = max(x,y);
    ausgabe(x,y,erg);


    printf("\n****** Vorzeichen-Test ******\n");
    printf("Eingabe(x)\t| Ergebnis \n");
    printf("----------------+----------\n");

    x = 96;
    erg = vorzeichen(x);
    ausgabe(x,NULL,erg);

    x = -1337;
    erg = vorzeichen(x);
    ausgabe(x,NULL,erg);

    x = 0;
    erg = vorzeichen(x);
    ausgabe(x,NULL,erg);


    return 0;
}

int main()
{
    int daysOfMonth, dayOfYear;
    Date date;

    printf("**** Test der neuen Funktionen ****\n");

    input_date(&date);

    if(exists_date(date)) {
        printf("Das Datum %d.%d.%d existiert.\n", date.day, date.month, date.year);
    } else  {
        printf("Das Datum %d.%d.%d existiert nicht.\n", date.day, date.month, date.year);
    }

    daysOfMonth = get_days_for_month(date.month, date.year);
    printf("Der %d. Monat hat %d Tage.\n", date.month, daysOfMonth);
    dayOfYear = day_of_the_year(date);
    printf("Der %d.%d.%d ist der %d. Tag des Jahres.\n", date.day, date.month, date.year, dayOfYear);

    return 0;
}
