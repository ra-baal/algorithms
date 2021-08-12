/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 7
 * Rafał Balcerowski - 289524 */

/* porównać dla zadania 6 dwa warianty komunikowania się funkcji z otoczeniem. */

#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

typedef el* wel; // wskaźnik na element listy

////////////////////////////////////////
//////////   BEZ WARTOWNIKA   //////////
////////////////////////////////////////
wel dodaj_sort_v2(wel lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Zwraca wsk na pierw el listy. */

    wel p = lista;

    wel nowy = malloc(sizeof(el));
    nowy->x = x;

    if(!p) {
        // gdy lista pusta
        nowy->nast = NULL;
        lista = nowy;
        return lista;
    }
    else {
        // gdy lista ma elementy
        if( x <= p->x) {
            // gdy dodanie na początek
            nowy->nast = lista;
            lista = nowy;
            return lista;
        }
        else {
            while (p->nast) {
                if (p->nast->x >= x) {
                    // gdy dodanie w środku
                    nowy->nast = p->nast;
                    p->nast = nowy;
                    return lista;
                }

                p = p->nast;
            }

            // gdy dodanie na końcu
            // p wskazuje na ostatni element
            p->nast = nowy;
            nowy->nast = NULL;
            return lista;
        }
    }
}

wel dodaj_sort_bez_powt_v2(wel lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Pomija powtórzenia.
 * Zwraca wsk na pierw el listy. */

    wel p = lista;

    if(!p) {
        // gdy lista pusta
        wel nowy = malloc(sizeof(el));
        nowy->x = x;

        nowy->nast = NULL;
        lista = nowy;
        return lista;
    }
    else {
        // gdy lista ma elementy
        if( x < p->x) {
            // gdy dodanie na początek
            wel nowy = malloc(sizeof(el));
            nowy->x = x;

            nowy->nast = lista;
            lista = nowy;
            return lista;
        }
        else {
            while (p->nast) {
                if ( x == p->x)
                    return lista;

                if (x < p->nast->x) {
                    // gdy dodanie w środku
                    wel nowy = malloc(sizeof(el));
                    nowy->x = x;

                    nowy->nast = p->nast;
                    p->nast = nowy;
                    return lista;
                }

                p = p->nast;
            }

            if ( x == p->x)
                return lista;

            // gdy dodanie na końcu
            // p wskazuje na ostatni element
            wel nowy = malloc(sizeof(el));
            nowy->x = x;

            p->nast = nowy;
            nowy->nast = NULL;
            return lista;

        }
    }
}

//////////////////////////////////////////
////////////   Z WARTOWNIKIEM   //////////
//////////////////////////////////////////
void konstruktor_wartow_v2(el** lista) {
/* Funkcja dodająca wartownika do listy jednokierunkowej. */

    wel wartownik = malloc(sizeof(el));
    wartownik->nast = wartownik; // wskazuje sam na siebie
    wartownik->x = INT_MAX; // maksymalna wartość integera

    *lista = wartownik;
    //return wartownik;
}

wel destruktor_wartow_v2(wel* lista) {
/* Funkcja usuwająca wszystkie elementy listy oraz wartownika.
 * Zwraca NULL */

    while ( ! jest_pusta_wartow(*lista) ) { // dopóki nie jest pusta
        //fprintf(stderr,"%p\n", *lista);
        pusun(lista);
    }

    free(*lista); // zwolnienie wartownika

    return NULL;

}

wel dodaj_sort_wartow_v2(wel lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Zwraca wsk na początek listy. */

    wel p;
    wel nowy;

    if( ! lista ) {
    // gdy lista niezainicjalizowana
        errprint("Lista niezainicjalizowana", 1, 3);
    }

    p = lista;

    nowy = malloc(sizeof(el));
    nowy->x = x;

    if( x <= p->x) {
        // gdy dodanie na początek
        nowy->nast = lista;
        return nowy;
    }
    else {
        // gdy dodanie gdzieś dalej
        while ( p != p->nast ) {
            if ( x <= p->nast->x ) {
                nowy->nast = p->nast;
                p->nast = nowy;
                return lista;
            }
            p = p->nast;
        }
    }
}

wel dodaj_sort_wartow_bez_powt_v2(wel lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Pomija powtórzenia.
 * Zwraca wsk na początek listy. */

    wel p;
    wel nowy;

    if( ! lista ) {
        // gdy lista niezainicjalizowana
        errprint("Lista niezainicjalizowana", 1, 3);
    }

    p = lista;

    if( x < p->x) {
        // gdy dodanie na początek
        nowy = malloc(sizeof(el));
        nowy->x = x;

        nowy->nast = lista;
        return nowy;
    }
    else {
        // gdy dodanie gdzieś dalej
        while ( p != p->nast ) {
            if ( x < p->nast->x ) {
                if ( x == p->x)
                    return lista;

                nowy = malloc(sizeof(el));
                nowy->x = x;

                nowy->nast = p->nast;
                p->nast = nowy;
                return lista;
            }
            p = p->nast;
        }
    }
}
