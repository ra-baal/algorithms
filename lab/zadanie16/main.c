#include <stdio.h>
#include <stdlib.h>

#define D_PUSTE_KOD 10 // kod błędu
#define D_PUSTE_INFO "BLAD! Drzewo puste.\n" // komunikat

// Typ logiczny - boolowski
#define TRUE 1
#define FALSE 0
typedef int BOOL;

// struktura
typedef struct elementDrzewaBinarnego {
    int klucz;
    int licznik; // liczba elementów o danym kluczu
    struct elementDrzewaBinarnego* rodzic;
    struct elementDrzewaBinarnego* lewy;
    struct elementDrzewaBinarnego* prawy;
} elD;

typedef elD* drzewoBinarne;

/*! Dodaje element od uprządkowanego drzewa binarnego.
 * @param T - wskaźnik na wskaźnik na drzewo
 * @param rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL
 * @param y - wartość (klucz) dodawanego elementu */
void dodajElement(drzewoBinarne * T, elD* rodz, int y) {
    if (!(*T)) {
        elD* nowy = malloc(sizeof(elD));
        nowy->klucz = y;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        *T = nowy;
    }
    else if (y < (*T)->klucz) {
        dodajElement(&(*T)->lewy, *T, y);
    }
    else if (y > (*T)->klucz) {
        dodajElement(&(*T)->prawy, *T, y);
    }
    else {
        ++((*T)->licznik);
    }
}

void zwolnijDrzewo(drzewoBinarne * T) {
    if ( ! (*T) )
        return;

    zwolnijDrzewo( &(*T)->lewy );
    zwolnijDrzewo( &(*T)->prawy );

    free(*T);

    *T = NULL;
}

/*! @return Zwraca adres węzła następnika w->x.
 * NULL gdy brak.*/
elD* nastepnikWezla(elD* w) {

    elD* p;

    if(!w){
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    if ( ((p = w->prawy)) ) // gdy istnieje prawe dziecko
        while (p->lewy)
            p = p->lewy; // to bierzemy najmniejszego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->lewy != w ) // gdy NIE istnieje prawe dziecko, to dopóki ISTNIEJE rodzic i nie przyszliśmy z lewej strony
            w = p;

    return p;

}

/*!
 * Funkcja typu logicznego, która porównuje dwa drzewa.
 * Tylko zawartość.
 * @param T1 Drzewo uporządkowane
 * @param T2 Drzewo uporządkowane
 * @return Zwraca wartość 1, gdy drzewa są identyczne pod względem zawartości lub 0 w przeciwnym wypadku.
 */
BOOL jestIdentycznaZawartosc(drzewoBinarne T1, drzewoBinarne T2) {
    if (T1)
        while (T1->lewy)
            T1 = T1->lewy; // min

    if (T2)
        while (T2->lewy)
            T2 = T2->lewy; // min

    while (T1 && T2) {
        if ( (T1->klucz != T2->klucz) || (T1->licznik != T2->licznik) )
            return FALSE;
        T1 = nastepnikWezla(T1);
        T2 = nastepnikWezla(T2);
    }

    if (T1 || T2)
        return FALSE; // jedno z drzew ma jeszcze jakieś elementy

    return TRUE;
}

int main() {

    drzewoBinarne d1 = NULL;
    drzewoBinarne d2 = NULL;

    dodajElement(&d1, NULL, 5);
    dodajElement(&d1, NULL, 10);
    dodajElement(&d1, NULL, 20);

    dodajElement(&d2, NULL, 10);
    dodajElement(&d2, NULL, 20);
    dodajElement(&d2, NULL, 5);

    printf("Zawartosc drzew %s identyczna.\n", (jestIdentycznaZawartosc(d1,d2) ? "jest" : "nie jest" ));

    zwolnijDrzewo(&d1);
    zwolnijDrzewo(&d2);
    return 0;
}
