/* Jednokierunkowa lista posortowana od min do max. */

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista_jednokierunkowa.h"

typedef el* wel; // wskaźnik na element listy


void errprint(const char* description, int is_stderr, int exit_code) {
    fprintf( is_stderr ? stderr : stdout , "%s\n" , description );
    if (exit_code)
        exit(exit_code);
}


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

////////////////////////////////////////
//////////   Z WARTOWNIKIEM   //////////
////////////////////////////////////////
wel konstruktor_wartow() {
/* Funkcja dodająca wartownika do listy jednokierunkowej.
 * Zwraca wskaźnik na listę. */

    wel wartownik = malloc(sizeof(el));
    wartownik->nast = wartownik; // wskazuje sam na siebie
    wartownik->x = INT_MAX; // maksymalna wartość integera

    //*lista = wartownik;
    return wartownik;
}

void destruktor_wartow(wel* lista) {
/* Funkcja usuwająca wszystkie elementy listy oraz wartownika. */

    while ( ! jest_pusta_wartow(*lista) ) { // dopóki nie jest pusta
        //fprintf(stderr,"%p\n", *lista);
        pusun(lista);
    }

    free(*lista); // zwolnienie wartownika

    *lista = NULL;

}

int jest_pusta_wartow(wel lista) {

    if ( ! lista ) // niezainicjalizowana
        exit(2);

    if ( lista != lista->nast ) // są elementy
        return 0;

    return 1; // pusta
}

void wyswietl_lista_wartow ( wel lista ) {
    if ( ! lista  ) { // brak listy
        printf("\nLISTA:\t(niezainicjalizowana)\n");
    }
    else if ( lista == lista->nast ) { // tylko wartownik w strukturze
        printf("\nLISTA:\t(pusta)\n");
    }
    else {
        printf("\nLISTA:");
        while (lista != lista->nast) { // do wartownika
            printf("\t");
            wyswietl_el(lista);
            lista = lista->nast;
        }
        /* printf("\n"); */
    }
}

void dodaj_sort_wartow(wel* lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max. */

    wel p;
    wel nowy;

    if( ! (*lista) ) {
    // gdy lista niezainicjalizowana
        errprint("Lista niezainicjalizowana", 1, 3);
    }

    p = *lista;

    nowy = malloc(sizeof(el));
    nowy->x = x;

    if( x <= p->x) {
    // gdy dodanie na początek
        nowy->nast = *lista;
        *lista = nowy;
        return;
    }
    else {
    // gdy dodanie gdzieś dalej
        while ( p != p->nast ) {
            if ( x <= p->nast->x ) {
                nowy->nast = p->nast;
                p->nast = nowy;
                return;
            }
            p = p->nast;
        }
    }
}

int pobierz_pierwszy_wartow(wel lista) {
/* Pobiera pierwszy element z listy jednokierunkowej z wartownikiem. */

    if( ! lista )
        errprint("Lista niezainicjalizowana", 1, 3);

    if( lista == lista->nast )
        errprint("Nie mozna pobrac: lista pusta", 1, 5);

    return lista->x;
}

int pobierz_ostatni_wartow(wel lista) {
/* Pobiera ostatni element z listy jednokierunkowej z wartownikiem. */

    int x;

    if( ! lista )
        errprint("Lista niezainicjalizowana", 1, 3);

    if( lista == lista->nast )
        errprint("Nie mozna pobrac: lista pusta", 1, 5);

    while( lista != lista->nast ) {
        x = lista->x;
        lista = lista->nast;
    }

    return x;
}

el* wyszukaj_wartow( wel lista , const int x ) {
/* Wyszukiwanie wartości w posortowanej liście jednokierunkowej z wartownikiem.
 * Zwraca adres. */

    if( ! lista )
        errprint("Lista niezainicjalizowana", 1, 3);


    while ( (lista != lista->nast) && (x >= lista->x)  ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }


    return NULL;

}

int usun_wyszukaj_wartow( wel* lista , const int x ) {
/* Usuwa element o podanej wartości z listy jednokierunkowej z wartownikiem. */

    if( ! *lista )
        errprint("Lista niezainicjalizowana", 1, 3);

    wel poprzedni = NULL;
    wel obecny = *lista;
    while( x >= obecny->x ) {
        if ( obecny->x == x ) {
            if (poprzedni) {
            // usuwamy element inny niż pierwszy
                poprzedni->nast = obecny->nast;
                free(obecny);
            }
            else {
                // usuwamy pierwszy element
                *lista = obecny->nast;
                free(obecny);
            }

            return 1;
        }

        poprzedni = obecny;
        obecny = obecny->nast;
    }

    return 0;
}

int zapis_listy_wartow( el* lista , char* nazwa_pliku ) {
    /* Zapisuje listę z wartownikiem do pliku.
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

int wczytanie_listy_sort_wartow( el** lista , char* nazwa_pliku ) {
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
            dodaj_sort_wartow( lista , atoi(t) ); // dodawanie posortowane
        }

    }

    fclose(plik);
    return 1; // successful

}