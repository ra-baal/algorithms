/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 10
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

void usun_wsz_rek( el** e, const int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy
     * Wersja rekurencyjna */

    el* p = NULL; // zmienna pomocnicza

    if ( *e ) {
        if ( (*e)->x == x ) {
            p = *e; // do zwolnienia
            *e = (*e)->nast;
            free (p);
            usun_wsz_rek( e , x );

        }
        else {
            usun_wsz_rek( &((*e)->nast) , x );

        }
    }
}

el* usun_wsz_rek_v2( el* e, const int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy
     * Wersja rekurencyjna
     * Zwraca wskaźnik na (pierwszy) element listy */

    el* p = NULL; // zmienna pomocnicza
    if ( e ) {
        if ( e->x == x ) {
            p = e->nast;
            free (e);
            return usun_wsz_rek_v2(p , x);
        }
        else {
            e->nast = usun_wsz_rek_v2(e->nast , x);
            return e;
        }
    }
    else {
        return e; // == NULL - koniec listy (albo lista pusta)
    }
}


void wyswietl_lista_odwr_rek ( el* e ) {
    /* Wyświetla listę od końca do początku.
     * Rekurencyjnie */

    if (e->nast) {
        wyswietl_lista_odwr_rek(e->nast);
        printf("\t");
        wyswietl_el(e);
    }
    else {
        printf("\t");
        wyswietl_el(e); // wyświetlenie ostatniego elementu ( ale na początku )
        /* printf("\n"); */
    }

}

el* odwroc_liste_rek( el* lista ) {
    /* Odwraca listę w sposób rekurencyjny.
     * Zwraca wskaźnik na nowy pierwszy element.
     * (który należy ustawić jako wskaźnik na listę) */

    el* p; // zmienna pomocnicza - wartosc zwracana

//    printf("*lista == %p\n", *lista);
//    printf("(*lista)->nast == %p\n", (*lista)->nast);
//    printf("&(*lista)->nast  == %p\n", &(*lista)->nast );
//    printf("\n");

    if ( ! lista ) {
        return NULL; // lista pusta
    }

    if ( (lista)->nast ) {
        p = odwroc_liste_rek( lista->nast );

        ((lista)->nast)->nast = lista; // następny następnego to teraz obeceny (odwracenie listy)
        (lista)->nast = NULL;

        return p;
    }

    return lista; // ostatni element
}

el* dodaj_sort_rek(el* l, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Wersja rekurencyjna (zad 6)
 * Zwraca wsk na listę. */

    if (! l) {
        // jedyny element
        el* nowy = malloc(sizeof(el));
        nowy->x = x;
        nowy->nast = NULL;
        l = nowy;
    }
    else if ( x < l->x ) {
        // pierwszy element
        el* nowy = malloc(sizeof(el));
        nowy->x = x;
        nowy->nast = l;
        l = nowy;
    }
    else if ( l->nast ) {
        if (x < l->nast->x ) {
            // między l a l->nast
            el* nowy = malloc(sizeof(el));
            nowy->x = x;
            nowy->nast = l->nast;
            l->nast = nowy;
        }
        else {
            // REKURENCJA OD NASTĘPNEGO ELEMENTU
            l->nast = dodaj_sort_rek(l->nast, x);
        }
    }
    else {
        // ostatni element
        el* nowy = malloc(sizeof(el));
        nowy->x = x;
        l->nast = nowy;
        nowy->nast = NULL;
    }

    return l;
}

//el* usun_powt_rek(el* l, int x) {
///* Usuwa powtarzające się wartości z dowolnej listy.
// * Wersja rekurencyjna.
// * int x w pierwszym wywołaniu czymkolwiek. */
//    el *p, *q , *q_nast;
//
//    if ( ! l )
//        return l;
//
//    p = *lista;
//    while (p) {
//        //wyswietl_el(p);
//
//        q = p->nast;
//        while (q) {
//            //wyswietl_el(q);
//            if (p->x == q->x) {
//                q_nast = q->nast;
//                usun_dany(lista, q);
//                q = q_nast;
//                //return;
//            }
//            else
//                q = q->nast;
//        }
//
//        p = p->nast;
//    }
//}

void usun_powt_sort_rek(el** l) {
/* Usuwa powtarzające się wartości z posortowanej listy.
 * Wersja rekurencyjna. */

    if ( ! (*l) )
        return;

    if ( ((*l)->nast) && ((*l)->nast->x == (*l)->x) ) {
        el* do_zwolnienia = (*l)->nast;
        (*l)->nast = (*l)->nast->nast;
        free(do_zwolnienia);
        usun_powt_sort_rek(l);
    }
    else
        usun_powt_sort_rek(&(*l)->nast);
}


void usun_powt_rekp(el* l, const int x) {
/* Funkcja pomocnicza dla 'void usun_powt_rek(el** l)' */

    if ( ! l )
        return;

    if ( l->nast ) {
        if ( l->nast->x == x ) {
            el *do_zwolnienia = l->nast;
            l->nast = l->nast->nast;
            free(do_zwolnienia);
            usun_powt_rekp(l, x);
        }
        else {
            usun_powt_rekp(l->nast, x);
        }
    }
}

void usun_powt_rek(el** l) {
/* Usuwa powtarzające się wartości z listy.
 * Wersja rekurencyjna. */

    if ( *l ) {
        usun_powt_rekp(*l, (*l)->x);
        usun_powt_rek(&(*l)->nast);
    }
}
