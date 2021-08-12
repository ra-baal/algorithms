// AlgoSD ćwiczenia
// Rafał Balcerowski
// lista 2: drzewa
//
// deklaracje funkcji z zadań
//
// DRZEWO BINARNE

#ifndef LISTA2_FUNKCJE_H
#define LISTA2_FUNKCJE_H


// STAŁE ///

#define D_PUSTE_KOD 10 // kod błędu
#define D_PUSTE_INFO "BLAD! Drzewo puste.\n" // komunikat

#define BRAK_WART_KOD 11
#define BRAK_WART_INFO "BLAD! Brak wartosci do zwrocenia: %s\n"

// Typ logiczny - boolowski
#define TRUE 1
#define FALSE 0
typedef int BOOL;


typedef struct elementDrzewa {
    int klucz;
    int licznik; // liczba elementów o danym kluczu
    struct elementDrzewa* rodzic; // ojciec, poprzedni
    struct elementDrzewa* lewy;
    struct elementDrzewa* prawy;
} elD;


// zadanie 1 ///
elD* dodaj_sort_rek(elD* T, elD* rodz, int y);
void dodaj_sort_rek_void(elD** T, elD* rodz, int y);

// zadanie 2 ///
elD* dodaj_los_rek(elD* T, elD* rodz, int y);
void dodaj_los_rek_void(elD** T, elD* rodz, int y);

// zadanie 3 ///
elD* szukaj_sort_rek(elD *T, const int y);
elD* szukaj_rek(elD *T, const int y);

// zadanie 4 ///
void wyswietl_LRP_rek(elD* drzewo);
void wyswietl_PRL_rek(elD* drzewo);

// zadanie 5 ///
elD* utworz_los_rek(elD* T_rodzic, int n);
void utworz_los_rek_void(elD** T, elD* rodzic, int n);

// zadanie 6 ///
int liczebnosc_sort(elD* T, int x);
int liczebnosc_los_rek(elD* T, int x);

// zadanie 7 ///
elD* nastepnik_sort(elD* T);
elD* poprzednik_sort(elD* T);
int nastepnik_sort_wart(elD* T);
int poprzednik_sort_wart(elD* T);

// zadanie 8 ///
elD* usun(elD* T, int x);
void usun_void(elD** T, int x);

// zadanie 9 ///
void usun_wsz_sort_void(elD** T, int x);
void usun_wsz_los_void(elD** T, int x);

// zadanie 10 ///
int liczba_wezlow_rek(elD* T);

// zadanie 11 ///
int liczba_lisci_rek(elD* T);

// zadanie 12 ///
int wysokosc_rek(elD* T);

// zadanie 13 ///
void poziom_rek(elD* T, int poziom, int k);

// zadanie 14 ///
int liczba_wezlow_poziom_rek(elD* wezel, int poziom, int k);
int szerokosc(elD* T);

// zadanie 15 ///
int wywazenie_wysokosc_rek(elD* T);
int wywazenie_liczebnosc_rek(elD* T);

// zadanie 16 ///
BOOL sa_identyczne(elD* T1, elD* T2);

// zadanie 17 ///
// zrobione w zadaniu 7

// zadanie 18 //
BOOL jest_identyczna_zawartosc(elD* T1, elD* T2);

#endif //LISTA2_FUNKCJE_H


