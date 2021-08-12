// RB
// 2k
// zadanie 9 (1 dla dwukierunkowej)

#ifndef ZADANIE9_DWUKIERUNKOWA_H
#define ZADANIE9_DWUKIERUNKOWA_H

typedef struct elem2 {
    /* element listy dwukierunkowej. */
    int x;
    struct elem2 *nast;
    struct elem2 *poprz;

} el2;

void dodaj_p_2k( el2** lista , const int x);
void dodaj_k_2k( el2** lista , const int x);
void usun_p_2k( el2** lista);
void usun_k_2k( el2** lista);
el2* wyszukaj_2k ( el2* lista , int x );
int dodaj_za_2k( el2** lista, const int cel_x, const int x);
int dodaj_przed_2k( el2** lista, const int cel_x, const int x);
int usun_wyszukaj_2k( el2** lista , const int cel_x );
void wyswietl_lista_2k ( el2* lista );
void wyswietl_lista_odwr_2k ( el2* lista );
int zapis_listy_2k( el2* lista , char* nazwa_pliku );
int wczytanie_listy_2k( el2** lista , char* nazwa_pliku );

#endif //ZADANIE9_DWUKIERUNKOWA_H
