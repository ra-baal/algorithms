/* AlgoSD - ćwiczenia
 * Lista 1 - funkcje dodatkowe listy dwukierunkowej
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include "lista1.h"

void wyswietl_el_lista2( el2* e ) {
/* Wyświetla dany element listy dwukierunkowej*/

    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("poprz: %p | adres obiektu: %p | x: %i nast: %p\n" , e->poprz, e , e->x , e->nast);
}

void wyswietl_lista2 ( el2* lista ) {
/* Wyświetla listę dwukierunkową od początku do końca */

    if ( ! lista ) {
        printf("\nLISTA:\t(pusta)\n");
    }
    else {

        printf("\nLISTA:\n");
        while (lista) {
            printf("\t");
            wyswietl_el_lista2(lista);
            lista = lista->nast;
        }
        /* printf("\n"); */
    }
}

