// AlgoSD ćwiczenia
// Rafał Balcerowski
// lista 2: drzewa
//
// definicje funkcji z zadań
//
// DRZEWO BINARNE

#include <stdlib.h>
#include "funkcje.h"
#include "dodatkowe.h"


// do testów
#include <stdio.h>

/////////////////
/// zadanie 1 ///
/////////////////

elD* dodaj_sort_rek(elD* T, elD* rodz, int y) {
/* Dodaje element od uprządkowanego drzewa binarnego.
 * T - wskaźnik na drzewo
 * rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL!!
 * y - wartość (klucz) dodawanego elementu */
//    printf("%x | %x | %i\n", T, rodz, y);

    if (!T) {
//        printf("A\n");
        elD* nowy = malloc(sizeof(elD));
        nowy->klucz = y;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        return nowy;
    }

    if (y < T->klucz) {
//        printf("B\n");
        T->lewy = dodaj_sort_rek(T->lewy, T, y);
    }
    else if (y > T->klucz) {
        T->prawy = dodaj_sort_rek(T->prawy, T, y);
    }
    else {
        ++(T->licznik);
    }

    return T;
}


void dodaj_sort_rek_void(elD** T, elD* rodz, int y) {
/* Dodaje element od uprządkowanego drzewa binarnego.
 * T - wskaźnik na wskaźnik na drzewo
 * rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL!!
 * y - wartość (klucz) dodawanego elementu */

    if (!(*T)) {
        elD* nowy = malloc(sizeof(elD));
        nowy->klucz = y;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        *T = nowy;
    }
    else if (y < (*T)->klucz) {
        dodaj_sort_rek_void(&(*T)->lewy, *T, y);
    }
    else if (y > (*T)->klucz) {
        dodaj_sort_rek_void(&(*T)->prawy, *T, y);
    }
    else {
        ++((*T)->licznik);
    }
}

/////////////////
/// zadanie 2 ///
/////////////////

elD* dodaj_los_rek(elD* T, elD* rodz, int y) {
/* Dodaje element do drzewa binarnego w losowe miejsce.
 * T - wskaźnik na drzewo
 * rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL!!
 * y - wartość (klucz) dodawanego elementu */
//    printf("%x | %x | %i\n", T, rodz, y);

    if (!T) {
//        printf("A\n");
        elD *nowy = malloc(sizeof(elD));
        nowy->klucz = y;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        return nowy;
    }

    if (rand() % 2) {
//        printf("B\n");
        T->lewy = dodaj_los_rek(T->lewy, T, y);
    }
    else
        T->prawy = dodaj_los_rek(T->prawy, T, y);

    return T;
}

void dodaj_los_rek_void(elD** T, elD* rodz, int y) {
/* Dodaje element do drzewa binarnego w losowe miejsce.
 * T - wskaźnik na drzewo
 * rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL!!
 * y - wartość (klucz) dodawanego elementu */

    if (!(*T)) {
        elD* nowy = malloc(sizeof(elD));
        nowy->klucz = y;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        *T = nowy;
    }
    else if (rand() % 2) {
        dodaj_los_rek_void( &((*T)->lewy) , *T, y);
    }
    else
        dodaj_los_rek_void( &((*T)->prawy) , *T, y);

}

/////////////////
/// zadanie 3 ///
/////////////////

elD* szukaj_sort_rek(elD *T, const int y) {
/** Szuka elementu w drzewie uporządkowanym.
 * Zwraca wzkaźnik na węzeł zawierający dany element. */

    elD* lewy;

    if (T) {
        if (T->klucz == y)
            return T;
        else if ( y < T->klucz && (lewy = szukaj_sort_rek(T->lewy, y)) )
            return lewy;
        else if ( y > T->klucz )
            return szukaj_sort_rek(T->prawy, y);
    }

    return NULL; // == T
}

elD* szukaj_rek(elD *T, const int y) {
/** Szuka elementu w drzewie nieuporządkowanym.
 * Zwraca wzkaźnik na węzeł zawierający dany element. */

    elD* lewy;

    if (T) {
//        printf("%i\n", T->klucz);
        if (T->klucz == y)
            return T;
        else if ( (lewy = szukaj_rek(T->lewy, y)) )
            return lewy;
        else
            return szukaj_rek(T->prawy, y);
    }

    return NULL; // == T
}

/////////////////
/// zadanie 4 ///
/////////////////

void wyswietl_LRP_rek(elD* drzewo) {
/** porządek prosty - poprzecznie - LRP - in-order */
    if (!drzewo)
        return;

    wyswietl_LRP_rek(drzewo->lewy);
    wyswietl_elD(drzewo);
    wyswietl_LRP_rek(drzewo->prawy);
}

void wyswietl_PRL_rek(elD* drzewo) {
/** porządek odwrotny - PRL */
    if (!drzewo)
        return;

    wyswietl_PRL_rek(drzewo->prawy);
    wyswietl_elD(drzewo);
    wyswietl_PRL_rek(drzewo->lewy);
}


/////////////////
/// zadanie 5 ///
/////////////////

elD* utworz_los_rek(elD* T_rodzic, int n) {
/** tworzy zrównoważone drzewo nieuporządkowane (losowe wartości) z n elementami */

    elD* nowy;

    if (n > 0) {
        nowy = nowy_element( rand() % 100, 1, T_rodzic, NULL, NULL);

        nowy->lewy = utworz_los_rek(nowy, (n-1) / 2);
        nowy->prawy = utworz_los_rek(nowy, n / 2);


        return nowy;
    }

    return NULL;
}

void utworz_los_rek_void(elD** T, elD* rodzic, int n) {
/** tworzy zrównoważone drzewo nieuporządkowane (losowe wartości) z n elementami
 * arg: rodzic - NULL przy pierwszym wywołaniu! */

    elD* nowy;

    if (n > 0) {
        nowy = nowy_element( rand() % 100, 1, rodzic, NULL, NULL);

        utworz_los_rek_void(&(nowy->lewy), nowy, (n-1) / 2);
        utworz_los_rek_void(&(nowy->prawy), nowy, n / 2);


        *T = nowy;
    }
    else
        *T = NULL;
}


/////////////////
/// zadanie 6 ///
/////////////////

int liczebnosc_sort(elD* T, int x) {
/** Zlicza ila razy wartość x występuje w drzewie uporządkowanym */

    elD* el_x = szukaj_sort_rek(T, x);

    if (el_x)
        return el_x->licznik;
    else
        return 0;

}

int liczebnosc_los_rek(elD* T, int x) {
/** Zlicza ile razy wartość x występuje w drzewie nieuporządkowanym */

    int licznik = 0;

    if (T){
        if (T->klucz == x)
            ++licznik; // tzn. licznik = 1

        licznik += liczebnosc_los_rek(T->lewy, x);
        licznik += liczebnosc_los_rek(T->prawy, x);
    }
    return licznik;
}

// /////////////////////////
// / zadanie 7 (oraz 17) ///
// /////////////////////////
elD* nastepnik_sort(elD* w) {
/** Zwraca adres węzła następnika w->x.
 * NULL gdy brak*/

    elD* p;

    if(!w){
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    if ( ((p = w->prawy)) ) // gdy istnieje prawe dziecko
        while (p->lewy)
            p = p->lewy; // to bierzemy najmniejszego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->lewy != w ) // gdy NIE istnieje prawe dziecko, to dopóki ISTNIEJE rodzic i nie przyszliśmy z lewej strony
            w = p;

    return p;

}

elD* poprzednik_sort(elD* w) {
/** Zwraca adres węzła poprzednika w->x.
 * NULL gdy brak*/

    elD* p;

    if(!w){
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    if ( ((p = w->lewy)) ) // gdy istnieje lewe dziecko
        while (p->prawy)
            p = p->prawy; // to bierzemy największego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->prawy != w ) // gdy NIE istnieje lewe dziecko, to dopóki ISTNIEJE rodzic i nie przyszliśmy z prawej strony
            w = p;

    return p;

}

int nastepnik_sort_wart(elD* w) {
/** Zwraca wartość następnika w->x. */

    elD* p = NULL;

    if(!w){
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    if ( ((p = w->prawy)) ) // gdy istnieje prawe dziecko
        while (p->lewy)
            p = p->lewy; // to bierzemy najmniejszego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->lewy != w ) // gdy NIE istnieje prawe dzieck, to dopóki ISTNIEJE rodzic i nie przyszliśmy z lewej strony
            w = p;

    if (!p) {
        printf(BRAK_WART_INFO, "Brak nastepnika.");
        exit(BRAK_WART_KOD);
    }

    return p->klucz;
}

int poprzednik_sort_wart(elD* w) {
/** Zwraca wartość poprzednika w->x. */

    elD* p = NULL;

    if(!w){
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    if ( ((p = w->lewy)) ) // gdy istnieje lewe dziecko
        while (p->prawy)
            p = p->prawy; // to bierzemy największego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->prawy != w ) // gdy NIE istnieje lewe dziecko, to dopóki ISTNIEJE rodzic i nie przyszliśmy z prawej strony
            w = p;

    if (!p) {
        printf(BRAK_WART_INFO, "Brak poprzednika.");
        exit(BRAK_WART_KOD);
    }

    return p->klucz;
}


/////////////////
/// zadanie 8 ///
/////////////////

elD* usun(elD* T, int x) {
/** Usuwa z uporządkowanego (z każdego usunie) drzewa podaną wartość.
 * Zwraca wskaźnik na drzewo. */

    elD* do_usuniecia = NULL;
    elD* rodzic = NULL; // rodzic elementu do usunięcia
    elD* zastepnik = NULL; // element, który w strukturze drzewa zastąpi usuwany el.
    elD** rodzic_syn = NULL; // pole dziecka (lewy albo prawy) rodzica el. do_usunięcia

    if (!T) {
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    do_usuniecia = szukaj_rek(T, x);

    if (!do_usuniecia) {
        printf("Nie ma danej wartosci w drzewie.\n");
        exit(112);
    }

    if (do_usuniecia->licznik > 1) {
    // tylko zmniejszenie licznika
        --(do_usuniecia->licznik);
        zastepnik = do_usuniecia;
    }
    else {
    // zwolnienie elementu

        rodzic = do_usuniecia->rodzic; // jeżeli rodzic==NULL to usuwamy korzeń

        if (rodzic) {
        // ustalenie czy el. do usunięcia jest prawym czy lewym synem
            if (rodzic->lewy == do_usuniecia) {
                rodzic_syn = &rodzic->lewy;
            } else {
                rodzic_syn = &rodzic->prawy;
            }
        }

        if (do_usuniecia->lewy && do_usuniecia->prawy) {
        // posiada i lewe i prawe dziecko
            zastepnik = nastepnik_sort(do_usuniecia);

            if (zastepnik->rodzic->lewy == zastepnik)
                zastepnik->rodzic->lewy = zastepnik->prawy;
            else
                zastepnik->rodzic->prawy = zastepnik->prawy;

            if (zastepnik->prawy)
                zastepnik->prawy->rodzic = zastepnik->rodzic;

            zastepnik->rodzic = rodzic;

            zastepnik->lewy = do_usuniecia->lewy;
            do_usuniecia->lewy->rodzic = zastepnik;

            zastepnik->prawy = do_usuniecia->prawy;
            if (do_usuniecia->prawy != zastepnik)
                do_usuniecia->prawy->rodzic = zastepnik;

        }
        else if (do_usuniecia->lewy) {
        // posiada tylko lewe dziecko
            zastepnik = do_usuniecia->lewy;
            zastepnik->rodzic = rodzic;
        }
        else if (do_usuniecia->prawy) {
        // posiada tylko prawe dziecko
            zastepnik = do_usuniecia->prawy;
            zastepnik->rodzic = rodzic;
        }
        else {
        // nie posiada dzieci
            zastepnik = NULL;
        }

        free(do_usuniecia);
    }

    if (rodzic)
        *rodzic_syn = zastepnik;
    else
        T = zastepnik;


    return T;
}

void usun_void(elD** T, int x) {
/** Usuwa z uporządkowanego (z każdego usunie) drzewa podaną wartość. */

    elD* do_usuniecia = NULL;
    elD* rodzic = NULL; // rodzic elementu do usunięcia
    elD* zastepnik = NULL; // element, który w strukturze drzewa zastąpi usuwany el.
    elD** rodzic_syn = NULL; // pole dziecka (lewy albo prawy) rodzica el. do_usunięcia

    if (!(*T)) {
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    do_usuniecia = szukaj_rek(*T, x);

    if (!do_usuniecia) {
        printf("Nie ma danej wartosci w drzewie.\n");
        exit(112);
    }

    if (do_usuniecia->licznik > 1) {
        // tylko zmniejszenie licznika
        --(do_usuniecia->licznik);
        zastepnik = do_usuniecia;
    }
    else {
        // zwolnienie elementu

        rodzic = do_usuniecia->rodzic; // jeżeli rodzic==NULL to usuwamy korzeń

        if (rodzic) {
            // ustalenie czy el. do usunięcia jest prawym czy lewym synem
            if (rodzic->lewy == do_usuniecia) {
                rodzic_syn = &rodzic->lewy;
            } else {
                rodzic_syn = &rodzic->prawy;
            }
        }

        if (do_usuniecia->lewy && do_usuniecia->prawy) {
            // posiada i lewe i prawe dziecko
            zastepnik = nastepnik_sort(do_usuniecia);

            if (zastepnik->rodzic->lewy == zastepnik)
                zastepnik->rodzic->lewy = zastepnik->prawy;
            else
                zastepnik->rodzic->prawy = zastepnik->prawy;

            if (zastepnik->prawy)
                zastepnik->prawy->rodzic = zastepnik->rodzic;

            zastepnik->rodzic = rodzic;

            zastepnik->lewy = do_usuniecia->lewy;
            do_usuniecia->lewy->rodzic = zastepnik;

            zastepnik->prawy = do_usuniecia->prawy;
            if (do_usuniecia->prawy != zastepnik)
                do_usuniecia->prawy->rodzic = zastepnik;

        }
        else if (do_usuniecia->lewy) {
            // posiada tylko lewe dziecko
            zastepnik = do_usuniecia->lewy;
            zastepnik->rodzic = rodzic;
        }
        else if (do_usuniecia->prawy) {
            // posiada tylko prawe dziecko
            zastepnik = do_usuniecia->prawy;
            zastepnik->rodzic = rodzic;
        }
        else {
            // nie posiada dzieci
            zastepnik = NULL;
        }

        free(do_usuniecia);
    }

    if (rodzic)
        *rodzic_syn = zastepnik;
    else
        *T = zastepnik;

}

///////////////////
//// zadanie 9 ////
///////////////////

void usun_wsz_sort_void(elD** T, int x) {
/** Zeruje w podanym uporządkowanym drzewie wystąpienia danej wartości. */

    elD* do_usuniecia = NULL;
    elD* rodzic = NULL; // rodzic elementu do usunięcia
    elD* zastepnik = NULL; // element, który w strukturze drzewa zastąpi usuwany el.
    elD** rodzic_syn = NULL; // pole dziecka (lewy albo prawy) rodzica el. do_usunięcia

    if (!(*T)) {
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    do_usuniecia = szukaj_rek(*T, x);

    if (!do_usuniecia) {
        printf("Nie ma danej wartosci w drzewie.\n");
        exit(112);
    }

    // zwolnienie elementu

    rodzic = do_usuniecia->rodzic; // jeżeli rodzic==NULL to usuwamy korzeń

    if (rodzic) {
        // ustalenie czy el. do usunięcia jest prawym czy lewym synem
        if (rodzic->lewy == do_usuniecia) {
            rodzic_syn = &rodzic->lewy;
        } else {
            rodzic_syn = &rodzic->prawy;
        }
    }

    if (do_usuniecia->lewy && do_usuniecia->prawy) {
        // posiada i lewe i prawe dziecko
        zastepnik = nastepnik_sort(do_usuniecia);

        if (zastepnik->rodzic->lewy == zastepnik)
            zastepnik->rodzic->lewy = zastepnik->prawy;
        else
            zastepnik->rodzic->prawy = zastepnik->prawy;

        if (zastepnik->prawy)
            zastepnik->prawy->rodzic = zastepnik->rodzic;

        zastepnik->rodzic = rodzic;

        zastepnik->lewy = do_usuniecia->lewy;
        do_usuniecia->lewy->rodzic = zastepnik;

        zastepnik->prawy = do_usuniecia->prawy;
        if (do_usuniecia->prawy != zastepnik)
            do_usuniecia->prawy->rodzic = zastepnik;

    }
    else if (do_usuniecia->lewy) {
        // posiada tylko lewe dziecko
        zastepnik = do_usuniecia->lewy;
        zastepnik->rodzic = rodzic;
    }
    else if (do_usuniecia->prawy) {
        // posiada tylko prawe dziecko
        zastepnik = do_usuniecia->prawy;
        zastepnik->rodzic = rodzic;
    }
    else {
        // nie posiada dzieci
        zastepnik = NULL;
    }

    free(do_usuniecia);

    if (rodzic)
        *rodzic_syn = zastepnik;
    else
        *T = zastepnik;

}

void usun_wsz_los_void(elD** T, int x) {
/** Usuwa wszystkie wystąpenia wartości z nieuprządkowanego drzewa */

    elD* do_usuniecia = NULL;
    elD* rodzic = NULL; // rodzic elementu do usunięcia
    elD* zastepnik = NULL; // element, który w strukturze drzewa zastąpi usuwany el.
    elD** rodzic_syn = NULL; // pole dziecka (lewy albo prawy) rodzica el. do_usunięcia

    do_usuniecia = szukaj_rek(*T, x);
    if (!do_usuniecia) {
        return;
    }

    if (!(*T)) {
        printf(D_PUSTE_INFO);
        exit(D_PUSTE_KOD);
    }

    // zwolnienie elementu

    rodzic = do_usuniecia->rodzic; // jeżeli rodzic==NULL to usuwamy korzeń

    if (rodzic) {
        // ustalenie czy el. do usunięcia jest prawym czy lewym synem
        if (rodzic->lewy == do_usuniecia) {
            rodzic_syn = &rodzic->lewy;
        } else {
            rodzic_syn = &rodzic->prawy;
        }
    }

    if (do_usuniecia->lewy && do_usuniecia->prawy) {
        // posiada i lewe i prawe dziecko
        zastepnik = nastepnik_sort(do_usuniecia);

        if (zastepnik->rodzic->lewy == zastepnik)
            zastepnik->rodzic->lewy = zastepnik->prawy;
        else
            zastepnik->rodzic->prawy = zastepnik->prawy;

        if (zastepnik->prawy)
            zastepnik->prawy->rodzic = zastepnik->rodzic;

        zastepnik->rodzic = rodzic;

        zastepnik->lewy = do_usuniecia->lewy;
        do_usuniecia->lewy->rodzic = zastepnik;

        zastepnik->prawy = do_usuniecia->prawy;
        if (do_usuniecia->prawy && do_usuniecia->prawy != zastepnik)
            do_usuniecia->prawy->rodzic = zastepnik;

    }
    else if (do_usuniecia->lewy) {
        // posiada tylko lewe dziecko
        zastepnik = do_usuniecia->lewy;
        zastepnik->rodzic = rodzic;
    }
    else if (do_usuniecia->prawy) {
        // posiada tylko prawe dziecko
        zastepnik = do_usuniecia->prawy;
        zastepnik->rodzic = rodzic;
    }
    else {
        // nie posiada dzieci
        zastepnik = NULL;
    }

    free(do_usuniecia);

    if (rodzic)
        *rodzic_syn = zastepnik;
    else
        *T = zastepnik;

    usun_wsz_los_void(T, x);
}

//////////////////
/// zadanie 10 ///
//////////////////

int liczba_wezlow_rek(elD* wezel) {
/** Zlicza liczbę węzłów w drzewie.
 * Funkcja rekurencyjna. */

    if (wezel)
        return 1 + liczba_wezlow_rek(wezel->lewy) + liczba_wezlow_rek(wezel->prawy);
    else
        return 0;
}

//////////////////
/// zadanie 11 ///
//////////////////

int liczba_lisci_rek(elD* wezel) {
/** Zlicza liczbę liści (węzłów końcowych) w drzewie.
 * Funkcja rekurencyjna. */

    if (!wezel) // puste poddrzewo
        return 0;

    if( wezel->lewy == NULL && wezel->prawy == NULL)
        return 1;

    return liczba_lisci_rek(wezel->lewy) + liczba_lisci_rek(wezel->prawy);
}

//////////////////
/// zadanie 12 ///
//////////////////

int wysokosc_rek(elD* wezel) {
/** Zwraca wysokosc drzewa (liczbę poziomów).
 * Funkcja rekurencyjna. */

    if (!wezel)
        return 0;

    int wys_lew = wysokosc_rek(wezel->lewy);
    int wys_praw = wysokosc_rek(wezel->prawy);

    return ( (wys_lew > wys_praw) ? wys_lew : wys_praw ) + 1;
}

//////////////////
/// zadanie 13 ///
//////////////////

void poziom_rek(elD* wezel, int poziom, int k) {
/** Wypisuje wartości wszystkich węzłów na poziomie k.
 * Przy pierwszym wywołaniu poziom powinien = 1 (albo też inaczej jeśli inaczej określamy poziom w T (np. licząc od zera)
 * Funkcja rekurencyjna. */

    if (!wezel)
        return;

    if (k == poziom)
        printf("%i razy %i\n", wezel->klucz, wezel->licznik);
    else {
        poziom_rek(wezel->lewy, poziom + 1, k);
        poziom_rek(wezel->prawy, poziom + 1, k);
    }
}

//////////////////
/// zadanie 14 ///
//////////////////

int liczba_wezlow_poziom_rek(elD* wezel, int poziom, int k) {
/** Napisana jako pomocnicza dla funkcji 'szerokosc'.
 * Zwraca liczbę węzłów na danym poziomie k.
 * Funkcja rekurencyjna. */

    if (!wezel)
        return 0;

    if (k == poziom)
        return 1;

    return liczba_wezlow_poziom_rek(wezel->lewy, poziom + 1, k) + liczba_wezlow_poziom_rek(wezel->prawy, poziom + 1, k);

}

int szerokosc(elD* T) {
/** Oblicza szerokość drzewa (maksymalną liczbę węzłów na jednym poziomie. */

    int i;
    int szerokosc;
    int max_szerokosc = 0;
    int wysokosc = wysokosc_rek(T);


    for (i=1; i <= wysokosc; i++) {
        szerokosc = liczba_wezlow_poziom_rek(T,1, i);
        if (szerokosc > max_szerokosc)
            max_szerokosc = szerokosc;
    }

    return max_szerokosc;
}

//////////////////
/// zadanie 15 ///
//////////////////

/** Oblicza wyważenie drzewa.
 * Największa róznica wysokości poddrzew dla wszystkich węzłów.
 * Funkcja rekurencyjna. */
int wywazenie_wysokosc_rek(elD* wezel) {

    if (!wezel)
        return 0;

    int max_roznica_lewy = wywazenie_wysokosc_rek(wezel->lewy);
    int max_roznica_prawy = wywazenie_wysokosc_rek(wezel->prawy);

    int roznica_tutaj = wysokosc_rek(wezel->lewy) - wysokosc_rek(wezel->prawy);
    roznica_tutaj = (roznica_tutaj < 0) ? -roznica_tutaj : roznica_tutaj; // wartość bezwzględna

    int max = (max_roznica_lewy > max_roznica_prawy) ? max_roznica_lewy : max_roznica_prawy;
    max = (max > roznica_tutaj) ? max : roznica_tutaj;

    return max;

}

/** Oblicza wyważenie drzewa.
 * Największa różnica liczebności poddrzew dla wszystkich węzłów.
 * Funkcja rekurencyjna. */
int wywazenie_liczebnosc_rek(elD* wezel) {

    if (!wezel)
        return 0;

    int max_roznica_lewy = wywazenie_liczebnosc_rek(wezel->lewy);
    int max_roznica_prawy = wywazenie_liczebnosc_rek(wezel->prawy);

    int roznica_tutaj = liczba_wezlow_rek(wezel->lewy) - liczba_wezlow_rek(wezel->prawy);
    roznica_tutaj = (roznica_tutaj < 0) ? -roznica_tutaj : roznica_tutaj; // wartość bezwzględna

    int max = (max_roznica_lewy > max_roznica_prawy) ? max_roznica_lewy : max_roznica_prawy;
    max = (max > roznica_tutaj) ? max : roznica_tutaj;

    return max;

}

// ///////////////
//  zadanie 16 ///
// ///////////////

/*!
 * Funkcja typu logicznego, która porównuje dwa drzewa.
 * Struktura i zawartość.
 * @param T1 Drzewo
 * @param T2 Drzewo
 * @return Zwraca wartość 1, gdy drzewa są identyczne pod względem struktury i zawartości lub 0 w przeciwnym wypadku.
 */
BOOL sa_identyczne(elD* T1, elD* T2) {
    if ( (!T1) && (!T2) ) // dwa nule
        return TRUE; // takie same

    if ( (!T1) || (!T2) ) // jeden nul
        return FALSE; // różne

    if ( (T1->klucz != T2->klucz) || (T1->licznik != T2->licznik) )// różne klucze
        return FALSE; // różne

    // klucze w tym węźle takie same
    // sprawdzaj dalej
    return sa_identyczne(T1->lewy, T2->lewy)
    && sa_identyczne(T1->prawy, T2->prawy);
}

// ///////////////////////////////////////
//  zadanie 17 zrobione już w zadaniu 7 //`
// ///////////////////////////////////////

// /////////////
// zadanie 18 //
// /////////////

/*!
 * Funkcja typu logicznego, która porównuje dwa drzewa.
 * Tylko zawartość.
 * @param T1 Drzewo uporządkowane
 * @param T2 Drzewo uporządkowane
 * @return Zwraca wartość 1, gdy drzewa są identyczne pod względem zawartości lub 0 w przeciwnym wypadku.
 */
BOOL jest_identyczna_zawartosc(elD* T1, elD* T2) {
    if (T1)
        while (T1->lewy)
            T1 = T1->lewy; // min

    if (T2)
        while (T2->lewy)
            T2 = T2->lewy; // min

    while (T1 && T2) {
        if ( (T1->klucz != T2->klucz) || (T1->licznik != T2->licznik) )
            return FALSE;
        T1 = nastepnik_sort(T1);
        T2 = nastepnik_sort(T2);
    }

    if (T1 || T2)
        return FALSE; // jedno z drzew ma jeszcze jakieś elementy

    return TRUE;
}
