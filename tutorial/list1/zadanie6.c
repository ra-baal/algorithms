/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 6
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include <stdlib.h>
#include "lista1.h"

void sortuj_elementy(el** lista) {
/* Sortuje elementy na liście od najmniejszego do największego x.
 * Faktycznie zamienia miejsca obiektów na liście. */

    if ( ! *lista )
        return; // pusta

    el* obecny = *lista;
    el* min;
    el* nast;

    while (obecny->nast) {
        //fprintf(STRERR, "obecny: %p\n", obecny);

        min = adres_min(obecny); // najmniejszy od obecnego do końca

        nast = obecny->nast; // zapamiętujemy następny
        if ( min == nast ) // jeśli min jest nast
            nast = obecny; // to obecny się nie zmienia!!

        zamien_elementy(lista, obecny, min); // zamiana

        //wyswietl_lista(*lista);

        obecny = nast;
    }
}

void sortuj_elementy_eliminuj_powt(el** lista) {
    /* Sortuje elementy na liście od najmniejszego do największego x.
     * Usuwa elementy o powtórzonych wartościach.
     * Faktycznie zamienia miejsca obiektów na liście. */

    if ( ! *lista )
        return; // pusta

    el* obecny = *lista;
    el* min;
    el* poprzedni = NULL; // poprzednie minimum ??
    el* nast;

    while (obecny->nast) {
        //fprintf(STRERR, "obecny: %p\n", obecny);

        min = adres_min(obecny); // najmniejszy od obecnego do końca

        if ( poprzedni && poprzedni->x == min->x ) {
            usun_dany(lista , min); // usuwamy powtórzenie
            continue; // i nie zmieniając obecnego pętla idzie dalej
        }
        else if ( obecny->x == obecny->nast->x ) {
            usun_dany(lista , obecny->nast); // usuwamy powtórzenie
            continue; // i nie zmieniając obecnego pętla idzie dalej
        }

        nast = obecny->nast; // zapamiętujemy następny
        if ( min == nast ) // jeśli min jest nast
            nast = obecny; // to obecny się nie zmienia!!

        zamien_elementy(lista, obecny, min); // zamiana
        poprzedni = min;

        //wyswietl_lista(*lista);

        obecny = nast;
    }
}

void zamien_elementy( el** lista, el* e1 , el* e2 ) {
    /* Zamienia położenia dwóch elementów w liście */

//    fprintf(STRERR, "zamien_elementy(lista: %p, e1: %p, e2: %p)\n", *lista, e1, e2);

    if ( ! ( (*lista) && e1 && e2 ) )
        return; // lista pusta lub pusty/e element/y
    else if ( e1 == e2 )
        return; // nic do zrobienia

    el* poprzedni_el1 = poprzedni(*lista, e1);
    el* poprzedni_el2 = poprzedni(*lista, e2);
    // jeśli mamy tu jakiś NULL to znaczy, że zmieni się początek listy

    el* e1_nast = e1->nast; // zapamiętanie e1->nast
    el* e2_nast = e2->nast; // zapamiętanie e2->nast

    if (e1->nast == e2) {
    // są obok siebie - e1 wcześniej

        if( poprzedni_el1 ) {
        // e1 nie jest początkiem listy

            poprzedni_el1->nast = e2;
            e2->nast = e1;
            e1->nast = e2_nast;
        }
        else {
        // e1 jest początkiem listy

            *lista = e2; // to zmiana wskaźnika na początek listy
            e2->nast = e1;
            e1->nast = e2_nast;
        }
    }
    else if (e2->nast == e1) {
    // są obok siebie - e2 wcześniej

        if( poprzedni_el2 ) {
            // e2 nie jest początkiem listy

            poprzedni_el2->nast = e1;
            e1->nast = e2;
            e2->nast = e1_nast;
        }
        else {
            // e2 jest początkiem listy

            *lista = e1; // to zmiana wskaźnika na początek listy
            e1->nast = e2;
            e2->nast = e1_nast;
        }
    }
    else {
    // nie są obok siebie

        if( poprzedni_el1 ) {
        // e1 nie jest początkiem listy
            poprzedni_el1->nast = e2;

            if( poprzedni_el2 ) {
            // e2 nie jest początkiem listy
                poprzedni_el2->nast = e1;
            }
            else {
            // e2 jest początkiem listy
                *lista = e1; // zmiana
            }

            e1->nast = e2_nast;
            e2->nast = e1_nast;

        }
        else {
        // e1 jest początkiem listy

            *lista = e2; // zmiana

            poprzedni_el2->nast = e1;

            e1->nast = e2_nast;
            e2->nast = e1_nast;
        }

    }

    printf("KONIEC\n");
}

el* adres_min ( el* lista ) {
    /* Zwraca adres najmniejszego elementu (x) */

    if ( ! lista )
        return NULL; // pusto

    el* el_min = lista;
    while (lista->nast) {
        if ( (el_min->x) > (lista->nast->x) )
            el_min = lista->nast;
        lista = lista->nast;
    }

    return el_min;
}

void zamien_wartosci( el* e1 , el* e2 ) { //
    /* Zamienia wartości dwóch elementów */
    if( e1 && e2 ) {
        int x = e2->x;
        e2->x = e1->x;
        e1->x = x;
    }
    else {
        fprintf(stderr, "ERROR zamien_wartosci(%p, %p): brak wartosci\n", e1, e2);
    }
}

void sortuj_wartosci(el* lista) {
    /* Sortuje wartości na liście od najmniejszego do największego.
     * Zamienia jedynie wartości x obiektów
     * bez faktycznej zmiany kolejności obiektów na liśćie*/
    el* p;

    while (lista) {
        //fprintf(stderr, "lista: %p\n", lista);
        p = lista->nast;
        while (p) {
            //fprintf(stderr,"p: %p\n", p);
            if (lista->x > p->x)
                zamien_wartosci(lista, p);
            p = p->nast;
        }
        lista = lista->nast;
    }
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////

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

void dodaj_sort_bez_powt(wel* lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Pomija powtórzenia. */

    wel p = *lista;

    if(!p) {
        // gdy lista pusta
        wel nowy = malloc(sizeof(el));
        nowy->x = x;

        nowy->nast = NULL;
        *lista = nowy;
        return;
    }
    else {
        // gdy lista ma elementy
        if( x < p->x) {
            // gdy dodanie na początek
            wel nowy = malloc(sizeof(el));
            nowy->x = x;

            nowy->nast = *lista;
            *lista = nowy;
            return;
        }
        else {
            while (p->nast) {
                if ( x == p->x)
                    return;

                if (x < p->nast->x) {
                    // gdy dodanie w środku
                    wel nowy = malloc(sizeof(el));
                    nowy->x = x;

                    nowy->nast = p->nast;
                    p->nast = nowy;
                    return;
                }

                p = p->nast;
            }

            if ( x == p->x)
                return;

            // gdy dodanie na końcu
            // p wskazuje na ostatni element
            wel nowy = malloc(sizeof(el));
            nowy->x = x;

            p->nast = nowy;
            nowy->nast = NULL;
            return;

        }
    }
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

void dodaj_sort_wartow_bez_powt(wel* lista, const int x) {
/* Dodaje element do listy jednokierunkowej przed pierwszym elementem nie mniejszym.
 * Tzn. w posortowany sposób od min do max.
 * Pomija powtórzenia */

    wel p;
    wel nowy;

    if( ! (*lista) ) {
        // gdy lista niezainicjalizowana
        errprint("Lista niezainicjalizowana", 1, 3);
    }

    p = *lista;

    if( x < p->x) {
        // gdy dodanie na początek
        nowy = malloc(sizeof(el));
        nowy->x = x;

        nowy->nast = *lista;
        *lista = nowy;
        return;
    }
    else {
        // gdy dodanie gdzieś dalej
        while ( p != p->nast ) {
            if ( x == p->x)
                return;

            if ( x < p->nast->x ) {
                nowy = malloc(sizeof(el));
                nowy->x = x;

                nowy->nast = p->nast;
                p->nast = nowy;
                return;
            }
            p = p->nast;
        }
    }
}