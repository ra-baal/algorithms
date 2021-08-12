// AlgoSD Lab
// RB
// dwukierunkowa lista cykliczna

#ifndef LISTA_CYKLICZNA_1K_2K_2K_CYKL_H
#define LISTA_CYKLICZNA_1K_2K_2K_CYKL_H

/// zadanie 10b (1 dla 2k_cykl)
typedef struct elementListyDwukierunkowej {
    int x;
    struct elementListyDwukierunkowej* poprz;
    struct elementListyDwukierunkowej* nast;
} el2k;

void wyswietl_el2k( el2k* e );
void wyswietl_2k_cykl ( el2k* poczatek );
void wyswietl_odwr_2k_cykl ( el2k* poczatek );
void dodaj_p_2k_cykl ( el2k** poczatek, int x);
void dodaj_k_2k_cykl ( el2k** poczatek, int x);
void usun_p_2k_cykl ( el2k** lista );
void usun_k_2k_cykl ( el2k** lista );
el2k* wyszukaj_2k_cykl( el2k* poczatek , int x );
el2k* dodaj_za_2k_cykl ( el2k** poczatek , int celx , int x );
el2k* dodaj_przed_2k_cykl ( el2k** poczatek , int celx , int x );
int usun_wyszukaj_2k_cykl ( el2k** poczatek , int celx );
int zapisz_2k_cykl( el2k* lista , char* nazwa_pliku );
int wczytaj_2k_cykl( el2k** lista , char* nazwa_pliku );



#endif //LISTA_CYKLICZNA_1K_2K_2K_CYKL_H
