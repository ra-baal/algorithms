/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 9
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include "lista1.h"

el* wytnij_podlista_posort(el** lista, const int min, const int max) {
    /* Wycina z posortowanej listy elementy od min do max włącznie.
     * Zwraca adres pierwszego elementu podlisty albo NULL jeśli brak.
     * Ostatni jako element nast ma ustawiony NULL (zatem podlista jest w pełni funkcjonalną listą. */

    el* poczatek; // szukany początek podlisty
    el* koniec; // koniec będzie ostatecznie wskazywał na ostatni WYCIĘTY element
    el* el_niewyciety = NULL; // el1 będzie ostatecznie wskazywał na ostatni NIE wycięty element
    el* el1 = *lista;
    while (el1) {
        if ( el1->x >= min && el1->x <= max ) {
            poczatek = el1; // mamy początek
            koniec = el1; // łapiemy koniec

            if (el_niewyciety)
                el_niewyciety->nast = koniec->nast; // omijamy element(y), kt. wycinamy


            while ( koniec->nast && (koniec->nast->x <= max) ) {
                koniec = koniec->nast; // łapiemy
                if (el_niewyciety)
                    el_niewyciety->nast = koniec->nast; // omijamy element(y), kt. wycinamy
            }

            if ( ! el_niewyciety )
                *lista = koniec->nast; // gdy wycięto początek, to zmienia się początek lsity

            koniec->nast = NULL; // podlista kończy się NULLem
            return poczatek;
        }

        el_niewyciety = el1; // poprzedni względem el1
        el1 = el1->nast;
    }

    return NULL; // brak szukanej podlisty
}

void wklej_podlista_przed_adres(el* podlista, el** lista, el* cel) {

    if ( ! podlista )
        return;

    el* p = *lista;
    while (p){
        if (p->nast == cel) {
            p->nast = podlista;
            ostatni(podlista)->nast = cel;
            return;
        }

        p = p->nast;
    }

}

void wklej_podlista_za_adres(el* podlista, el** lista, el* cel) {

    el* pamiec;

    if ( ! podlista )
        return;

    pamiec = cel->nast;
    cel->nast = podlista;
    ostatni(podlista)->nast = pamiec;

}

void polacz_listy(el** P , el** Q) {
    /* łączy dwie posortowane listy.
     * P staje się połączoną listą, a Q NULLem */

    el* p = *P;
    el* q = *Q;

    while (p && p->nast && *Q) {
        if ( p->x != p->nast->x )
            wklej_podlista_przed_adres( wytnij_podlista_posort(Q, p->x, p->nast->x) , P , el_war(*P, p->nast->x) );

        p = p->nast;
    }
}
