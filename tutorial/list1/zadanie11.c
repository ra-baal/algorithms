/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 11
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include <stdio.h>
#include "lista1.h"

void dodaj_p_lista2( el2** lista , const int x) {
/* Dodaje element na początku listy dwukierunkowej. */

    el2* poprzedni = *lista;

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->poprz = NULL;
    nowy->nast = poprzedni;

    if ( poprzedni )
        poprzedni->poprz = nowy;

    *lista = nowy;
}

void dodaj_k_lista2( el2** lista , const int x) {
/* Dodaje element na końcu listy dwukierunkowej. */

    el2* ostatni = *lista;
    while (ostatni && ostatni->nast)
        ostatni = ostatni->nast;
    // mamy ostatni

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->poprz = ostatni;
    nowy->nast = NULL;


    if ( ostatni )
        ostatni->nast = nowy;
    else
        *lista = nowy;

}

void usun_p_lista2( el2** lista) {
/* Usuwa początkowy element z listy dwukierunkowej */

    if ( ! *lista ) { // lista pusta
        fprintf(STRERR, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* nast = (*lista)->nast;
    free(*lista);
    *lista = nast;

    if (*lista)
        (*lista)->poprz = NULL;
}

void usun_k_lista2( el2** lista) {
/* Usuwa ostatni element z listy dwukierunkowej */

    if ( ! *lista ) { // lista pusta
        fprintf(STRERR, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* ostatni = *lista;
    while (ostatni && ostatni->nast)
        ostatni = ostatni->nast;

    if (ostatni->poprz)
        (ostatni->poprz)->nast = NULL;
    else
        *lista = NULL;

    free(ostatni);
}

void dodaj_za_danym_lista2( el2** lista, el2* cel, const int x) {
/* Dodaje element za wskazanym elementem listy dwukierunkowej. */

    if (! *lista || ! cel )
        return;

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->poprz = cel;
    nowy->nast = cel->nast;

    if (nowy->nast)
        nowy->nast->poprz = nowy;

    cel->nast = nowy;

}

void dodaj_przed_danym_lista2( el2** lista, el2* cel, const int x) {
/* Dodaje element za wskazanym elementem listy dwukierunkowej. */

    if (! *lista || ! cel )
        return;

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->nast = cel;

    if ( ! (nowy->poprz = cel->poprz) )
        *lista = nowy;

    if (nowy->poprz)
        nowy->poprz->nast = nowy;

    cel->poprz = nowy;

}
