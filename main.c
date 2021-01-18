/**
 *
 *
 *
 **/

#include <stdio.h>
#include <stdlib.h>

/**
 *
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
