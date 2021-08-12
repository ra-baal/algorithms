//
// lista_jednokierunkowa.h
//

#ifndef ZADANIE1_LISTA_JEDNOKIERUNKOWA_H
#define ZADANIE1_LISTA_JEDNOKIERUNKOWA_H


typedef struct elem {
    int x;
    struct elem *nast;
} el;

void wyswietl_el( el* e );
void pdodaj ( el** lista , int x );
el* ostatni( el* lista );
el* el_n (el* lista , int n );
void kdodaj ( el** lista , int x );
el* el_war ( el* lista , int x );
void pusun ( el** lista );
void kusun ( el** lista );
void usun_dany( el** lista , el* cel );
int dodaj_przed( el** lista , int x , el* cel );
int dodaj_za( el** lista , int x , el* cel );
void wyswietl_lista ( el* lista );

int zapis_listy( el* lista , char* nazwa_pliku );
int wczytanie_listy( el** lista , char* nazwa_pliku );

void usun_wsz( el** lista, int x );
void usun_wsz_rek( el** lista, int x );

void odwroc_liste( el** lista );
el* odwroc_liste_rek( el* lista );

/// zadanie 6 ///
// bez wartownika
void dodaj_sort(el** lista, const int x);
int pobierz_pierwszy(el* lista);
int pobierz_ostatni(el* lista);
el* wyszukaj( el* lista , const int x );
int usun_wyszukaj( el** lista , const int x );
int wczytanie_listy_sort( el** lista , char* nazwa_pliku );

// z wartownikiem
el* konstruktor_wartow();
void destruktor_wartow(el** lista);
void wyswietl_lista_wartow ( el* lista );
int jest_pusta_wartow(el* lista);
void dodaj_sort_wartow(el** lista, const int x);
int pobierz_pierwszy_wartow(el* lista);
int pobierz_ostatni_wartow(el* lista);
el* wyszukaj_wartow( el* lista , const int x );
int usun_wyszukaj_wartow( el** lista , const int x );
int wczytanie_listy_sort_wartow( el** lista , char* nazwa_pliku );
int zapis_listy_wartow( el* lista , char* nazwa_pliku );

#endif //ZADANIE1_LISTA_JEDNOKIERUNKOWA_H
