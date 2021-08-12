/* AlgoSD - ćwiczenia
 * Lista 1 - zadanie 12
 * Rafał Balcerowski - 289524 */

#include <stdlib.h>
#include <stdio.h>
#include "lista1.h"

void dodaj_przed_cykliczna ( el** poczatek, const int x) {
/* Dodaje element przed element wskazany jako początek cyklu. */

    el* p;

    el* nowy = malloc(sizeof(el));
    nowy->x = x;

    if ( *poczatek ) {
    // lista posiada elementy
        nowy->nast = *poczatek;

        p = *poczatek;
        while (p->nast && p->nast != *poczatek) // war. p->nast zbędne
            p = p->nast;

        p->nast = nowy;
    }
    else {
    // lista jest pusta
        nowy->nast = nowy;
        *poczatek = nowy;
    }
}

void dodaj_za_cykliczna ( el** poczatek, const int x) {
/* Dodaje element przed element wskazany jako początek cyklu. */


    el* nowy = malloc(sizeof(el));
    nowy->x = x;

    if ( *poczatek ) {
        // lista posiada elementy
        nowy->nast = (*poczatek)->nast;
        (*poczatek)->nast = nowy;
    }
    else {
        // lista jest pusta
        nowy->nast = nowy;
        *poczatek = nowy;
    }
}

el* el_war_cykliczna ( el* poczatek , const int x ) {
/* Zwraca adres elementu o danej wartości x w jednokierunkowej liście cyklicznej */

    el* e = poczatek;

    while (e) {
        if (e->x == x)
            return e; // zwracamy adres elementu z wartością x
        else if ( e->nast == poczatek ) // gdy powrót na początek
            return NULL; // nie znaleziono szukanego x

        e = e->nast;
    }

    return NULL; // NULL == poczatek <=>  lista pusta

}

el* el_war_cykliczna_rek ( el* plista , el* elista, const int x ) {
/* Zwraca adres elementu o danej wartości x w jednokierunkowej liście cyklicznej.
 * NULL gdy nieznaleziono.
 * Wersja rekurencyjna.
 *
 * plista - wskaźnik na listę
 * elista - wskaźnik na listę (to samo!)
 * x - szukana wartość elementu */

    if ( ! plista ) // lista pusta
        return NULL; // nie ma szukanej wartości

    if (elista->x == x) // szukansa wartość
        return elista; // adrs elementu szukanej wartości

    if (elista->nast == plista) // przeszukano całą listę
        return NULL; //  nie ma szukanej wartości

    return el_war_cykliczna_rek(plista, elista->nast, x); // następny element

}

void usun_dany_cykliczna( el** lista, el* cel) {
/* Usuwa dany element (z podanego adresu) z listy cyklicznej */

    el* poprzedni;
    el* nastepny; // niekoniecznie potrzeba - bo to po prostu cel->nast - poprawić

    if ( (! cel) || (! *lista) ) // brak celu lub lista pusta
        return;  // nic do zrobienia

    if ( (cel)->nast != cel ) {
    // więcej niż 1 element w liście

        nastepny = (cel)->nast;

        poprzedni = (cel)->nast;
        while ( poprzedni->nast != cel )
            poprzedni = poprzedni->nast; // szukamy poprzedniego elementu względem celu do usunięcia

        if ( cel == *lista ) {
        // usuwany element jest początkiem cyklu
            *lista = nastepny; // zmiana początku listy
        }

        free(cel);

        poprzedni->nast = nastepny;
        //cel = nastepny; // zmiana początku listy

    }
    else {
    // tylko 1 element na liście
        free(cel);
        *lista = NULL; // lista jest teraz pusta
    }
}


void usun_dany_cykliczna_rek(const el** plista, el* elista, const int x) {
/* Usuwa element (o danej wartości) z listy cyklicznej.
 * Rekurencyjnie.
 *
 * plista - adres wskaźnika na listę
 * elista - wskaźnik na listę (potrzebne, aby umożliwić rekurencję)
 * x - szukana wartość elementu */

    el* pomoc;

    if ( ! *plista ) {
    // lista pusta
        fprintf(stderr, "usun_dany_cykliczna_rek(%p, %p, %i): Lista jest pusta.", plista, elista, x);
    }
    else if ( elista->nast->x == x ) {
    // znaleziono element
        if (elista->nast == elista) {
        // tylko 1 element
            free(elista); // elist == elist->nast
            *plista = NULL;
        }
        else {
        // więcej elementów
            pomoc = elista->nast;
            elista->nast = elista->nast->nast;
            free(pomoc);
        }
    }
    else if (elista->nast == *plista){
        fprintf(stderr, "usun_dany_cykliczna_rek(%p, %p, %i): Brak danej wartosci.", plista, *plista, x);

        // koniec // return
    }
    else {
        usun_dany_cykliczna_rek(plista, elista->nast, x);
    }
}