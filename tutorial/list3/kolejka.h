// Rafał Balcerowski
// kolejka priorytetowa

#ifndef LISTA3_KOLEJKA_H
#define LISTA3_KOLEJKA_H

typedef struct elem {
    int x; // wierzchołek
    struct elem *nast;
    int priorytet; // d[x]
} el;

typedef struct elem* kolejka_priorytetowa;

el* nowa_kolejka();
void zniszcz_kolejke(el** kolejka);
int jest_pusta(el* kolejka);
int pobierz(el* kolejka);
void dodaj(el* kolejka, const int x, const int prior);

void wyswietl_el( el* e );
void wyswietl_kolejke ( el* kolejka );
#endif //LISTA3_KOLEJKA_H
