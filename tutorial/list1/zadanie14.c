/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 14
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include <stdio.h>
#include "lista1.h"

int ile_wystapien_cykliczna (el* poczatek, const int x) {
/* Zwraca liczbę wystąpień x-a w jednokierunkowej liście cyklicznej.
 * Funkcja napisana jako pomocnicza dla funkcji 'int max_powt_cykliczna(el* poczatek)'*/

    if (! poczatek) {
        return 0; // w liście pustej liczba wystąpień dowolnego x-a jest równa 0
    }

    int lx = 0; // liczba wystąpień
    el* p = poczatek;
    do {
        if ( p->x == x )
            ++lx;

        p = p->nast;

    } while ( p != poczatek);

    return lx;
}

int max_powt_cykliczna(el* poczatek) {
/* Zwraca najczęściej powtarającą się wartość z listy cyklicznej. */

    int x, lx; // wartość x, liczba x-ów w liście
    int y, ly; // wartość y, liczba y-ów w liście
    el* p;

    if (! poczatek) {
        fprintf(stderr, "int max_powt_cykliczna(%p): Lista nie moze byc pusta.\n", poczatek);
        exit(1); // lista pusta
    }

    p = poczatek;
    x = p->x; // bierzemy pierwszą wartość
    lx = ile_wystapien_cykliczna(poczatek, x); // i liczbę jej wystąpień
    do {

        y = p->nast->x; // bierzemy następną wartość
        ly = ile_wystapien_cykliczna(poczatek, y); // i liczbę jej wystąpień

        if ( ly > lx) {
        // jeśli jest ona większa
            lx = ly; // to bierzemy ją
            x = y; // oraz wartość, której dotyczy
        }

        p = p->nast;
    } while (p != poczatek);

    return x;

}

int ile_wystapien_cykliczna_rek (const el* poczatek, const el* obecny , const int x) {
/* Zwraca liczbę wystąpień x-a w jednokierunkowej liście cyklicznej.
 * Funkcja napisana jako pomocnicza dla funkcji 'int max_powt_cykliczna_rek'
 * Rekurencyjnie. */

    int liczebnosc; // wartość do ustalenia i zwrócenia

    if (! poczatek)
        liczebnosc = 0; // w liście pustej liczba wystąpień dowolnego x-a jest równa 0

    else if (obecny->x == x) {
        if (obecny->nast == poczatek)
            liczebnosc = 1;
        else
            liczebnosc = ile_wystapien_cykliczna_rek(poczatek, obecny->nast, x) + 1;
    }

    else if (obecny->nast == poczatek)
        liczebnosc = 0;
    else
        liczebnosc = ile_wystapien_cykliczna_rek(poczatek, obecny->nast, x);

    return liczebnosc;
}

int max_powt_cykliczna_rek(const el* poczatek, const el* obecny, const int wartosc, const int liczebnosc) {
/* Zwraca najczęściej powtarającą się wartość z listy cyklicznej.
 * Rekurencyjnie
 *
 * !!! Pierwsze wywołanie (lista, lista, 0, 0)*/

    int x, lx; // wartość x, liczba x-ów w liście
    int y; // wartość y, liczba y-ów w liście

    if (! poczatek) {
        fprintf(stderr, "int max_powt_cykliczna_rek(%p,--,--,--): Lista nie moze byc pusta.\n", poczatek);
        exit(1); // lista pusta
    }

    x = obecny->x;
    lx = ile_wystapien_cykliczna_rek(obecny, obecny, x);

    if ( obecny->nast != poczatek)
        y = max_powt_cykliczna_rek(poczatek,obecny->nast, lx > liczebnosc ? x : wartosc, lx > liczebnosc ? lx : liczebnosc);
    else
        return (liczebnosc > lx) ? wartosc : x;

    return y;

}