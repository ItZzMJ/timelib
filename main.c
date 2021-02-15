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
    int day,month,year, daysOfMonth;

    printf("**** Test der neuen Funktionen ****\n");

    input_date(&day, &month, &year);

    if(exists_date(day,month,year)) {
        printf("Das Datum %d.%d.%d existiert.\n", day, month, year);
    } else  {
        printf("Das Datum %d.%d.%d existiert nicht.\n", day, month, year);
    }

    daysOfMonth = get_days_for_month(month, year);
    printf("Der %d. Monat hat %d Tage.\n", month, daysOfMonth);


    return 0;
}
