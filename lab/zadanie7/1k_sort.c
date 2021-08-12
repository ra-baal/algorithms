/* Jednokierunkowa lista posortowana od min do max. */

//#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "1k.h"
#include "1k_sort.h"


////////////////////////////////////////
//////////   BEZ WARTOWNIKA   //////////
////////////////////////////////////////
void dodaj_sort(wel* lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max. */

    wel p = *lista;

    wel nowy = malloc(sizeof(el));
    nowy->x = x;

    if(!p) {
    // gdy lista pusta
        nowy->nast = NULL;
        *lista = nowy;
        return;
    }
    else {
    // gdy lista ma elementy
        if( x <= p->x) {
        // gdy dodanie na początek
            nowy->nast = *lista;
            *lista = nowy;
            return;
        }
        else {
            while (p->nast) {
                if (p->nast->x >= x) {
                    // gdy dodanie w środku
                    nowy->nast = p->nast;
                    p->nast = nowy;
                    return;
                }

                p = p->nast;
            }

            // gdy dodanie na końcu
            // p wskazuje na ostatni element
            p->nast = nowy;
            nowy->nast = NULL;
            return;

        }
    }
}

int pobierz_pierwszy(wel lista) {
/* Pobiera pierwszy element z listy jednokierunkowej. */

    if( ! lista ) {
        fprintf(stderr, "funkcja pobierz_pierwszy(el*): lista nie moze byc pusta!");
        exit(1);
    }

    return lista->x;
}

int pobierz_ostatni(wel lista) {
/* Pobiera ostatni element z listy jednokierunkowej. */

    int x;

    if( ! lista ) {
        fprintf(stderr, "funkcja pobierz_ostatni(el*): lista nie może byc pusta!");
        exit(1);
    }

    while (lista) {
        x = lista->x;
        lista = lista->nast;
    }

    return x;
}

el* wyszukaj( wel lista , const int x ) {
/* Wyszukiwanie wartości z posort. jednokier. listy.
 * Zwraca adres.
 * Zwraca 0 gdy nieznaleziono. */

    while ( lista && (x >= lista->x)  ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return NULL;// == lista; //* brak wartości */
}

int usun_wyszukaj( wel* lista , const int x ) {
/* Usuwa element o podajnej wartości z listy jednokierunkowej. */

    wel poprzedni = NULL;
    wel obecny = *lista;

    while ( obecny && (x >= obecny->x) ) {
        if ( x == obecny->x ) {
        /* znaleziono */
            if (poprzedni) {
            // usuwamy element inny niż pierwszy
                if (obecny->nast)
                    poprzedni->nast = obecny->nast;
                else
                    poprzedni->nast = NULL;

                free(obecny);
            }
            else {
            // usuwamy pierwszy element
                if (obecny->nast)
                    *lista = obecny->nast;
                else
                    *lista= NULL;

                free(obecny);
            }

            return 1; // true - znaleziono i usunieto
        }

        poprzedni = obecny;
        obecny = obecny->nast;
    }

    return 0; // false - nie ma takiej wartosci
}

int wczytanie_listy_sort( el** lista , char* nazwa_pliku ) {
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
            dodaj_sort( lista , atoi(t) ); // dodawanie posortowane
        }

    }

    fclose(plik);
    return 1; // successful

}

//// zadanie 7 /////
void polacz_listy_sort(el** A, el** B) {
/* Łączy dwie listy posortowane w jedną.
 * *A będzie wsk na nową posortowaną listę.
 * *B będzie NULLem. */

    el* p; // początek listy głównej (ostatecznie będzie wskazywać na całą połączoną listę
    el* q; // początek listy pobocznej - z niej elementy będą przekładane do listy p

    el* pi; // iterator listy p (głównej) - element przed którym należy wstawić elementy z q
    el* qi; // iterator listy q (pobocznej) - ostatni element podlisty z q, który zostanie przeniesiony do p

    el* pi_poprz; // element poprzedzający pi - po nim należy wstawić należy wstawić elementy z q

    if ( ! *A ) {
        *A = *B;
        *B = NULL;
        return;
    }
    if ( ! *B )
        return;

    if ( (*A)->x <= (*B)->x ) {
    // pierwszy element A mniejszy niż B
        p = *A; // A będzie listą główną
        q = *B; // B poboczną
    }
    else {
    // pierw. el. B większy niż A
        p = *B; // B będzie listą główną
        q = *A; // A poboczną
    }

    pi = p->nast;
    pi_poprz = p;

    while ( q ) { // && pi
    // dopóki lista poboczna q nie jest pusta

        qi = q;

        while ( pi && pi->x < qi->x ) {
            pi_poprz = pi;
            pi = pi->nast;
        }

        while ( qi->nast && ( ! pi || qi->nast->x <= pi->x) )

            qi = qi->nast;

        pi_poprz->nast = q;
        q = qi->nast;
        qi->nast = pi;

        qi = q;

        pi_poprz = pi;

        if (pi)
            pi = pi->nast;
    }

    *A = p;
    *B = NULL; // == q
}

