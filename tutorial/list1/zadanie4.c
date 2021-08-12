/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 4
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include "lista1.h"

void wyswietl_el( el* e ) {
    /* Wyświetla dany element listy */

    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("ten: %x | x: %i nast: %x\n" , e , e->x , e->nast);
}

void wyswietl_lista ( el* lista ) {
    /* Wyświetla listę od początku do końca */

    if ( ! lista ) {
        printf("\nLISTA:\t(pusta)\n");
    }
    else {

        printf("\nLISTA:\n");
        while (lista) {
            printf("\t");
            wyswietl_el(lista);
            lista = lista->nast;
        }
        /* printf("\n"); */
    }
}

void wyswietl_lista_odwr ( el* lista ) {
    /* Jeśli lista nie jest pusta, wyświetla listę od końca do początku za pomocą funkcji 'wyswietl'_lista_odwr_rek'
     * W przeciwnym razie wyświetla stosowny komunikat. */

    printf("\nLISTA (odwrotnie):");

    if ( ! lista ) {
        printf(" (pusta)\n");
    }
    else {
        printf("\n");
        wyswietl_lista_odwr_rek( lista );
    }
}
