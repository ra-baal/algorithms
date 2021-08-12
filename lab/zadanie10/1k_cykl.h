// AlgoSD Lab
// RB
// jednokierunkowa lista cykliczna

#ifndef LISTA_CYKLICZNA_1K_2K_1K_CYKL_H
#define LISTA_CYKLICZNA_1K_2K_1K_CYKL_H

/// zadanie 10a (1 dla 1k_cykl)
typedef struct elementListyJednokierunkowej {
    int x;
    struct elementListyJednokierunkowej* nast;
} el1k;

void wyswietl_el1k( el1k* e );
void wyswietl_1k_cykl ( el1k* poczatek );
void wyswietl_odwr_1k_cykl ( el1k* poczatek, el1k* k );
void dodaj_p_1k_cykl ( el1k** poczatek, int x);
void dodaj_k_1k_cykl ( el1k** poczatek, int x);
void usun_p_1k_cykl ( el1k** lista );
void usun_k_1k_cykl ( el1k** lista );
el1k* wyszukaj_1k_cykl( el1k* poczatek , int x );
el1k* dodaj_za_1k_cykl ( el1k** poczatek , int celx , int x );
el1k* dodaj_przed_1k_cykl ( el1k** poczatek , int celx , int x );
int usun_wyszukaj_1k_cykl ( el1k** poczatek , int celx );
int zapisz_1k_cykl( el1k* lista , char* nazwa_pliku );
int wczytaj_1k_cykl( el1k** lista , char* nazwa_pliku );


#endif //LISTA_CYKLICZNA_1K_2K_1K_CYKL_H
