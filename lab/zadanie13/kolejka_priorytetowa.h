// AlgoSD Lab
// Rafał Balcerowski
// zadanie 13

#ifndef KOLEJKA_PRIORYTETOWA_KOLEJKA_PRIORYTETOWA_H
#define KOLEJKA_PRIORYTETOWA_KOLEJKA_PRIORYTETOWA_H

typedef struct elem {
    int x;
    struct elem *nast;
    int priorytet;
} el;

el* nowa_kolejka();
void zniszcz_kolejke(el** kolejka);
int jest_pusta(el* kolejka);
int pobierz(el* kolejka);
void dodaj(el* kolejka, const int x, const int prior);
int zmien_priorytet(el* kolejka, const int x, const int nowy_prior);
void wyswietl_kolejke ( el* kolejka );

#endif //KOLEJKA_PRIORYTETOWA_KOLEJKA_PRIORYTETOWA_H
