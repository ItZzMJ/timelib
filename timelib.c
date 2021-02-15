/**
 * Bibliothek mit verschiedenen Datums-Funktionen
 * Autor: Jannik Möbius
 * Erstellt am: 15.02.21
 **/

#include "timelib.h"
#include <stdio.h>
#include <stdlib.h>


void input_date(int *day, int *month, int *year)
{
    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Jahr einlesen
    printf("Geben Sie das Jahr ein: ");
    do {
        scanf("%d", &*year);

        //Überprüfung der Eingabe
        if(*year < 1582 || *year > 2400) {
            printf("Jahr muss gr\x94\xe1er als 0 sein! Versuchen Sie es nochmal: ");
        }

    } while (*year < 0);

    //Überprüfe ob year ein Schaltjahr ist
    if(is_leapyear(*year)) {
        tagePM[1]++;
    }

    //Monat einlesen
    printf("Geben Sie den Monat ein: ");
    do {
        scanf("%d", &*month);

        //Überprüfung der Eingabe
        if(*month < 1 || *month > 12 ) {
            printf("Monat muss zwischen 1 und 12 gew\x84hlt werden! Versuchen Sie es nochmal: ");
        }
    } while(*month < 1 || *month > 12 );

    //Tag einlesen
    printf("Geben Sie den Tag ein: ");
    do {
        scanf("%d", &*day);

        //Überprüfung der Eingabe
        if(*day < 1 || *day > tagePM[*month-1]) {
            printf("Kein g\x81ltiger Tag! Versuchen Sie es nochmal: ");
        }
    } while(*day < 1 || *day > tagePM[*month-1]);
}



/**
 * Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 *
 * @param month
 * @param year
 * @return Anzahl der Tage des Monats
 */
int get_days_for_month(int month, int year)
{
    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Ungültige Eingabe bei year < 0 oder month > 12 oder < 1
    if(year < 0 || month > 12 || month < 1) {
        return -1;
    }

    if(is_leapyear(year)) {
        tagePM[1]++;
    }

    return tagePM[month-1];

}

/**
 * Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
 * wie alle Daten nach dem 31.12.2400.
 *
 * @return
 */
int exists_date(int day, int month, int year)
{
    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    if(year < 1582 || year > 2400) return 0; //check year
    if(month > 12  || month < 1) return 0; //check month
    if(is_leapyear(year)) tagePM[1]++; //check for leapyear
    if(day < 1 || day > tagePM[month-1]) return 0; //check for day

    //Wenn an diesem punkt angekommen existiert das Datum also return 1
    return 1;
}



/**
 * Zählt den aktuellen Tag des Jahres und gibt diesen zurück
 * Test
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int jahr, monat, tag, i, erg;

    printf("*** Tag des Jahres ***\n");

    jahr = year;

    //Überprüfe ob das Jahr ein Schaltjahr ist
    if(is_leapyear(jahr)) {
        tagePM[1]++; //Februar hat in einem Schaltjahr 29 Tage
    }

    monat = month;
    tag = day;


    //Tage Berechnen
    erg = tag;
    for(i = 0; i < monat - 1; i++) {
        erg += tagePM[i];
    }

    //Ergebnis ausgeben
    printf("\n");
    return erg;

}



/**
 * Die Funktion bekommt zwei Ganzzahlen übergeben, vergleicht die beiden Zahlen und gibt die kleinere Zahl zurück.
 *
 * @param a
 * @param b
 * @return kleinerer Wert
 */
int min(int a, int b)
{
    return a < b ? a : b;
}

/**
 * Die Funktion bekommt zwei Ganzzahlen übergeben, vergleicht die beiden Zahlen und gibt die größere Zahl zurück.
 *
 * @param a
 * @param b
 * @return groeßerer Wert
 */
int max(int a, int b)
{
    return a > b ? a : b;
}

/**
 * Die Funktion bekommt eine Ganzzahl übergeben und gibt entsprechend dem Vorzeichen eine Ganzzahl zurück.
 * Bei allen positiven Zahlen ist der Rückgabewert eine 1, bei allen negativen Zahlen eine -1, bei Null eine 0.
 *
 * @param c
 * @return 1 bei c > 0, -1 bei c < 0, 0 bei c = 0
 */
int vorzeichen(int c)
{
    if(c > 0)       return 1;
    else if(c < 0)  return -1;
    return 0;
}


/**
 * Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist
 * falls ja wird 1,
 * falls nicht wird 0 zurückgegeben
 * Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 */
int is_leapyear(int jahr)
{

    if(jahr < 1582) return -1; //Wenn Jahr kleiner ist als 0 falsche eingabe

    //Wenn das Jahr durch 4 Teilbar ist, ist es ein Schaltjahr
    if(jahr % 4 == 0) {

        // Wenn jahr durch 100 und durch 4 teilbar ist, ist es kein Schaltjahr
        if (jahr % 100 == 0) {

            //Wenn jahr durch 400 teilbar ist, ist es ein Schaltjahr
            if (jahr % 400 == 0) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

