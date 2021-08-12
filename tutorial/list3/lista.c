// Rafał Balcerowski
// lista jednokierunkowa

#include <stdlib.h>
#include "lista.h"

void pdodaj ( ell** lista , int x ){
    //* dodaj na początku *//

    ell* p = malloc(sizeof(ell));
    p->x = x;
    p->nast = *lista;
    *lista = p;
}

void pusun ( ell** lista ) {
    /* usun poczatkowy element */

    if ( ! (*lista) )
        return;

    ell* p = (*lista)->nast;
    free(*lista);
    *lista = p;
}

void wyczysc(ell** lista) {
    while (*lista)
        pusun(lista);
}