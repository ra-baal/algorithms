// Lista stron - definicje funkcji

#include <stdlib.h>
#include <stdio.h>
#include "ListaStron.h"
#include "Ogolne.h"


/** Dodaje do listy na początku. */
void DodajStrone( ListaStron* lista, const int numer ){
    NumerStrony* nowaStrona = malloc(sizeof(NumerStrony));
    nowaStrona->Numer = numer;
    nowaStrona->nast = *lista;
    *lista = nowaStrona;
}

/** Usuwa wszystkie elementy. Zwalnia pamięć. */
void WyczyscListeStron ( ListaStron* lista ) {
    while ( *lista ) {
        NumerStrony* doZwolnienia = *lista;
        *lista = (*lista)->nast;
        free(doZwolnienia);
    }
}

/** Wyświetla numery stron w jednym wersie.
 * 3 lub więcej kolejnych stron wyświetla jako zakres. */
void WyswietlListeStronZakresy(ListaStron lista) {

    NumerStrony* kolejna = NULL;

    while (lista) {
        kolejna = KolejneStrony(lista, 3);
        if (lista != kolejna) {
            printf("%i-%i ", lista->Numer, kolejna->Numer);
            lista = kolejna->nast;
        }
        else {
            printf("%i ", lista->Numer);
            lista = lista->nast;
        }

    }
}

/*! Dla danej strony zwraca adres najdlaszej kolejnej strony większej o 1 bądź równej jeżeli jest ona oddalona co najmniej o 2 ( razem 3).
 *
 * @param strona Adres strony, dla której sprawdzać następne wartości.
 * @return Zwraca adres ostaniej strony kończącej ciąg kolejnych wartości.
 */
NumerStrony* KolejneStrony(NumerStrony* strona, int minimalnyZakres) {

    NumerStrony* s = strona;

    int wystapienia = 1;

    if (s)
        while (s->nast) {
            if (s->Numer == s->nast->Numer || s->Numer == (s->nast->Numer - 1)) {
                s = s->nast;
                ++wystapienia;
            } else
                break;
        }
    if (wystapienia < minimalnyZakres)
        return strona;
    else
        return s;
}

/** Wyświetla numery stron w jednym wersie. */
void WyswietlListeStron(ListaStron lista) {

    while (lista) {
        printf("%i ", lista->Numer);
        lista = lista->nast;
    }

}

/*! Odwraca listę w sposób rekurencyjny.
 * Zwraca wskaźnik na nowy pierwszy element.
 * (który należy ustawić jako wskaźnik na listę)
 * */
ListaStron OdwrocListeStron( ListaStron lista ) {

    NumerStrony* s; // zmienna pomocnicza - wartosc zwracana

    if ( ! lista )
        return NULL; // lista pusta

    if ( (lista)->nast ) {
        s = OdwrocListeStron( lista->nast );

        ((lista)->nast)->nast = lista; // następny następnego to teraz obeceny (odwracenie listy)
        (lista)->nast = NULL;

        return s;
    }

    return lista; // ostatni element
}

/*! Usuwa powtarzające się wartości z posortowanej listy.
 * Wersja rekurencyjna. */
void UsunPowtorzeniaStron(ListaStron* l) {

    if ( ! (*l) )
        return;

    if ( ((*l)->nast) && ((*l)->nast->Numer == (*l)->Numer) ) {
        NumerStrony* doZwolnienia = (*l)->nast;
        (*l)->nast = (*l)->nast->nast;
        free(doZwolnienia);
        UsunPowtorzeniaStron(l);
    }
    else
        UsunPowtorzeniaStron(&(*l)->nast);
}







