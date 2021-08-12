/*!
 * AlgoSD Laboratorium
 * Drzewo - katalogi.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "definicje.h"

/*! Dodaje katalog do listy (cyklicznej) */
void dolacz_do_listy ( kat** lista, kat* katalog) {
    kat* p = NULL;

    if ( *lista ) {
        // lista posiada elementy
        katalog->nast = *lista;

        p = *lista;
        while (p->nast != *lista)
            p = p->nast;

        p->nast = katalog;
    }
    else {
        // lista jest pusta
        katalog->nast = katalog;
        *lista = katalog;
    }
}

/*! Tworzy nowy katalog w podanym katalogu.
 * @param rodz - wsk na katalog nadrzędny
 * @param nazwa - nazwa katalogu */
kat* utworz_katalog(kat* rodzic, const char nazwa[]) {

    kat *nowy = NULL;
    if ( (nowy = malloc(sizeof(kat))) ) {
        strncpy(nowy->nazwa, nazwa, LANCUCH_MAX - 1);
        nowy->rodzic = rodzic;
        dolacz_do_listy(&(nowy->rodzic->lista), nowy);
        return nowy;
    }
    else
        return NULL; // == nowy
}

kat* utworz_system(const char nazwa_katalogu_glownego[]) {
    kat *nowy = NULL;
    if ( (nowy = malloc(sizeof(kat))) ) {
        strncpy(nowy->nazwa, nazwa_katalogu_glownego, LANCUCH_MAX - 1);
        nowy->rodzic = NULL;
        nowy->nast = nowy;
        nowy->lista = NULL;
        return nowy;
    }
    else
        return NULL; // == nowy
}

/*!
 *
 * @param katalog Element listy do odłączenia z listy.
 * @return Wskaźnik na listę po odłączeniu danego elementu.
 */
kat* odlacz_z_listy(kat* katalog) {
    kat* poprz = NULL;

    if (!katalog) { // ta sytuacja nie powinna zachodzić podczas działania progrmu!
        fprintf(stderr,"NULL jako argument. Nie można odłączyć z listy.");
        return NULL;
    }

    if (katalog->nast == katalog) {
        // tylko 1 element
        return NULL;
    }
    else {
        // więcej elementów
        poprz = katalog->nast;
        while (poprz->nast != katalog)
            poprz = katalog->nast; // poprzedni

        poprz->nast = katalog->nast; // ominięcie katalogu <=> odłączenie z listy
        return poprz; // początek listy będzie się zmieniał nie tylko podczas usuwanie pierwszwego elementu
    }

}

kat* szukaj_w_liscie(kat* lista, char nazwa[]) {
    if (!lista)
        return NULL;

    if (!nazwa)
        return NULL;

    kat* poczatek = lista;
    do {
        if (strncmp(lista->nazwa,nazwa, LANCUCH_MAX) == 0)
            return lista;
        lista = lista->nast;
    } while (lista != poczatek);

    return NULL;
}

void usun_katalog(kat* katalog) {

    if (katalog && katalog->rodzic) {

        katalog->rodzic->lista = odlacz_z_listy(katalog);

        while (katalog->lista)
            usun_katalog(katalog->lista); // usuwanie wszystkich podkatalogów

        free(katalog);
    }
}

kat* usun_system(kat* root) {
    if(!root)
        return NULL;

        while (root->lista)
            usun_katalog(root->lista); // usuwanie wszystkich podkatalogów

        free(root);

    return NULL;
}
