/* lista dwukierunkowa */
// zadanie 9 (1 dla dwukierunkowej)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "2k.h"

void dodaj_p_2k( el2** lista , const int x) {
/* alias: dodaj_p_lista2
 * Dodaje element na początku listy dwukierunkowej. */

    el2* poprzedni = *lista;

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->poprz = NULL;
    nowy->nast = poprzedni;

    if ( poprzedni )
        poprzedni->poprz = nowy;

    *lista = nowy;
}

void dodaj_k_2k( el2** lista , const int x) {
/* alias: dodaj_k_lista2
 * Dodaje element na końcu listy dwukierunkowej. */

    el2* ostatni = *lista;
    while (ostatni && ostatni->nast)
        ostatni = ostatni->nast;
    // mamy ostatni

    el2* nowy = malloc(sizeof(el2));
    nowy->x = x;
    nowy->poprz = ostatni;
    nowy->nast = NULL;


    if ( ostatni )
        ostatni->nast = nowy;
    else
        *lista = nowy;

}

void usun_p_2k( el2** lista) {
/* alias: usun_p_lista2
 * Usuwa początkowy element z listy dwukierunkowej */

    if ( ! *lista ) { // lista pusta
        fprintf(stderr, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* nast = (*lista)->nast;
    free(*lista);
    *lista = nast;

    if (*lista)
        (*lista)->poprz = NULL;
}

void usun_k_2k( el2** lista) {
/* alias: usun_k_lista2
 * Usuwa ostatni element z listy dwukierunkowej */

    if ( ! *lista ) { // lista pusta
        fprintf(stderr, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* ostatni = *lista;
    while (ostatni && ostatni->nast)
        ostatni = ostatni->nast;

    if (ostatni->poprz)
        (ostatni->poprz)->nast = NULL;
    else
        *lista = NULL;

    free(ostatni);
}

el2* wyszukaj_2k ( el2* lista , int x ) {
/* alias: el_war
 * wyszukiwanie wartości
 * zwraca adres */

    while ( lista ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return NULL;//lista; //* brak wartości */
}

int dodaj_za_2k( el2** lista, const int cel_x, const int x) {
/* alias: dodaj_za_danym_lista2
 * Dodaje element za wskazanym elementem listy dwukierunkowej.
 * Zwraca True/False */

    el2* nowy;
    el2* cel = *lista;

    while ( cel ) {
        if ( cel->x == cel_x ) {
            //znaleziono
            nowy = malloc(sizeof(el2));

            nowy->x = x;
            nowy->poprz = cel;
            nowy->nast = cel->nast;

            if (nowy->nast)
                nowy->nast->poprz = nowy;

            cel->nast = nowy;

            return 1; // successful
        }
        cel = cel->nast;
    }

    return 0; // brak takiej wartości
}

int dodaj_przed_2k( el2** lista, const int cel_x, const int x) {
/* alias: dodaj_przed_danym_lista2
 * Dodaje element przed wskazanym elementem listy dwukierunkowej.
 * Zwraca True/False */

    el2* nowy;
    el2* cel = *lista;

    while ( cel ) {
        if ( cel->x == cel_x ) {
            //znaleziono
            nowy = malloc(sizeof(el2));

            nowy->x = x;
            nowy->poprz = cel->poprz;
            nowy->nast = cel;

            if (nowy->poprz)
                nowy->poprz->nast = nowy;
            else
                *lista = nowy;

            cel->poprz = nowy;

            return 1; // successful
        }
        cel = cel->nast;
    }

    return 0; // brak takiej wartości

}

int usun_wyszukaj_2k( el2** lista , const int cel_x ) {
/* alias: usun_dany
 * usuwa element o danej wartości
 * Zwraca True/False */

    el2* cel = *lista;

    while ( cel ) {
        if ( cel->x == cel_x ) {
            //znaleziono

            if (cel->poprz)
                cel->poprz->nast = cel->nast;
            else
                *lista = cel->nast;

            if (cel->nast)
                cel->nast->poprz = cel->poprz;

            free(cel);

            return 1; // successful
        }
        cel = cel->nast;
    }

    return 0; // brak takiej wartości

}

void wyswietl_lista_2k ( el2* lista ) {
/* Wyświetla listę dwukierunkową od początku do końca w sposób krótki */

    if ( ! lista ) {
        printf("\n");
    }
    else {
        while (lista) {
            printf("%i ", lista->x);
            lista = lista->nast;
        }
        printf("\n");
    }
}

void wyswietl_lista_odwr_2k ( el2* lista ) {
/* Wyświetla listę dwukierunkową od końca do początku w sposób krótki.
 * Rekurencyjnie. */

    if ( ! lista ) {
        printf("Od konca: ");
    }
    else {
        wyswietl_lista_odwr_2k(lista->nast);
        printf("%i ", lista->x);
    }
}

int zapis_listy_2k( el2* lista , char* nazwa_pliku ) {
    /* Zapisuje listę do pliku.
     * Zwraca: 1 - powodzenie, 0 - niepowodzenie */

    FILE* plik = fopen( nazwa_pliku , "w" ); // otwarcie pliku do zapisu

    if ( ! plik ) {
        fprintf( stderr , "Problem z zapisem do pliku!" );
        return 0; // zwraca fałsz - niepowodzenie
    }

    while ( lista ) {
        fprintf( plik , "%i " , lista->x );
        lista = lista->nast;
    }

    fclose(plik);
    return 1; // zwraca prawdę - powodzenie
}

int wczytanie_listy_2k( el2** lista , char* nazwa_pliku ) {
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
            dodaj_k_2k( lista , atoi(t) );
        }

    }

    fclose(plik);
    return 1; // successful

}