/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 2
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include "lista1.h"

el* pusun_v2 ( el* lista ) {
    /* usun poczatkowy element
     * Wersja zwracająca wskaźnik na początek listy. */


    el *p = lista;

    if (lista) {

        p = lista->nast;
        free(lista);
    }

    return p; // zwracamy wskaźnik na nowy początek listy
}

el* pdodaj_v2 ( el* lista , int x ) {
    /* dodaj na początku
     * Wersja zwracająca wskaźnik na początek listy. */

    el* p = malloc(sizeof(el));
    p->x = x;
    p->nast = lista;

    return p; // zwracamy wskaźnik na nowy początek listy
}

el* kdodaj_v2 ( el* lista , int x ) {
    /* dodaj na końcu listy
     * Wersja zwracająca wskaźnik na początek listy. */

    el* p = malloc(sizeof(el)); // p - nowy elemement dodawany na koniec listy
    p->x = x;
    p->nast = NULL;

    el* o = ostatni( lista ); // o - obecny ostatni
    if ( o ) // jeżeli istnieje ( != NULL )
        o->nast = p; // to po nim ma znajdować się ten nowy
    else // w przeciwnym razie ten nowy jest pierwszym (i jednocześnie ostatnim) elementem listy
        return p; // więc zwracamy wskaźnik na niego

    return lista; // nie następuje żadna zmiana - początek listy bez zmian
}
