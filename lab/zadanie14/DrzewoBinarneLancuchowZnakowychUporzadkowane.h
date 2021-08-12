/*!
 * AlgoSD Laboratorium
 * Zadanie 14
 * Drzewo binarne łańcuchów znakowych z uporządkowaniem.
 */
#ifndef ZADANIE14_DRZEWOBINARNELANCUCHOWZNAKOWYCHUPORZADKOWANE_H
#define ZADANIE14_DRZEWOBINARNELANCUCHOWZNAKOWYCHUPORZADKOWANE_H

#define LANCUCH_MAX 6 // maksymalny rozmiar łańcucha znaków (o jeden mniej, ostatni na zero)

typedef struct elementDrzewa {
    char lancuch[LANCUCH_MAX];
    int licznik; // liczba powtórzeń elementu
    struct elementDrzewa* rodzic; // ojciec, poprzedni
    struct elementDrzewa* lewy;
    struct elementDrzewa* prawy;
} elD;

typedef elD* drzewo;

void dodaj(drzewo* T, const char lancuch[]);
elD* szukaj(drzewo T, const char lancuch[]);
elD* nastepnik(elD* w);
elD* poprzednik(elD* w);
int usun(drzewo* T, const char lancuch[]);
int minimum(drzewo T, char * zwracaneMinimum);
int maksimum(drzewo T, char * zwracaneMaksimum);

int wysokosc(elD* wezel);
void drukuj(drzewo T);

void wyczysc(drzewo* T);

#endif //ZADANIE14_DRZEWOBINARNELANCUCHOWZNAKOWYCHUPORZADKOWANE_H
