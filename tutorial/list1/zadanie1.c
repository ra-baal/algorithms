/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 1
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include "lista1.h"

void kdodaj ( el** lista , int x ) {
    /* dodaj na końcu listy */

    el* p = malloc(sizeof(el));
    p->x = x;
    p->nast = NULL;
    el* o = ostatni(*lista);
    if ( o )
        o->nast = p;
    else
        *lista = p;
}

void pdodaj ( el** lista , int x ){
    //* dodaj na początku *//

    el* p = malloc(sizeof(el));
    p->x = x;
    p->nast = *lista;
    *lista = p;
}

el* el_war ( el* lista , int x ) {
    /* Wyszukiwanie wartości.
     * Zwraca adres */
    while ( lista ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return lista; //* brak wartości */
}

void dodaj_przed( el** lista , int x , el* cel ) { // wstawia element przed el. cel
    if ( (! *lista) || ( cel == *lista )  ) {
        pdodaj( &(*lista) , x ); /* po prostu na początek */
        return;
    }

    el* q = *lista;
    while ( q->nast != cel )
        q = q->nast;

    //wstawiamy nowy element między 'q' a 'cel'
    q->nast = malloc(sizeof(el));
    (q->nast)->nast = cel;
    (q->nast)->x = x;
}

void dodaj_za( el** lista , int x , el* cel ) { /* dodaj za el. 'cel' */
    if ( ! *lista ) {
        pdodaj( &(*lista) , x );
        return;
    }

    el* q = cel->nast;
    // dodajemy nowy element między cel a q
    cel->nast = malloc(sizeof(el));
    (cel->nast)->nast = q;
    (cel->nast)->x = x;

}

void pusun ( el** lista ) {
    /* usun poczatkowy element */

    if ( ! (*lista) )
        return;

    el* p = (*lista)->nast;
    free(*lista);
    *lista = p;
}

void kusun ( el** lista ) {
    /* usuwa element z końca listy */
    if ( ! *lista)
        return;

    el* p = *lista;
    if ( ! (p->nast) ) {
        free( p ); //* *lista == p */
        *lista = NULL;
    }
    else
    {
        while ( (p->nast)->nast )
            p = p->nast;

        free( p->nast );
        p->nast = NULL;
    }
}

void usun_dany( el** lista , el* cel ) {
    /* usuwa element o danym adresie */

    if ( ! lista )
        return;

    if ( ! cel ) // brak celu!
        return;

    if ( cel == *lista ) {
        *lista = (*lista)->nast;
        free(cel);
        return;
    }

    el* q = *lista;
    while ( q->nast != cel )
        q = q->nast;

    q->nast = cel->nast;
    free( cel );

}