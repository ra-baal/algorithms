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
    else
    {
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

    return EXIT_SUCCESS; // unsuccessful
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


//int daj_wartosc(el* element) {
//    /* zwraca wartość elementu listy */
//    return element->x;
//}*/


int zapis_listy( el* lista , char* nazwa_pliku ) {
    /* Zapisuje listę do pliku.
     * Zwraca: 1 - powodzenie, 2 - niepowodzenie */

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
     * Zwraca: 1 - powodzenie, 2 - niepowodzenie */

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



/// funkcja do testów
void test(void) {
    el* lista = NULL; //* wskaźnik na (pustą) listę *//
    wyswietl_lista( lista );

    kdodaj( &lista , 1 );
    wyswietl_lista( lista );

    pdodaj( &lista , 2 );
    wyswietl_lista( lista );

    wyswietl_el( el_war( lista , 0 ) );
    wyswietl_el( el_war( lista , 2 ) );

    dodaj_przed( &lista , 3 , el_n( lista , 2 ) ); /* dodaj 3 przed elementem nr 2 */
    wyswietl_lista( lista );

    dodaj_przed( &lista , 10 , el_war( lista , 2 ) ); /* dodaj 10 przed 2 */
    wyswietl_lista( lista );

    dodaj_za( &lista , 77 , ostatni( lista ) ); /* dodaj 77 za ostatnim elementem */
    wyswietl_lista( lista );

    dodaj_za( &lista , 88 , el_war( lista , 3 ) ); /* dodaj 88 za 3 */
    wyswietl_lista( lista );

    zapis_listy( lista , "testowa1.txt" );

    pusun( &lista );
    wyswietl_lista( lista );

    kusun( &lista );
    wyswietl_lista( lista );

    usun_dany( &lista , el_war( lista , 88 ) ); /* usun 88 */
    wyswietl_lista( lista );

    zapis_listy( lista , "testowa2.txt" );

    while ( lista ) /* zwolnienie listy */
        pusun( &lista );

    wyswietl_lista( lista );
}


