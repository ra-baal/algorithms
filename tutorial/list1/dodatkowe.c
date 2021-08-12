/* AlgoSD - ćwiczenia
 * Lista 1 - funkcje dodatkowe listy jednokierunkowej
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista1.h"

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



el* poprzedni(el* lista, el* element) {
    /* Zwraca adres poprzedniego elementu względem 'element' na liście 'lista',
     * a NULL gdy lista pusta lub brak poprzedniego elementu (dla poprzedniego względem pierwszego), (ewenntualnie dla złych danych) */

    //fprintf(STRERR, "poprzedni(lista: %p, element: %p)\n", lista, element);

    while (lista) {
        if (lista->nast == element) {
            //fprintf(STRERR, "poprzedni = %p\n", lista);
            return lista;
        }
        lista = lista->nast;
    }

    //fprintf(STRERR, "poprzedni = %p\n", NULL);
    return NULL;
}