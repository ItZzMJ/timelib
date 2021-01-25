/**
 * Bibliothek mit verschiedenen Funktionen
 * Autor: Jannik M�bius
 * Erstellt am: 19.01.21
 **/

#include <stdio.h>
#include <stdlib.h>



void input_date(int *day, int *month, int *year)
{
    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Jahr einlesen
    printf("Geben Sie das Jahr ein: ");
    do {
        scanf("%d", &*year);

        //�berpr�fung der Eingabe
        if(*year < 1582 || *year > 2400) {
            printf("Jahr muss gr\x94\xe1er als 0 sein! Versuchen Sie es nochmal: ");
        }

    } while (*year < 0);

    //�berpr�fe ob year ein Schaltjahr ist
    if(is_leapyear(*year)) {
        tagePM[1]++;
    }

    //Monat einlesen
    printf("Geben Sie den Monat ein: ");
    do {
        scanf("%d", &*month);

        //�berpr�fung der Eingabe
        if(*month < 1 || *month > 12 ) {
            printf("Monat muss zwischen 1 und 12 gew\x84hlt werden! Versuchen Sie es nochmal: ");
        }
    } while(*month < 1 || *month > 12 );

    //Tag einlesen
    printf("Geben Sie den Tag ein: ");
    do {
        scanf("%d", &*day);

        //�berpr�fung der Eingabe
        if(*day < 1 || *day > tagePM[*month-1]) {
            printf("Kein g\x81ltiger Tag! Versuchen Sie es nochmal: ");
        }
    } while(*day < 1 || *day > tagePM[*month-1]);
}



/**
 * Die Funktion bestimmt f�r einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 * Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden ber�cksichtigt.
 *
 * @param month
 * @param year
 * @return Anzahl der Tage des Monats
 */
int get_days_for_month(int month, int year)
{
    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //Ung�ltige Eingabe bei year < 0 oder month > 12 oder < 1
    if(year < 0 || month > 12 || month < 1) {
        return -1;
    }

    if(is_leapyear(year)) {
        tagePM[1]++;
    }

    return tagePM[month-1];

}

/**
 * Die Funktion �berpr�ft, ob ein eingegebenes Datum g�ltig ist. Daten vor dem 1.1.1582 sind ung�ltig, genauso
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
 * Z�hlt den aktuellen Tag des Jahres und gibt diesen zur�ck
 * Test
 *
 **/
int day_of_the_year(int day, int month, int year)
{

    int tagePM[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int jahr, monat, tag, i, erg;

    printf("*** Tag des Jahres ***\n");

    jahr = year;

    //�berpr�fe ob das Jahr ein Schaltjahr ist
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
 * Die Funktion bekommt zwei Ganzzahlen �bergeben, vergleicht die beiden Zahlen und gibt die kleinere Zahl zur�ck.
 *
 * @param a
 * @param b
 * @return kleinerer Wert
 */
int min(int a, int b) {
    return a < b ? a : b;
}

/**
 * Die Funktion bekommt zwei Ganzzahlen �bergeben, vergleicht die beiden Zahlen und gibt die gr��ere Zahl zur�ck.
 *
 * @param a
 * @param b
 * @return groe�erer Wert
 */
int max(int a, int b) {
    return a > b ? a : b;
}

/**
 * Die Funktion bekommt eine Ganzzahl �bergeben und gibt entsprechend dem Vorzeichen eine Ganzzahl zur�ck.
 * Bei allen positiven Zahlen ist der R�ckgabewert eine 1, bei allen negativen Zahlen eine -1, bei Null eine 0.
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

/**
 * Testfunktion f�r Min-, Max-, und Vorzeichen-funktion
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


/**
 * Die Funktion �berpr�ft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr ist
 * falls ja wird 1,
 * falls nicht wird 0 zur�ckgegeben
 * Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zur�ckgegeben.
 */
int is_leapyear(int jahr) {

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
