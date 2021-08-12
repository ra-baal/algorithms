// Rafał Balcerowski
// lista jednokierunkowa

#ifndef LISTA3_LISTA_H
#define LISTA3_LISTA_H

typedef struct elem_listy {
    int x;
    struct elem_listy *nast;
} ell;

typedef struct elem_listy* lista;

// zadanie 1
void pdodaj ( ell** lista , int x );
void pusun ( ell** lista );
void wyczysc(ell** lista);

#endif //LISTA3_LISTA_H
