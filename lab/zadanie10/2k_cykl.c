// AlgoSD Lab
// RB
// dwukierunkowa lista cykliczna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2k_cykl.h"

////////////////////////////////////////////////////////////////////////////
/// zadanie 10b (1 dla nieposortowanej dwukierunkowej listy cyklicznej) ///
////////////////////////////////////////////////////////////////////////////

void wyswietl_el2k( el2k* e ) {
    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("poprz: %x | ten: %x | nast: %x | x: %i\n" , e->poprz , e , e->nast , e->x);
}

void wyswietl_2k_cykl ( el2k* poczatek ) {
/* Wyświetla dwukierunkową listę cykliczną od podanego miejsca*/

    el2k* p = poczatek;

    if ( ! p ) {
        printf("\nLISTA CYKLICZNA 2k:\t(pusta)\n");
    }
    else {

        printf("\nLISTA CYKLICZNA 2k:\n");
        while (p) {
            printf("\t");
            wyswietl_el2k(p);

            if ( p->nast == poczatek )
                break; // koniec gdy wróciliśmy do początku

            p = p->nast;
        }
    }
}

void wyswietl_odwr_2k_cykl ( el2k* poczatek ) {
/* Wyświetla dwukierunkową listę cykliczną od podanego miejsca*/

    el2k* p;

    if ( ! poczatek ) {
        printf("\nLISTA CYKLICZNA 2k OD KONCA:\t(pusta)\n");
    }
    else {
        p = poczatek->poprz;

        printf("\nLISTA CYKLICZNA 2k OD KONCA:\n");
        while (p) {
            printf("\t");
            wyswietl_el2k(p);

            if ( p->poprz == poczatek->poprz )
                break; // koniec gdy wróciliśmy do początku

            p = p->poprz;
        }
    }
}

void dodaj_p_2k_cykl ( el2k** poczatek, const int x) {
/* Dodaje element na początek. */

    el2k* nowy = malloc(sizeof(el2k));
    nowy->x = x;

    if ( *poczatek ) {
        // lista posiada elementy
        nowy->nast = *poczatek;
        nowy->poprz = (*poczatek)->poprz;

        (*poczatek)->poprz->nast = nowy;
        (*poczatek)->poprz = nowy;
    }
    else {
        // lista jest pusta
        nowy->nast = nowy;
        nowy->poprz = nowy;
    }

    *poczatek = nowy; // nowododany element ma być początkiem listy
}

void dodaj_k_2k_cykl ( el2k** poczatek, const int x) {
/* Dodaje element na koniec. */

    el2k* nowy = malloc(sizeof(el2k));
    nowy->x = x;

    if ( *poczatek ) {
        // lista posiada elementy
        nowy->nast = *poczatek;
        nowy->poprz = (*poczatek)->poprz;

        (*poczatek)->poprz->nast = nowy;
        (*poczatek)->poprz = nowy;
    }
    else {
        // lista jest pusta
        nowy->nast = nowy;
        nowy->poprz = nowy;
        *poczatek = nowy;
    }

}

void usun_p_2k_cykl ( el2k** lista ) {
/* usun poczatkowy element */

    el2k* ostatni;

    if ( ! (*lista) )
        return;

    ostatni = (*lista)->poprz;

    if ( ostatni !=  ostatni->nast ) {
    // więcej elementów niz 1
        ostatni->nast = (*lista)->nast;
        (*lista)->nast->poprz = ostatni;
        free(*lista);
        *lista = ostatni->nast;
    }
    else {
        free(*lista);
        *lista = NULL;
    }

}

void usun_k_2k_cykl ( el2k** lista ) {
/* usun końcowy element */

    el2k* ostatni;

    if ( ! (*lista) )
        return;

    if ( (*lista) != (*lista)->nast ) {
    // więcej niż jeden element
        ostatni = (*lista)->poprz;

        ostatni->poprz->nast = ostatni->nast; // przedostatni->nast = ostatni->nast
        ostatni->nast->poprz = ostatni->poprz;
        free(ostatni);
    }
    else {
        free(*lista);
        *lista = NULL;
    }

}

el2k* wyszukaj_2k_cykl( el2k* poczatek , const int x ) {
/* Zwraca adres elementu o danej wartości x w dwukierunkowej liście cyklicznej */

    el2k* e = poczatek;

    while (e) {
        if (e->x == x)
            return e; // zwracamy adres elementu z wartością x
        else if ( e->nast == poczatek ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego x

        e = e->nast;
    }

    return NULL; // NULL == poczatek <=>  lista pusta

}

el2k* dodaj_za_2k_cykl ( el2k** poczatek , const int celx , const int x ) {
/* dodaje x za celx */

    el2k* nowy;
    el2k* cel = *poczatek;

    if ( ! (*poczatek) )
        return NULL; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego celu

        cel = cel->nast;
    }

    nowy = malloc(sizeof(el2k));
    nowy->x = x;

    nowy->poprz = cel;
    nowy->nast = cel->nast;

    cel->nast->poprz = nowy;
    cel->nast = nowy;

    return nowy; // zwraca adres nowego

}

el2k* dodaj_przed_2k_cykl ( el2k** poczatek , const int celx , const int x ) {
/* dodaje x za celx */

    el2k* nowy;
    el2k* cel = *poczatek;

    if ( ! (*poczatek) )
        return NULL; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego celu

        cel = cel->nast;
    }

    nowy = malloc(sizeof(el2k));
    nowy->x = x;

    nowy->poprz = cel->poprz;
    nowy->nast = cel;

    cel->poprz->nast = nowy;
    cel->poprz = nowy;

    if ( cel == (*poczatek) )
        *poczatek = nowy;

    return nowy; // zwraca adres nowego

}

int usun_wyszukaj_2k_cykl ( el2k** poczatek , const int celx ) {
/* usuwa x i zwraca True
 * gdy x nie ma zwraca False */

    el2k* cel = *poczatek;

    if ( ! cel )
        return 0; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return 0; // nie znaleziono szukanego celu

        cel = cel->nast;
    }

    if ( cel == cel->nast ) {
    // jeden element i należy go usunąć

        free(*poczatek);
        *poczatek = NULL;

        return 1; // successful
    }
    else {
    // więcej elementów

        cel->poprz->nast = cel->nast;
        cel->nast->poprz = cel->poprz;

        if ( cel == (*poczatek ) )
            *poczatek = (*poczatek)->nast; // ewnetualna zmiana wsk początku listy

        free(cel);

        return 1; // zwraca adres nowego == poczatek listy
    }

}


int zapisz_2k_cykl( el2k* lista , char* nazwa_pliku ) {
/* Zapisuje listę do pliku.
 * Zwraca: 1 - powodzenie, 0 - niepowodzenie */

    el2k* poczatek = lista;

    FILE* plik = fopen( nazwa_pliku , "w" ); // otwarcie pliku do zapisu

    if ( ! plik ) {
        fprintf( stderr , "Problem z zapisem do pliku!" );
        return 0; // zwraca fałsz - niepowodzenie
    }

    if (lista) {
        do {
            fprintf(plik, "%i ", lista->x);
            lista = lista->nast;
        } while (lista != poczatek);
    }

    fclose(plik);
    return 1; // zwraca prawdę - powodzenie
}

int wczytaj_2k_cykl( el2k** lista , char* nazwa_pliku ) {
    /* Wczytuje listę z pliku dodajac ją do obecnej.
     * Zwraca: 1 - powodzenie, 0 - niepowodzenie */

    const size_t rozmiar = 200; // rozmiar bufora
    char *t;
    char bufor[rozmiar];

    FILE* plik = fopen( nazwa_pliku , "r" );
    if( ! plik )
    {
        fprintf( stderr , "Problem z odczytem z pliku." );
        return 0; // unsuccessful
    }

    while ( ! feof(plik) ) {

        fgets( bufor , rozmiar , plik );

        for ( t = strtok( bufor , " " ) ; t != NULL ; t = strtok( NULL , " " ) ) {

            printf("%i\n", atoi(t));
            dodaj_k_2k_cykl( lista , atoi(t) ); // dodawanie na końcu, aby otrzymać listę w kolejności zapisywanej
        }

    }

    fclose(plik);
    return 1; // successful
}
