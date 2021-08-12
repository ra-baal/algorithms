// AlgoSD Lab
// RB
// jednokierunkowa lista cykliczna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "1k_cykl.h"

/////////////////////////////////////////////////////////////////////////////
/// zadanie 10a (1 dla nieposortowanej jednokierunkowej listy cyklicznej) ///
/////////////////////////////////////////////////////////////////////////////

void wyswietl_el1k( el1k* e ) {
    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("adres obiektu: %x | x: %i nast: %x\n" , e , e->x , e->nast);
//        printf("adres obiektu: %p | x: %i nast: %p\n" , e , e->x , e->nast);
}

void wyswietl_1k_cykl ( el1k* poczatek ) {
/* Wyświetla jednokierunkową listę cykliczną od podanego miejsca*/

    el1k* p = poczatek;

    if ( ! p ) {
        printf("\nLISTA CYKLICZNA 1k:\t(pusta)\n");
    }
    else {

        printf("\nLISTA CYKLICZNA 1k:\n");
        while (p) {
            printf("\t");
            wyswietl_el1k(p);

            if ( p->nast == poczatek )
                break; // koniec gdy wróciliśmy do początku

            p = p->nast;
        }
    }
}

void wyswietl_odwr_1k_cykl ( el1k* poczatek, el1k* k ) {
/* Wyświetla jednokierunkową listę cykliczną od końca
 * wywywływać z k = NULL
 * parametr potrzebny do wywołań rekurencyjnych */

    if ( ! poczatek ) {
    // lista pusta
        printf("\nLISTA CYKLICZNA 1k OD KONCA:\t(pusta)\n");
        return;
    }

    if ( k == NULL ) {
    // pierwsze wywołanie
        printf("\nLISTA CYKLICZNA 1k OD KONCA:\n");
        wyswietl_odwr_1k_cykl(poczatek->nast, poczatek);
        printf("\t");
        wyswietl_el1k(poczatek);
    }
    else if ( poczatek != k ) {
    // kolejne wywołania
        wyswietl_odwr_1k_cykl(poczatek->nast, k);
        printf("\t");
        wyswietl_el1k(poczatek);
    }

}

void dodaj_p_1k_cykl ( el1k** poczatek, const int x) {
/* Dodaje element na początek. */

    el1k* p;

    el1k* nowy = malloc(sizeof(el1k));
    nowy->x = x;

    if ( *poczatek ) {
        // lista posiada elementy
        nowy->nast = *poczatek;

        p = *poczatek;
        while (p->nast != *poczatek)
            p = p->nast;

        p->nast = nowy;
    }
    else {
        // lista jest pusta
        nowy->nast = nowy;
    }

    *poczatek = nowy; // nowododany element ma być początkiem listy
}

void dodaj_k_1k_cykl ( el1k** poczatek, const int x) {
/* Dodaje element na koniec. */

    el1k* p;

    el1k* nowy = malloc(sizeof(el1k));
    nowy->x = x;

    if ( *poczatek ) {
        // lista posiada elementy
        nowy->nast = *poczatek;

        p = *poczatek;
        while (p->nast != *poczatek)
            p = p->nast;

        p->nast = nowy;
    }
    else {
        // lista jest pusta
        nowy->nast = nowy;
        *poczatek = nowy;
    }

}

void usun_p_1k_cykl ( el1k** lista ) {
/* usun poczatkowy element */

    el1k* ostatni;

    if ( ! (*lista) )
        return;

    ostatni = *lista;
    while (ostatni->nast != *lista)
        ostatni = ostatni->nast;

    if ( ostatni !=  ostatni->nast ) {
        ostatni->nast = (*lista)->nast;
        free(*lista);
        *lista = ostatni->nast;
    }
    else {
        free(*lista);
        *lista = NULL;
    }

}

void usun_k_1k_cykl ( el1k** lista ) {
/* usun końcowy element */

    el1k* ostatni;
    el1k* przedostatni;

    if ( ! (*lista) )
        return;

    przedostatni = *lista;
    ostatni = przedostatni->nast;
    // jeśli jest 1 element w liście to wskazują na to samo
    while (ostatni->nast != *lista) {
        ostatni = ostatni->nast;
        przedostatni = przedostatni->nast;
    }

    if ( ostatni != przedostatni ) {
        przedostatni->nast = ostatni->nast;
        free(ostatni);
    }
    else {
        free(*lista);
        *lista = NULL;
    }

}

el1k* wyszukaj_1k_cykl( el1k* poczatek , const int x ) {
/* Zwraca adres elementu o danej wartości x w jednokierunkowej liście cyklicznej */

    el1k* e = poczatek;

    while (e) {
        if (e->x == x)
            return e; // zwracamy adres elementu z wartością x
        else if ( e->nast == poczatek ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego x

        e = e->nast;
    }

    return NULL; // NULL == poczatek <=>  lista pusta

}

el1k* dodaj_za_1k_cykl ( el1k** poczatek , const int celx , const int x ) {
/* dodaje x za celx */

    el1k* nowy;
    el1k* cel = *poczatek;

    if ( ! (*poczatek) )
        return NULL; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego celu

        cel = cel->nast;
    }

    nowy = malloc(sizeof(el1k));
    nowy->x = x;
    nowy->nast = cel->nast;
    cel->nast = nowy;
    return nowy; // zwraca adres nowego

}

el1k* dodaj_przed_1k_cykl ( el1k** poczatek , const int celx , const int x ) {
/* dodaje x przed celx */

    el1k* poprzedni = NULL;
    el1k* cel = *poczatek;

    if ( ! (*poczatek) )
        return NULL; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego celu

        poprzedni = cel;
        cel = cel->nast;
    }

    if (poprzedni) {
        poprzedni->nast = malloc(sizeof(el1k));
        poprzedni->nast->x = x;
        poprzedni->nast->nast = cel;
        return poprzedni->nast; // zwraca adres nowego
    }
    else {
    // dodanie przed 1. el - nowy będzie nowym początkiem
        poprzedni = cel->nast;
        while (poprzedni->nast != cel)
            poprzedni = poprzedni->nast;

        poprzedni->nast = malloc(sizeof(el1k));
        poprzedni->nast->x = x;
        poprzedni->nast->nast = cel;

        *poczatek = poprzedni->nast; // nowy początkiem
        return poprzedni->nast; // zwraca adres nowego == poczatek listy
    }

}

int usun_wyszukaj_1k_cykl ( el1k** poczatek , const int celx ) {
/* usuwa x i zwraca True
 * gdy x nie ma zwraca False */

    el1k* poprzedni = NULL;
    el1k* cel = *poczatek;

    if ( ! cel )
        return 0; // niedodano - nie ma takiego celx (bo lista pusta)

    while (cel) {
        if (cel->x == celx)
            break; // cel znaleziony
        else if ( cel->nast == (*poczatek) ) // gdy powrót na początek
            return 0; // nie znaleziono szukanego celu

        poprzedni = cel;
        cel = cel->nast;
    }

    if (poprzedni) {
        poprzedni->nast = cel->nast; // ominięcie

        if (cel == cel->nast) // 1 element
            *poczatek = NULL; // lista pusta

        free(cel);
        return 1; // successful
    }
    else {
        // usunięcie pierwszego el
        poprzedni = cel->nast;
        while (poprzedni->nast != cel)
            poprzedni = poprzedni->nast;

        poprzedni->nast = cel->nast;

        if (cel == cel->nast) // tylko jeden element
            *poczatek = NULL; // lista pusta
        else
          *poczatek = cel->nast; // przesunięcie początku

        free(cel);

        return 1; // zwraca adres nowego == poczatek listy
    }

}


int zapisz_1k_cykl( el1k* lista , char* nazwa_pliku ) {
/* Zapisuje listę do pliku.
 * Zwraca: 1 - powodzenie, 0 - niepowodzenie */

    el1k* poczatek = lista;

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

int wczytaj_1k_cykl( el1k** lista , char* nazwa_pliku ) {
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
            dodaj_k_1k_cykl( lista , atoi(t) ); // lista == &(*lista) // dodawanie na końcu, aby otrzymać listę w kolejności zapisywanej
        }

    }

    fclose(plik);
    return 1; // successful
}




//////////////////
/// zadanie 12 ///
//////////////////

void usun_czesc_wspolna(el1k** A, el1k* B) {
/* z listy A usuwana wartości występujące w liście B */

    //el1k* zwol;
    el1k* a = *A;
    el1k* b = B;

    el1k* a_poprz = a;
    while (a_poprz->nast != a )
        a_poprz = a_poprz->nast;

    if ( ! a || ! b ) {
        return;
    } // któraś lista pusta, zatem nie ma żadnego elementu z B w A

    do {
        do {
            if (a->x == b->x) {

                if (a->nast == a) {
                    // usuwamy jedyny element
                    *A = NULL;
                    free(a);
                    return;
                }

                if (a == *A ) // usuwamy pierwszy element
                    *A = a->nast; // zmiana początku listy

                a = a->nast;
                free(a_poprz->nast); // zwalniamy poprzednie a
                a_poprz->nast = a;

            }
            else {
                a_poprz = a;
                a = a->nast;
            }

        } while ( a != *A );

        if ( a->x == b->x ) {
        // usuwnie pozostałego elementu z początku
            if (a->nast == a) {
            // usuwamy jedyny element
                *A = NULL;
                free(a);
                return;
            }

            if (a == *A )
            // usuwamy pierwszy element
                *A = a->nast; // zmiana początku listy
            a = a->nast;
            free(a_poprz->nast); // zwalniamy poprzednie a
            a_poprz->nast = a;
        }

        b = b->nast;
    } while ( b != B );

}
