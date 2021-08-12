/* AlgoSD - ćwiczenia
 * Lista 1 - plik nagłówkowy dla wszystkich zadań
 * Rafał Balcerowski - 289524 */

#ifndef LISTA1_ZAD1_LISTA1_H
#define LISTA1_ZAD1_LISTA1_H

#define STRERR stdout // strumień błędów do debugowania

void errprint(const char* description, int is_stderr, int exit_code);

/////////////////////////////
/// LISTA JEDNOKIERUNKOWA ///
/////////////////////////////
typedef struct elem {
    /* Element listy jednokierunkowej (lub jednokierunkowej listy cyklicznej). */
    int x;
    struct elem *nast;
} el;

// zadanie 1
void pdodaj ( el** lista , int x );
void kdodaj ( el** lista , int x );
el* el_war ( el* lista , int x );
void dodaj_przed( el** lista , int x , el* cel );
void dodaj_za( el** lista , int x , el* cel );
void pusun ( el** lista );
void kusun ( el** lista );
void usun_dany( el** lista , el* cel );

// zadanie 2
el* pusun_v2 ( el* lista );
el* pdodaj_v2 ( el* lista , int x );
el* kdodaj_v2 ( el* lista , int x );

// zadanie 3
void usun_wsz( el** lista, int x );
el*  usun_wsz_v2( el* lista, int x );

// zadanie 4
void wyswietl_el( el* e );
void wyswietl_lista ( el* lista );
void wyswietl_lista_odwr ( el* lista );

// zadanie 5
void odwroc_liste( el** lista );

// zadanie 6
el* adres_min ( el* lista );
void zamien_elementy( el** lista, el* e1 , el* e2 );
void sortuj_elementy(el** lista);
void zamien_wartosci( el* e1 , el* e2 );
void sortuj_wartosci(el* lista);
void sortuj_elementy_eliminuj_powt(el** lista);

// bez wartownika
void dodaj_sort(el** lista, const int x);
void dodaj_sort_bez_powt(el** lista, const int x);

// z wartownikiem
el* konstruktor_wartow();
void destruktor_wartow(el** lista);
void wyswietl_lista_wartow ( el* lista );
int jest_pusta_wartow(el* lista);
void dodaj_sort_wartow(el** lista, const int x);
void dodaj_sort_wartow_bez_powt(el** lista, const int x);

// zadanie 7
el* dodaj_sort_v2(el* lista, const int x);
el* dodaj_sort_bez_powt_v2(el* lista, const int x);
// wartownik
void konstruktor_wartow_v2(el** lista);
el* destruktor_wartow_v2(el** lista);
el* dodaj_sort_wartow_v2(el* lista, const int x);
el* dodaj_sort_wartow_bez_powt_v2(el* lista, const int x);

// zadanie 8
void usun_powt_posort(el** lista);
void usun_powt(el** lista);

// zadanie 9
void polacz_listy(el** P , el** Q);
el* wytnij_podlista_posort(el** lista, const int min, const int max);
void wklej_podlista_przed_adres(el* podlista, el** lista, el* cel);
void wklej_podlista_za_adres(el* podlista, el** lista, el* cel);

// zadanie 10
el* usun_wsz_rek_v2( el* e, const int x );
void usun_wsz_rek( el** e, const int x );
void wyswietl_lista_odwr_rek ( el* e );
el* odwroc_liste_rek( el* lista );
el* dodaj_sort_rek(el* l, const int x);

void usun_powt_sort_rek(el** l);
void usun_powt_rek(el** l);
/* ... */

// dodatkowe - lista jednokierunkowa
el* ostatni( el* lista );

el* el_n (el* lista , int n );
int wczytanie_listy( el** lista , char* nazwa_pliku );
el* poprzedni(el* lista, el* element);

///////////////////////////
/// LISTA DWUKIERUNKOWA ///
///////////////////////////
typedef struct elem2 {
    /* element listy dwukierunkowej. */
    int x;
    struct elem2 *nast;
    struct elem2 *poprz;

} el2;

// zadanie 11
void dodaj_p_lista2( el2** lista , const int x);
void dodaj_k_lista2( el2** lista , const int x);
void usun_p_lista2( el2** lista);
void usun_k_lista2( el2** lista);
void dodaj_za_danym_lista2( el2** lista, el2* cel, const int x);
void dodaj_przed_danym_lista2( el2** lista, el2* cel, const int x);

// dodatkowe - lista dwukierunkowa
void wyswietl_el_lista2( el2* e );
void wyswietl_lista2( el2* lista );

///////////////////////////////////////
/// JEDNOKIERUNKOWA LISTA CYKLICZNA ///
///////////////////////////////////////
// zadanie 12
void dodaj_przed_cykliczna( el** poczatek, const int x);
void dodaj_za_cykliczna( el** poczatek, const int x);
el* el_war_cykliczna( el* poczatek , const int x );
el* el_war_cykliczna_rek ( el* plista , el* elista, const int x ); // dtk zad
void usun_dany_cykliczna( el** lista, el* cel);
void usun_dany_cykliczna_rek(const el** plista, el* elista, const int x);


// zadanie 13
void usun_powt_cykliczna(el** poczatek);
void usun_powt_cykliczna_rek(el** lista);

//void delete_new(el* text, el* l2); // funkcja pomocnicza nie potrzeba jej w pliku nagłówkowym
//void delete_repeat(el** text);



// zadanie 14
int ile_wystapien_cykliczna (el* poczatek, const int x);
int max_powt_cykliczna(el* poczatek);
int ile_wystapien_cykliczna_rek (const el* poczatek, const el* obecny , const int x); // dtk zad
int max_powt_cykliczna_rek(const el* poczatek, const el* obecny, const int wartosc, const int liczebnosc); // dtk zad

// dodatkowe - jednokierunkowa lista cykliczna
void wyswietl_lista_cykliczna( el* poczatek );
void usun_co_k_cykliczna(el** poczatek, const int k); // dtk zad
void usun_co_k_cykliczna_rek(el** poczatek, el* obecny, const int k); // dtk zad

#endif //LISTA1_ZAD1_LISTA1_H
