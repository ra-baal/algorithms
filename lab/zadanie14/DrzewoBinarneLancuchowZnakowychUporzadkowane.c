/*!
 * AlgoSD Laboratorium
 * Zadanie 14
 * Drzewo binarne łańcuchów znakowych z uporządkowaniem.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "DrzewoBinarneLancuchowZnakowychUporzadkowane.h"

/*! Dodaje element od uprządkowanego drzewa binarnego.
 * @param T - wskaźnik na wskaźnik na drzewo
 * @param rodz - pomocniczno dla wywołań rekurencyjnych, używać z NULL!!
 * @param lancuch - dodawany element */
void dodaj_rek(elD** T, elD* rodz, const char lancuch[]) {

    if (!(*T)) {
        elD* nowy = malloc(sizeof(elD));
        strncpy( nowy->lancuch, lancuch, LANCUCH_MAX - 1 );
        nowy->lancuch[LANCUCH_MAX-1]=0;
        nowy->lewy = NULL;
        nowy->prawy = NULL;
        nowy->licznik = 1;
        nowy->rodzic = rodz;
        *T = nowy;
    }
    else if ( strncmp( lancuch, (*T)->lancuch, LANCUCH_MAX) < 0 ) {
        dodaj_rek(&(*T)->lewy, *T, lancuch );
    }
    else if ( strncmp(lancuch, (*T)->lancuch, LANCUCH_MAX) > 0 ) {
        dodaj_rek(&(*T)->prawy, *T, lancuch);
    }
    else {
        ++((*T)->licznik);
    }
}

/*!
 * Interfejs funkcji dodaj_rek.
 * @param drzewo
 * @param lancuch
 */
void dodaj(elD** drzewo, const char lancuch[]) {
   dodaj_rek(drzewo, NULL, lancuch);
}

/** Usuwa z uporządkowanego (z każdego usunie) drzewa podaną wartość. */
int usun(drzewo* T, const char lancuch[]) {
    elD* do_usuniecia = NULL;
    elD* rodzic = NULL; // rodzic elementu do usunięcia
    elD* zastepnik = NULL; // element, który w strukturze drzewa zastąpi usuwany el.
    elD** rodzic_syn = NULL; // pole dziecka (lewy albo prawy) rodzica el. do_usunięcia

    if (!(*T))
        return 0;

    do_usuniecia = szukaj(*T, lancuch);

    if (!do_usuniecia)
        return 0;

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
            }
            else {
                rodzic_syn = &rodzic->prawy;
            }
        }

        if (do_usuniecia->lewy && do_usuniecia->prawy) {
            // posiada i lewe i prawe dziecko
            zastepnik = nastepnik(do_usuniecia);

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
    }

    if (rodzic)
        *rodzic_syn = zastepnik;
    else
        *T = zastepnik;

    return 1;

}

/** Szuka elementu w drzewie uporządkowanym.
 * Zwraca wzkaźnik na węzeł zawierający dany element. */
elD* szukaj(drzewo T, const char szukany[]) {

    elD* lewy;

    if (T) {
        if ( strncmp(szukany, T->lancuch, LANCUCH_MAX) == 0 )
            return T;
        else if ( strncmp(szukany, T->lancuch, LANCUCH_MAX) < 0 && (lewy = szukaj(T->lewy, szukany)) )
            return lewy;
        else // if ( y > T->klucz )
            return szukaj(T->prawy, szukany);
    }

    return NULL; // == T
}

/** Zwraca adres węzła następnika w->lancuch.
 * NULL gdy brak*/
elD* nastepnik(elD* w) {
    elD* p;

    if(!w){
//        printf("Nie ma takiej wartosci!\n");
        return NULL;
    }

    if ( ((p = w->prawy)) ) // gdy istnieje prawe dziecko
        while (p->lewy)
            p = p->lewy; // to bierzemy najmniejszego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->lewy != w ) // gdy NIE istnieje prawe dzieck, to dopóki ISTNIEJE rodzic i nie przyszliśmy z lewej strony
            w = p;

    return p;

}

/** Zwraca adres węzła poprzednika w->lancuch.
 * NULL gdy brak*/
elD* poprzednik(elD* w) {
    elD* p;

    if(!w){
//        printf("Nie ma takiej wartosci!\n");
        return NULL;
    }

    if ( ((p = w->lewy)) ) // gdy istnieje lewe dziecko
        while (p->prawy)
            p = p->prawy; // to bierzemy największego z tego poddrzewa
    else while ( ((p = w->rodzic)) && p->prawy != w ) // gdy NIE istnieje lewe dziecko, to dopóki ISTNIEJE rodzic i nie przyszliśmy z prawej strony
            w = p;

    return p;

}

/*!
 * Zwraca przez argument najmniejszą wartość elementu w drzewie uporządkowanym.
 * @param T Drzewo binarne uporządkowane łańcuchów znakowych.
 * @param zwracany_lancuch  Łańcuch, do którego ma zostać zapisana wartość.
 * NULL gdy drzewo puste.
 * Podana tablica znaków (bufor) musi mieć odpowiednią długość!
 */
int minimum(drzewo T, char * zwracanyLancuch) {
    if (T) {
        while (T->lewy)
            T = T->lewy;
        strncpy(zwracanyLancuch, T->lancuch, LANCUCH_MAX - 1);
        return 1;
    }

    zwracanyLancuch = NULL;
    return 0;
}
/*!
 * Zwraca przez argument największą wartość elementu w drzewie uporządkowanym.
 * @param T Drzewo binarne uporządkowane łańcuchów znakowych.
 * @param zwracany_lancuch  Łańcuch, do którego ma zostać zapisana wartość.
 * NULL gdy drzewo puste.
 * Podana tablica znaków (bufor) musi mieć odpowiednią długość!
 */
int maksimum(drzewo T, char * zwracanyLancuch) {
    if (T) {
        while (T->prawy)
            T = T->prawy;
        strncpy(zwracanyLancuch, T->lancuch, LANCUCH_MAX - 1);
        return 1;
    }

    zwracanyLancuch = NULL;
    return 0;
}

/** Zwraca wysokosc drzewa (liczbę poziomów).
 * Funkcja rekurencyjna. */
int wysokosc(elD* wezel) {

    if (!wezel)
        return 0;

    int wys_lew = wysokosc(wezel->lewy);
    int wys_praw = wysokosc(wezel->prawy);

    return ( (wys_lew > wys_praw) ? wys_lew : wys_praw ) + 1;
}

/*!
 * Zwalnia pamięć.
 * @param T
 */
void wyczysc(drzewo * T) {
    while (*T)
        usun(T, (*T)->lancuch);
}

void poziom_widmo_rek(int poziom, int k, int szer) {

    int i;

    if (k == poziom) {
        for (i = 0; i < (szer * (LANCUCH_MAX - poziom) / pow(2, k)); ++i)
            printf(" ");

        printf("%-6s ", NULL);
    }
    else {
        poziom_widmo_rek(poziom + 1, k, szer);
        poziom_widmo_rek(poziom + 1, k, szer);
    }
}

/** Wypisuje wartości wszystkich węzłów na poziomie k.
 * Przy pierwszym wywołaniu poziom powinien = 1 (albo też inaczej jeśli inaczej określamy poziom w T (np. licząc od zera)
 * Funkcja rekurencyjna. */
void poziom_rek(elD* wezel, int poziom, int k, int szer) {

    int i;

    if (k == poziom) {

        if (k==1) {
            for (i = 0; i < (szer * (LANCUCH_MAX - 1) / 3); ++i)
                printf(" ");
        }
        else {
            for (i = 0; i < (szer * (LANCUCH_MAX - poziom ) / pow(2, k)); ++i)
                printf(" ");
        }

        if (wezel)
            printf("%-6s ", wezel->lancuch);
        else
            printf("%-6s ", NULL);
    }
    else {
        if (wezel) {
            poziom_rek(wezel->lewy, poziom + 1, k, szer);
            poziom_rek(wezel->prawy, poziom + 1, k, szer);
        }
        else {
            poziom_widmo_rek(poziom + 1, k, szer);
            poziom_widmo_rek(poziom + 1, k, szer);
        }
    }
}

/*!
 * Wyświetla drzewo z ukazaniem struktury.
 * @param T Drzewo binarne
 */
void drukuj(drzewo T) {
    int wys = wysokosc(T);
    int i;

    if (!T){
        printf("(pusto)\n");
        return;
    }

    for (i=1; i<=wys; ++i) {
        poziom_rek(T, 1, i, (int)pow(2,wys)); // pow - szerokość potencjalna (gdyby istniały wszystkie elementy na poziomach)
        printf("\n");
    }

    printf("\n");
}


