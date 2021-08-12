//
// dwukierunkowa sortowana
// zadanie 9 (6b dla dwukierunkowej)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "2k.h"
#include "2k_sort.h"

void dodaj_2k_sort(el2** lista, const int x) {
/* Dodaje element do listy dwukierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max. */

    el2* p = *lista;

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;

    if (!p) {
        // gdy lista pusta
        // => dodawanie na początku listy
        nowy->poprz = NULL;
        nowy->nast = NULL;
        *lista = nowy;
        return;
    }

    do {
        if ( x <= p->x ) {
            // dodanie w środku lub na początku

            nowy->poprz = p->poprz;
            nowy->nast = p;

            if(p->poprz)
                p->poprz->nast = nowy;
            else
                *lista = nowy;

            p->poprz = nowy;

            return;
        }

        nowy->poprz = p; // zapamietanie gdyby trzeba było dodać nowy na koniec

        p = p->nast;
    } while (p);


    // dodanie na końcu

    //nowy->poprz ustalony w pętli do-while
    nowy->nast = NULL;
    if (nowy->poprz)
        nowy->poprz->nast = nowy;


}

int pobierz_pierwszy_2k_sort(el2* lista) {
/* Pobiera pierwszy element z listy dwukierunkowej. */

    if( ! lista ) {
        fprintf(stderr, "funkcja pobierz_pierwszy(el*): lista nie moze byc pusta!\n");
        //exit(1);
    }

    return lista->x;
}

int pobierz_ostatni_2k_sort(el2* lista) {
/* Pobiera ostatni element z listy dwukierunkowej. */

    int x;

    if( ! lista ) {
        fprintf(stderr, "funkcja pobierz_ostatni(el*): lista nie może byc pusta!");
        //exit(1);
    }

    while (lista) {
        x = lista->x;
        lista = lista->nast;
    }

    return x;
}

el2* wyszukaj_2k_sort( el2* lista , const int x ) {
/* Wyszukiwanie wartości z posort. dwukierunkowej. listy.
 * Zwraca adres.
 * Zwraca 0 gdy nieznaleziono. */

    while ( lista && (x >= lista->x)  ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return NULL;// == lista; //* brak wartości */
}

int usun_wyszukaj_2k_sort( el2** lista , const int x ) {
/* Usuwa element o podajnej wartości z listy dwukierunkowej sort. */

    el2* poprzedni = NULL;
    el2* obecny = *lista;

    while ( obecny && (x >= obecny->x) ) {
        if ( x == obecny->x ) {
            /* znaleziono */

            if (poprzedni) // usuwamy element inny niż pierwszy
                poprzedni->nast = obecny->nast;
            else // usuwamy pierwszy element
                *lista = obecny->nast;

            if(obecny->nast) // obecny nie jest ostanim elementem
                obecny->nast->poprz = obecny->poprz;

            free(obecny);
            return 1; // true - znaleziono i usunieto
        }

        poprzedni = obecny;
        obecny = obecny->nast;
    }

    return 0; // false - nie ma takiej wartosci
}

int wczytanie_listy_2k_sort( el2** lista , char* nazwa_pliku ) {
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
            dodaj_2k_sort( lista , atoi(t) ); // dodawanie posortowane
        }

    }

    fclose(plik);
    return 1; // successful

}

