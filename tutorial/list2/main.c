// AlgoSD ćwiczenia
// Rafał Balcerowski
// lista 2: drzewa

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funkcje.h"
#include "dodatkowe.h"

void drzewo_sort() {
/** test drzewa uporządkowanego */

//    int i;

    srand(time(NULL));

    printf("DRZEWO UPORZADKOWANE\n");

    elD* drzewo = NULL;
    elD* drzewo2 = NULL;

    dodaj_sort_rek_void(&drzewo, NULL, 10);
    dodaj_sort_rek_void(&drzewo, NULL, 5);
    dodaj_sort_rek_void(&drzewo, NULL, 15);
    dodaj_sort_rek_void(&drzewo, NULL, 3);
    dodaj_sort_rek_void(&drzewo, NULL, 8);
    dodaj_sort_rek_void(&drzewo, NULL, 13);
    dodaj_sort_rek_void(&drzewo, NULL, 20);
    dodaj_sort_rek_void(&drzewo, NULL, 19);
    dodaj_sort_rek_void(&drzewo, NULL, 100);


//    dodaj_sort_rek_void(&drzewo2, NULL, 20);
//    dodaj_sort_rek_void(&drzewo2, NULL, 15);
//    dodaj_sort_rek_void(&drzewo2, NULL, 5);
//    dodaj_sort_rek_void(&drzewo2, NULL, 10);
//    dodaj_sort_rek_void(&drzewo2, NULL, 100);

    printf("identycznosc-struktura i zawartosc: %s\n", (sa_identyczne(drzewo, drzewo2) == FALSE) ? "FALSZ" : "PRAWDA");
    printf("identycznosc-zawartosc: %s\n", (jest_identyczna_zawartosc(drzewo, drzewo2) == FALSE) ? "FALSZ" : "PRAWDA");

//    printf("nastepnik 20: %x\n", nastepnik_sort( szukaj_sort_rek(drzewo, 20) ) );
    printf("liczba wezlow w 3 poz: %i\n", liczba_wezlow_poziom_rek(drzewo, 0, 3));
    printf("wysokosc: %i\n", wysokosc_rek(drzewo));
    printf("szerokosc: %i\n", szerokosc(drzewo));
    printf("wywazenie-wysokosc: %i\n", wywazenie_wysokosc_rek(drzewo));
    printf("wywazenie-liczebnosc: %i\n", wywazenie_liczebnosc_rek(drzewo));

    zwolnij_rek(&drzewo);
}

void drzewo_los() {
/** test drzewa nieuporządkowanego */

//    int i;

    printf("DRZEWO NIEUPORZADKOWANE\n");

    srand(time(NULL));

    elD* drzewo = NULL;

    dodaj_los_rek_void(&drzewo, NULL, 1);
//    dodaj_los_rek_void(&drzewo, NULL, 2);
//    dodaj_los_rek_void(&drzewo, NULL, 0);
//    drzewo = dodaj_los_rek(drzewo, NULL, 1);
//    drzewo = dodaj_los_rek(drzewo, NULL, 1);
//    dodaj_los_rek_void(&drzewo, NULL, 9);

//    utworz_los_rek_void(&drzewo, NULL, 5);

    wyswietl_RLP_rek(drzewo);
    printf("Liczba lisci: %i\n", liczba_lisci_rek(drzewo));
    printf("--------------USUWANIE----------------\n");
    usun_wsz_los_void(&drzewo,1);
    wyswietl_RLP_rek(drzewo);
    printf("Liczba lisci: %i\n", liczba_lisci_rek(drzewo));

//    for (i = 0; i <= 10; i++)
//        printf("%i znaleziono w: %x\n", i, szukaj_rek(drzewo, i));

    int szukany = 1;
    printf("liczebnosc %i wynosi: %i\n", szukany, liczebnosc_los_rek(drzewo, szukany));


    zwolnij_rek(&drzewo);
}

int main() {

    drzewo_sort();

//    drzewo_los();


    return 0;
}
