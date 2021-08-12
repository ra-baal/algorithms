/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 8
 * Rafał Balcerowski - 289524 */

#include "lista1.h"

void usun_powt(el** lista) {
    /* Usuwa powtarzające się wartości z dowolnej listy*/
    el *p, *q , *q_nast;

    if ( ! (*lista) )
        return;

    p = *lista;
    while (p) {
        //wyswietl_el(p);

        q = p->nast;
        while (q) {
            //wyswietl_el(q);
            if (p->x == q->x) {
                q_nast = q->nast;
                usun_dany(lista, q);
                q = q_nast;
                //return;
            }
            else
                q = q->nast;
        }

        p = p->nast;
    }
}

void usun_powt_posort(el** lista) {
    /* Usuwa powtarzające się wartości z posortowanej listy. */
    if ( ! (*lista) )
        return;

    el* p = *lista;
    while (p->nast) { // p && ...
        if ( p->x == (p->nast)->x )
            usun_dany(lista, p->nast);
        else
            p = p->nast;
    }
}