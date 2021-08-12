// Rafał Balcerowski
// kolejka priorytetowa
// od minimum od maksimum (odwrotna!)

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "kolejka.h"

el* nowa_kolejka() {
/* Konstruktor.
 * Funkcja dodająca wartowników do kolejki.
 * Zwraca wskaźnik na listę. */

    el* k = malloc(sizeof(el));
    k->nast = k; // wskazuje sam na siebie
    k->priorytet = INT_MAX;
    k->x = INT_MAX;

    el* p = malloc(sizeof(el));
    p->nast = k; // wskazuej na końcowego wartownka
    p->priorytet = INT_MIN;
    p->x = INT_MIN;

    return p;
}

void zniszcz_kolejke(el** kolejka) {
/* Funkcja usuwająca wszystkie elementy kolejki oraz wartowników. */

    while ( ! jest_pusta(*kolejka) ) { // dopóki nie jest pusta
        //fprintf(stderr,"%p\n", *lista);
        pobierz(*kolejka);
    }

    free((*kolejka)->nast); // zwolnienie wartownika
    free((*kolejka));

    *kolejka = NULL;

}

int jest_pusta(el* kolejka) {
/* zwraca 1 gdy lista pusta*/
    if ( ! kolejka ) // niezainicjalizowana
        exit(2);

    if ( kolejka->nast->priorytet != INT_MAX ) // są elementy
        return 0;

    return 1; // pusta
}


int pobierz(el* kolejka) {
/* Usuwa element o najmniejszym priorytecie i zwarca jego wartość */

    if (jest_pusta(kolejka)){
        printf("Kolejka pusta!\n");
        return INT_MAX;
    }

    int wartosc = kolejka->nast->x;

    el* zwol = kolejka->nast;
    kolejka->nast = zwol->nast;
    free(zwol);

    return wartosc;

}

void dodaj(el* kolejka, const int x, const int prior) {
/* Dodaje nowy element do kolejki */

    el* nowy;

    if( ! kolejka ) {
        // gdy lista niezainicjalizowana
        fprintf(stderr, "Lista niezainicjalizowana\n");
        exit(2);
    }

    nowy = malloc(sizeof(el));
    nowy->x = x;
    nowy->priorytet = prior;

    while ( kolejka->priorytet != INT_MAX ) {
        if ( prior < kolejka->nast->priorytet ) {
            nowy->nast = kolejka->nast;
            kolejka->nast = nowy;
            //printf("%i\n", x);
            //wyswietl_kolejke(kolejka);
            return;
        }
        kolejka = kolejka->nast;
    }
}

void wyswietl_el( el* e ) {
    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("adres: %x | x: %4i prior: %2i nast: %x\n" , e , e->x , e->priorytet , e->nast);
}

void wyswietl_kolejke ( el* kolejka ) {
    if ( ! kolejka ) { // brak listy
        printf("\nKOLEJKA PRIORYTETOWA:\t(niezainicjalizowana)\n");
    }
    else if ( kolejka->nast->priorytet == INT_MAX ) { // tylko wartownik w strukturze
        printf("\nKOLEJKA PRIORYTETOWA:\t(pusta)\n");
    }
    else {
        kolejka = kolejka->nast; // omijamy pierwszego wartownika
        printf("\nKOLEJKA PRIORYTETOWA:\n");
        while (kolejka->priorytet != INT_MAX) { // do wartownika koncowego
            printf("\t");
            wyswietl_el(kolejka);
            kolejka = kolejka->nast;
        }
    }
}