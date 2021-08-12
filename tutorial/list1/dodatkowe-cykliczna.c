/* AlgoSD - ćwiczenia
 * Lista 1 - funkcje dodatkowe jednokierunkowej listy cyklicznej
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

void wyswietl_lista_cykliczna ( el* poczatek ) {
/* Wyświetla jednokierunkową listę cykliczną od podanego miejsca*/

    el* p = poczatek;

    if ( ! p ) {
        printf("\nLISTA CYKLICZNA:\t(pusta)\n");
    }
    else {

        printf("\nLISTA CYKLICZNA:\n");
        while (p) {
            printf("\t");
            wyswietl_el(p);

            if ( p->nast == poczatek )
                break; // koniec gdy wróciliśmy od początku

            p = p->nast;
        }
        /* printf("\n"); */
    }
}

void usun_co_k_cykliczna(el** poczatek, const int k) {
/* Usuwa co k-ty element z listy cyklicznej. */

    int i;
    el* obecny;
    el* poprzedni;

    if (! *poczatek) {
        fprintf(stderr, "Lista pusta\n");
        return;
    }

    if ( ! (k > 0) ) {
        fprintf(stderr, "Nie mozna usuwac dla k = %i\n", k);
        return;
    }

    i = 2;
    poprzedni = *poczatek;
    obecny = (*poczatek)->nast;
    while (obecny != *poczatek) { // a ostatni będzie wzięty pod uwagę?
        if ( i % k == 0 ) {
            poprzedni->nast = obecny->nast;
            free(obecny);
            obecny = poprzedni->nast;
        }
        else {
            obecny = obecny->nast;
            poprzedni = poprzedni->nast;
        }
        ++i;
    }

    // dla k == 1 pozostaje 1 element, trzeba go usunąć oddzielnie
    if ( k == 1) {
        free(*poczatek);
        *poczatek = NULL;
    }
}

void usun_co_k_cykliczna_rek(el** poczatek, el* obecny, const int k) {
/* Usuwa co k-ty element z listy cyklicznej.
 * Wersja rekurencyjna.
 *
 * Użycie: ( adres wskaźnika na listę , NULL , k ) */

    int i;
    int flaga_pierwsze_wywolanie = 0; // pierwsze wywołanie funkcji musi usunąć ostatni element listy dla k = 1

    if (! *poczatek) {
        fprintf(stderr, "Lista pusta\n");
        return;
    }

    if ( ! (k > 0) ) {
        fprintf(stderr, "Nie mozna usuwac dla k = %i\n", k);
        return;
    }

    if ( obecny == NULL ) {
        obecny = (*poczatek)->nast;
        i = 2;
        flaga_pierwsze_wywolanie = 1;
    }
    else
        i = 1;

    for ( ; i < k ; ++i ) {
        if (obecny == *poczatek)
            return;

        obecny = obecny->nast;
    }

    if (obecny == *poczatek)
        return;

    usun_co_k_cykliczna_rek(poczatek, obecny->nast, k);
    usun_dany_cykliczna(poczatek, obecny);

    if (k == 1 && flaga_pierwsze_wywolanie )
        usun_dany_cykliczna(poczatek, *poczatek);
}