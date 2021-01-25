/**
 * Bibliothek mit verschiedenen Funktionen
 * Autor: Jannik Möbius
 * Erstellt am: 19.01.21
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 * Zählt den aktuellen Tag des Jahres und gibt diesen zurück
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int jahr, monat, tag, i, erg;

    printf("*** Tag des Jahres ***\n");

    jahr = year;

    //Überprüfe ob das Jahr ein Schaltjahr ist
    if(isSchaltjahr(jahr)) {
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
int min(int a, int b) {
    return a < b ? a : b;
}

/**
 * Die Funktion bekommt zwei Ganzzahlen übergeben, vergleicht die beiden Zahlen und gibt die größere Zahl zurück.
 *
 * @param a
 * @param b
 * @return groeßerer Wert
 */
int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * Die Funktion bekommt eine Ganzzahl übergeben und gibt entsprechend dem Vorzeichen eine Ganzzahl zurück.
 * Bei allen positiven Zahlen ist der Rückgabewert eine 1, bei allen negativen Zahlen eine -1, bei Null eine 0.
 *
 * @param c
 * @return 1 bei c > 0, -1 bei c < 0, 0 bei c = 0
 */
int vorzeichen(int c) {
    if(c > 0)       return 1;
    else if(c < 0)  return -1;
    return 0;
}

/**
 * Formatierte Ausgabe zum Testen der vorherigen Funktionen
 *
 * @param x
 * @param y
 * @param erg
 */
void ausgabe(int x, int y, int erg) {

    if(y == NULL) printf(" %d\t", x);
    else printf(" %d, %d ", x,y);

    printf("\t| %d \n", erg);
}

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


/*
 * Überprüft ob das gegebene Jahr ein Schaltjahr ist
 * falls ja wird 1,
 * falls nicht wird 0 zurückgegeben
 */
int isSchaltjahr(int jahr) {
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

int main()
{
    printf("Tag des Jahres: %i\n", day_of_the_year(31, 12, 2018));
    return 0;
}
