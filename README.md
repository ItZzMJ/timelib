# Timelib
### Bibliothek mit verschiedenen Funktionen zur Datums-Eingabe, -Bearbeitung und -Ausgabe.
### Außerdem mit Datums-Struktur.

Autor: Jannik Möbius<br>
Letzter Commit: 08.03.2021

## Datums-Struktur
 
Zuerst wird ein leeres Datum erstellt.
```
Date date;
```
Danach kann entweder mit der Funktion input_date(&date) ein Datum aus der Kommandozeile
eingelesen werden, oder manuell erzeugt werden.
```
Date date;
date.day = 2;
date.month = 3;
date.year = 2021;
```


## Funktionen:

### day_of_the_year(Date date):
Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
Berechnung berücksichtigt. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.

<br>

### input_date(Date *date):
Die Funktion liest ein Datum ein, "*date" sollte ein Zeiger auf eine leere Datums-Struktur sein. 
Wenn das angegebene Datum ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde

<br>

### is_leapyear(int year):
Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben. 

<br>

### get_days_for_month(int month, int year):
Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.

<br> 

### exists_date(Date date):
Die Funktion überprüft, ob ein eingegebenes Datum gültig ist. Daten vor dem 1.1.1582 sind ungültig, genauso
wie alle Daten nach dem 31.12.2400.

<br>

### min(int a, int b):
Die Funktion gibt den kleineren der beiden Werte zurück

<br> 

### max(int a, int b):
Die Funktion gibt den größeren der beiden Werte zurück

<br> 

### vorzeichen(int c):
Die Funktion überprüft das Vorzeichen des gegebenen Integers. Bei positivem Vorzeichen wird 1 zurückgegeben, 
bei negativem Vorzeichen -1 und bei 0 wird 0 zurückgegeben.

<br>

## Beispielprogram zum Testen der Funktionen:

```
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
```