//
// lista_jednokierunkowa.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lista_jednokierunkowa.h"

void wyswietl_el( el* e ) {
    if ( ! e )
        printf("obiekt nie istnieje\n");
    else
        printf("adres obiektu: %p | x: %i nast: %p\n" , e , e->x , e->nast);
}

void pdodaj ( el** lista , int x ) { //* dodaj na początku *//
    el* p = malloc(sizeof(el));
    p->x = x;
    p->nast = *lista;
    *lista = p;
}

el* ostatni( el* lista ) {
    if ( ! lista )
        return NULL; // lista pusta

    while ( lista->nast ) // tak długo jak istnieje następna
        lista = lista->nast;

    return lista;
}

el* el_n (el* lista , int n ) { //* zwraca adres n-tego elementu *//
    if ( ! lista )
        return NULL; //* lista jest pusta *//

    if ( n > 0 ) {
        int i;
        for ( i = 1 ; i < n ; ++i ) {
            if ( lista->nast )
                lista = lista->nast;
            else
                return NULL; //* nie istnieje el. o takim indeksie *//
        }

        return lista;
    }

    /////////////////////////////////////////////////
    ////* można dodać obsługę indeksów ujemnych *////
    /////////////////////////////////////////////////

    return NULL; // niepoprawny indeks
}

void kdodaj ( el** lista , int x ) {
    el* p = malloc(sizeof(el));
    p->x = x;
    p->nast = NULL;
    el* o = ostatni(*lista);
    if ( o )
        o->nast = p;
    else
        *lista = p;
}

el* el_war ( el* lista , int x ) { //* wyszukiwanie wartośći ; zwraca adres */
    while ( lista ) {
        if ( lista->x == x )
            return lista; //* znaleziono */
        lista = lista->nast;
    }

    return NULL;//lista; //* brak wartości */
}


void pusun ( el** lista ) { /* usun poczatkowy element */
    if ( ! (*lista) )
        return;

    el* p = (*lista)->nast;
    free(*lista);
    *lista = p;
}

void kusun ( el** lista ) { /* usuwa na końcu */
    if ( ! *lista)
        return;

    el* p = *lista;
    if ( ! (p->nast) ) {
        free( p ); //* *lista == p */
        *lista = NULL;
    }
    else {
        while ( (p->nast)->nast )
            p = p->nast;

        free( p->nast );
        p->nast = NULL;
    }
}

void usun_dany( el** lista , el* cel ) { /* usuwa element o danym adresie */
    if ( ! (*lista) )
        return;

    if ( ! cel ) // brak celu!
        return;

    if ( cel == *lista ) {
        *lista = (*lista)->nast;
        free(cel);
        return;
    }

    el* q = *lista;
    while ( q->nast != cel )
        q = q->nast;

    q->nast = cel->nast;
    free( cel );

}

int dodaj_przed( el** lista , int x , el* cel ) { // wstawia element przed el. cel

    if ( ! cel )
        return EXIT_FAILURE; // unsuccessful


    if ( (! *lista) || ( cel == *lista )  ) {
        pdodaj( &(*lista) , x ); /* po prostu na początek */
        return EXIT_SUCCESS;
    }

    el* q = *lista;
    while ( q->nast != cel )
        q = q->nast;

    //wstawiamy nowy element między 'q' a 'cel'
    q->nast = malloc(sizeof(el));
    (q->nast)->nast = cel;
    (q->nast)->x = x;

    return EXIT_SUCCESS;
}

int dodaj_za( el** lista , int x , el* cel ) { /* dodaj za el. 'cel' */

    if ( ! cel )
        return EXIT_FAILURE; // unsuccessful


    if ( ! *lista ) {
        pdodaj( &(*lista) , x );
        return EXIT_SUCCESS; // successful
    }

    el* q = cel->nast;
    // dodajemy nowy element między cel a q
    cel->nast = malloc(sizeof(el));
    (cel->nast)->nast = q;
    (cel->nast)->x = x;

    return EXIT_SUCCESS; // successful
}

void wyswietl_lista ( el* lista ) {
    if ( ! lista ) {
        printf("\nLISTA:\t(pusta)\n");
    }
    else {

        printf("\nLISTA:");
        while (lista) {
            printf("\t");
            wyswietl_el(lista);
            lista = lista->nast;
        }
        /* printf("\n"); */
    }
}


int zapis_listy( el* lista , char* nazwa_pliku ) {
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

int wczytanie_listy( el** lista , char* nazwa_pliku ) {
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
            kdodaj( lista , atoi(t) ); // lista == &(*lista) // dodawanie na końcu, aby otrzymać listę w kolejności zapisywanej
        }

    }


    fclose(plik);
    return 1; // successful

}


/// zadanie 2 ///
void usun_wsz( el** lista, int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy */

    if ( ! *lista )
        return; // lista jest pusta, nie ma czego usuwać

    el* p; // pomocniczy wsk na element

    /* Usuwanie z początku listy */
    while ( (*lista) && (*lista)->x == x ) { /* dopóki niepusta i element do usunięcia jest na początku */
        p = (*lista)->nast;
        free(*lista);
        *lista = p;
    }

    /* Usuwanie dalszych elementów */
    el* l = *lista; // pomocniczy wsk na listę (na początek listy)
    while ( l && l->nast ) {
        if ( (l->nast)->x == x ) {
            p = l->nast; // do zwolnienia

            l->nast = (l->nast)->nast;

            free(p); // zwolnienie
        }
        else {
            l = l->nast;
        }
    }
}

void usun_wsz_rek( el** e, const int x ) {
    /* Funkcja usuwająca wszystkie wystąpienia wartości z listy
     * Wersja rekurencyjna */

    el* p = NULL; // zmienna pomocnicza

    if ( *e ) {
        if ( (*e)->x == x ) {
            p = *e; // do zwolnienia
            *e = (*e)->nast;
            free (p);
            usun_wsz_rek( e , x );

        }
        else {
            usun_wsz_rek( &((*e)->nast) , x );

        }
    }
}

/// zadanie 5 ///
void odwroc_liste( el** lista ) {
    /* Odwraca listę w sposób iteracyjny */

    el* l = NULL; // wsk pomocniczy na poprzedni element - l od lewy

    // *lista wskazuje na obecny element - "środkowy"

    el* p; // wsk pomocniczy na następny element - p od prawy

    while ( *lista ) {
        p = (*lista)->nast; // zapamiętujemy prawy (następny)

        (*lista)->nast = l; // zmieniamy wskazanie następnego elementu względem obecnego na lewy (poprzedni) - zmiana kierunku listy

        l = (*lista); // teraz po lewo (poprzednim) będzie dla nas obecny element
        *lista = p; // za obecny element bierzemy ten po prawej (następny)
    }

    *lista = l; // ostatni lewy to teraz prawy

}

el* odwroc_liste_rek( el* lista ) {
    /* Odwraca listę w sposób rekurencyjny.
     * Zwraca wskaźnik na nowy pierwszy element.
     * (który należy ustawić jako wskaźnik na listę) */

    el* p; // zmienna pomocnicza - wartosc zwracana

//    printf("*lista == %p\n", *lista);
//    printf("(*lista)->nast == %p\n", (*lista)->nast);
//    printf("&(*lista)->nast  == %p\n", &(*lista)->nast );
//    printf("\n");

    if ( ! lista ) {
        return NULL; // lista pusta
    }

    if ( (lista)->nast ) {
        p = odwroc_liste_rek( lista->nast );

        ((lista)->nast)->nast = lista; // następny następnego to teraz obeceny (odwracenie listy)
        (lista)->nast = NULL;

        return p;
    }

    return lista; // ostatni element
}
