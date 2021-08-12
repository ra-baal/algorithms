//
// dwukierunkowa sortowana z wartownikiem
// zadanie 9 (6a dla dwukierunkowej)

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "2k.h"
#include "2k_sort_wartow.h"

el2* konstruktor_wartow() {
/* Funkcja dodająca wartownika do listy dwukierunkowej.
 * Zwraca wskaźnik na listę. */

    el2* wartownik = malloc(sizeof(el2*));
    wartownik->poprz = NULL;
    wartownik->nast = wartownik; // wskazuje sam na siebie
    wartownik->x = INT_MAX; // maksymalna wartość integera

    //*lista = wartownik;
    return wartownik;
}

void destruktor_wartow(el2** lista) {
/* Funkcja usuwająca wszystkie elementy listy 2k oraz wartownika. */

    while ( ! jest_pusta_wartow(*lista) ) { // dopóki nie jest pusta
        //fprintf(stderr,"%p\n", *lista);
        usun_p_2k_wartow(lista);
    }

    free(*lista); // zwolnienie wartownika

    *lista = NULL;

}

void usun_p_2k_wartow( el2** lista) {
/* alias: usun_p_lista2_wartow
 * Usuwa początkowy element z listy dwukierunkowej z wartownikiem */

    if ( jest_pusta_wartow(*lista) ) { // lista pusta
        fprintf(stderr, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* nast = (*lista)->nast;
    free(*lista);
    *lista = nast;

    if (*lista)
        (*lista)->poprz = NULL;
}

void usun_k_2k_wartow( el2** lista) {
/* alias: usun_k_lista2_wartow
 * Usuwa ostatni element z listy dwukierunkowej z wartownikiem  */

    if ( jest_pusta_wartow(*lista) ) { // lista pusta
        fprintf(stderr, "Nie mozna usunac elementu z pustej listy\n");
        return; // nic od usuwania
    }

    el2* ostatni = *lista;
    while (ostatni->nast != ostatni->nast->nast) // nast nie jest wart
        ostatni = ostatni->nast;

    if (ostatni->poprz) {
        (ostatni->poprz)->nast = ostatni->nast; // wsk na wartownika
        ostatni->nast->poprz = ostatni->poprz;
    }
    else {
        *lista = ostatni->nast;
        ostatni->nast->poprz = NULL;
    }

    free(ostatni);
}

int jest_pusta_wartow(el2* lista) {

    if ( ! lista ) // niezainicjalizowana
        exit(2);

    if ( lista != lista->nast ) // są elementy
        return 0;

    return 1; // pusta
}

void dodaj_2k_sort_wartow(el2** lista, const int x) {
/* Dodaje element do listy dwukierunkowej z wartownikiem przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max. */

    el2* nowy;
    el2* p = *lista;

    if (!p) {
        fprintf(stderr, "Lista niezainicjalizowana!\n");
        exit(3);
    }

    nowy = malloc(sizeof(el2));
    nowy->x = x;

    while (x > p->x) {
        p = p->nast; // szukanie miejsca do wstawienia
    }

    nowy->poprz = p->poprz;
    nowy->nast = p;

    if(p->poprz)
        p->poprz->nast = nowy;
    else
        *lista = nowy;

    p->poprz = nowy;

}

int pobierz_pierwszy_2k_sort_wartow(el2* lista) {
/* Pobiera pierwszy element z listy dwukierunkowej z wart. */

    if (!lista) {
        fprintf(stderr, "Lista niezainicjalizowana!\n");
        exit(3);
    }

    if( jest_pusta_wartow(lista) ) {
        fprintf(stderr, "funkcja pobierz_pierwszy(el*): lista nie moze byc pusta!\n");
        return 0;
    }

    return lista->x;
}

int pobierz_ostatni_2k_sort_wartow(el2* lista) {
/* Pobiera ostatni element z listy dwukierunkowej z wart. */

    if (!lista) {
        fprintf(stderr, "Lista niezainicjalizowana!\n");
        exit(3);
    }

    if( jest_pusta_wartow(lista) ) {
        fprintf(stderr, "funkcja pobierz_pierwszy(el*): lista nie moze byc pusta!\n");
        return 0;
    }

    while (lista != lista->nast)
        lista = lista->nast;

    // teraz lista wsk na wartownika

    return lista->poprz->x;
}

el2* wyszukaj_2k_sort_wartow( el2* lista , const int x ) {
/* Wyszukiwanie wartości z posort. dwukierunkowej listy z wart.
 * Zwraca adres.
 * Zwraca 0 gdy nieznaleziono. */

    while ( x >= lista->x ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return NULL;// == lista; //* brak wartości */
}

int usun_wyszukaj_2k_sort_wartow( el2** lista , const int x ) {
/* Usuwa element o podajnej wartości z listy dwukierunkowej sort. z wart. */

    el2* obecny = *lista;

    while ( x > obecny->x )
        obecny = obecny->nast;

    if ( x == obecny->x ) {

        if (obecny->poprz) // usuwamy element inny niż pierwszy
            obecny->poprz->nast = obecny->nast;
        else // usuwamy pierwszy element
            *lista = obecny->nast;

        obecny->nast->poprz = obecny->poprz;

        free(obecny);

        return 1; // true - znaleziono i usunieto
    }

    return 0; // false - nie ma takiej wartosci
}

int wczytanie_listy_2k_sort_wartow( el2** lista , char* nazwa_pliku ) {
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
            dodaj_2k_sort_wartow( lista , atoi(t) ); // dodawanie posortowane
        }

    }

    fclose(plik);
    return 1; // successful

}

void wyswietl_lista_2k_wartow ( el2* lista ) {
/* Wyświetla listę dwukierunkową z wart od początku do końca w sposób krótki */

    if ( jest_pusta_wartow(lista) ) {
        printf("pusta\n");
    }
    else {
        while (lista != lista->nast) {
            printf("%i ", lista->x);
            lista = lista->nast;
        }

        printf("\n");
    }
}

void wyswietl_lista_odwr_2k_wartow ( el2* lista ) {
/* Wyświetla listę dwukierunkową z wart od końca do początku w sposób krótki.
 * Rekurencyjnie. */

    //printf("poprz=%x ten=%x x=%x nast=%x\n", lista->poprz, lista, lista->x, lista->nast);

    if ( jest_pusta_wartow(lista) ) {
        printf("od konca: ");
    }
    else {
        wyswietl_lista_odwr_2k_wartow(lista->nast);
        printf("%i ", lista->x);
    }
}

int zapis_listy_2k_wartow( el2* lista , char* nazwa_pliku ) {
/* Zapisuje listę do pliku.
 * Zwraca: 1 - powodzenie, 0 - niepowodzenie */

    FILE* plik = fopen( nazwa_pliku , "w" ); // otwarcie pliku do zapisu

    if ( ! plik ) {
        fprintf( stderr , "Problem z zapisem do pliku!" );
        return 0; // zwraca fałsz - niepowodzenie
    }

    while ( ! jest_pusta_wartow(lista) ) {
        fprintf( plik , "%i " , lista->x );
        lista = lista->nast;
    }

    fclose(plik);
    return 1; // zwraca prawdę - powodzenie
}
