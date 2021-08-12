//
// 2k sort
// zadanie 9 (6b dla dwukierunkowej)

#ifndef LISTA_DWUKIERUNKOWA_2K_SORT_H
#define LISTA_DWUKIERUNKOWA_2K_SORT_H

void dodaj_2k_sort(el2** lista, const int x);
int pobierz_pierwszy_2k_sort(el2* lista);
int pobierz_ostatni_2k_sort(el2* lista);
el2* wyszukaj_2k_sort( el2* lista , const int x );
int usun_wyszukaj_2k_sort( el2** lista , const int x );
int wczytanie_listy_2k_sort( el2** lista , char* nazwa_pliku );


#endif //LISTA_DWUKIERUNKOWA_2K_SORT_H
