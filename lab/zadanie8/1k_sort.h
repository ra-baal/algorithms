


#ifndef LISTA_1K_SORT_H
#define LISTA_1K_SORT_H

/// zadanie 6 ///
// bez wartownika
void dodaj_sort(el** lista, const int x);
int pobierz_pierwszy(el* lista);
int pobierz_ostatni(el* lista);
el* wyszukaj( el* lista , const int x );
int usun_wyszukaj( el** lista , const int x );
int wczytanie_listy_sort( el** lista , char* nazwa_pliku );


/// zadamnie 7
void polacz_listy_sort(el** A , el** B);

/// zadanie 8
void porownaj_sort(el** A, el** B);
#endif //LISTA_1K_SORT_H
