//
// 2k sort
// zadanie 9 (6a dla dwukierunkowej)

#ifndef LISTA_DWUKIERUNKOWA_2K_SORT_WARTOW_H
#define LISTA_DWUKIERUNKOWA_2K_SORT_WARTOW_H

el2* konstruktor_wartow();
void destruktor_wartow(el2** lista);
void usun_p_2k_wartow( el2** lista);
void usun_k_2k_wartow( el2** lista);
int jest_pusta_wartow(el2* lista);
void dodaj_2k_sort_wartow(el2** lista, const int x);
int pobierz_pierwszy_2k_sort_wartow(el2* lista);
int pobierz_ostatni_2k_sort_wartow(el2* lista);
el2* wyszukaj_2k_sort_wartow( el2* lista , const int x );
int usun_wyszukaj_2k_sort_wartow( el2** lista , const int x );
int wczytanie_listy_2k_sort_wartow( el2** lista , char* nazwa_pliku );
void wyswietl_lista_2k_wartow ( el2* lista );
void wyswietl_lista_odwr_2k_wartow ( el2* lista );
int zapis_listy_2k_wartow( el2* lista , char* nazwa_pliku );

#endif //LISTA_DWUKIERUNKOWA_2K_SORT_WARTOW_H
