/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 13
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include "lista1.h"

void usun_powt_cykliczna(el** poczatek) {
/* Usuwa powtórzenia z jednokierunkowej listy cyklicznej. */

    el* p = *poczatek; // "chodzik 1"
    el* q; // "chodzik 2"

    if ( ! p ) // pusto
        return; // nic do zrobienia

    while( p->nast != *poczatek ) {

        q = p->nast;
        while ( q != *poczatek ) {
            if ( p->x == q->x ) {
                usun_dany_cykliczna( &q , q );  // czy nie gubię q jak go zwalniam??? bo dalej jest sprawdzany w warunku.... ??
            }
            else {
                q = q->nast;
            }
        }

        p = p->nast;
    }
}

void usun_powt_cykliczna_rekp(el* poczatek, el* p){

    if( poczatek->nast == p )
        return; // koniec rekurencji
    else if( poczatek->nast->x == p->x )
        poczatek->nast = poczatek->nast->nast;
    else
        usun_powt_cykliczna_rekp( poczatek->nast , p );
}

void usun_powt_cykliczna_rek(el** lista){

    el* p = *lista;

    do {
        usun_powt_cykliczna_rekp(*lista, p);
        p = p->nast;
        usun_powt_cykliczna_rekp(*lista, p);
    } while ( p != *lista );
}
