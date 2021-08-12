/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 3
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include "lista1.h"

void usun_wsz( el** lista, int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy */

    if ( ! *lista )
        return; // lista jest pusta, nie ma czego usuwać

    el* p; // pomocniczy wsk na element

    /* Usuwanie z początku listy */
    while ( (*lista) && (*lista)->x == x ) { /* dopóki niepusta i element do usunięcia jest na początku */
        p = (*lista)->nast;
        free(*lista);
        *lista = p;
    }

    /* Usuwanie dalszych elementów */
    el* l = *lista; // pomocniczy wsk na listę (na początek listy)
    while ( l && l->nast ) {
        if ( (l->nast)->x == x ) {
            p = l->nast; // do zwolnienia

            l->nast = (l->nast)->nast;

            free(p); // zwolnienie
        }
        else {
            l = l->nast;
        }
    }
}

el*  usun_wsz_v2( el* lista, int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy
     * Wersja zwracakąca wskaźnik na początek listy */

    if ( ! lista )
        return NULL; // lista jest pusta, nie ma czego usuwać

    el* p; // pomocniczy wsk na element

    /* Usuwanie z początku listy */
    while ( lista && lista->x == x ) { /* dopóki niepusta i element do usunięcia jest na początku */
        p = lista->nast;
        free(lista);
        lista = p;
    }

    /* Usuwanie dalszych elementów */
    el* l = lista; // pomocniczy wsk na listę (na początek listy)
    while ( l && l->nast ) {
        if ( (l->nast)->x == x ) {
            p = l->nast; // do zwolnienia

            l->nast = (l->nast)->nast;

            free(p); // zwolnienie
        }
        else {
            l = l->nast;
        }
    }

    return lista;
}
