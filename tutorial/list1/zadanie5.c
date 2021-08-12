/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 5
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include "lista1.h"

void odwroc_liste( el** lista ) {
    /* Odwraca listę w sposób iteracyjny */

    el* l = NULL; // wsk pomocniczy na poprzedni element - l od lewy

    // *lista wskazuje na obecny element - "środkowy"

    el* p; // wsk pomocniczy na następny element - p od prawy

    while ( *lista ) {
        p = (*lista)->nast; // zapamiętujemy prawy (następny)

        (*lista)->nast = l; // zmieniamy wskazanie następnego elementu względem obecnego na lewy (poprzedni) - zmiana kierunku listy

        l = (*lista); // teraz po lewo (poprzednim) będzie dla nas obecny element
        *lista = p; // za obecny element bierzemy ten po prawej (następny)
    }

    *lista = l; // ostatni lewy to teraz prawy
}