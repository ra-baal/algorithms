// AlgoSD ćwiczenia
// Rafał Balcerowski
// lista 2: drzewa
//
// definicje dodatkowych funkcji
//
// DRZEWO BINARNE

#include <stdio.h>
#include <stdlib.h>
#include "dodatkowe.h"

void wyswietl_elD(elD* element) {
    if ( ! element ) {
        printf("nul\n");
    }
    else {
        printf("ten:  %6x | rodzic: %6x\n", element, element->rodzic);
        printf("klucz:%6i | licznik:%6i\n", element->klucz, element->licznik);
        printf("lewy: %6x | prawy:  %6x\n", element->lewy, element->prawy);
    }

    printf("\n");
}

void wyswietl_RLP_rek(elD* drzewo) {
/** wzdłużnie - RLP - pre-order */
    if (!drzewo)
        return;

    wyswietl_elD(drzewo);
    wyswietl_RLP_rek(drzewo->lewy);
    wyswietl_RLP_rek(drzewo->prawy);
}

void DrukujDrzewo0(elD* d, int glebokosc) {
/** Drukuje drzewo.
 * Funkcja z prezentacji prof. Jankowskiego
 * Rekurencyjna. Wywolywac z glebokosc = 0*/

    int i;

    if (d == 0) return;

    DrukujDrzewo0(d->lewy, glebokosc + 1);

    for(i = 0; i < glebokosc; i++)
        putchar('_');

    printf ("%d\n", d->klucz);
    DrukujDrzewo0(d->prawy, glebokosc + 1);
}

elD* nowy_element(int klucz, int licznik, elD* rodzic, elD* lewy, elD* prawy) {
/* Alokuje pamięć dla nowego elementu drzewa i ustawia wartości pól.
 * Zwraca wskaźnik do tego elemntu. */

    elD* nowy = malloc(sizeof(elD));

    nowy->klucz = klucz;
    nowy->licznik = licznik;
    nowy->rodzic = rodzic;
    nowy->lewy = lewy;
    nowy->prawy = prawy;

    return nowy;
}

void zwolnij_rek(elD ** T) {
    if ( ! (*T) )
        return;

    zwolnij_rek( &(*T)->lewy );
    zwolnij_rek( &(*T)->prawy );

    free(*T);

    *T = NULL;
}
