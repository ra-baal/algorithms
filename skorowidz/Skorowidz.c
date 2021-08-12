// Skorowidz - definicje funkcji

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Skorowidz.h"

/** Wczytuje zagadnienia z pliku do listy.
 * Plik musi mieć w każdym wersie jedno zagadnienie. */
void WczytajZagadnienia(Skorowidz* skorowidz, const char nazwaPliku[]) {

    FILE* plik = fopen(nazwaPliku, "r");
    char bufor[BUFOR_ZAGADNIENIE] = {0}; // todo dobrze zrobione inicjalizacja zerami?

    if ( *skorowidz )
        ExitPrint(LISTA_NIEPUSTA, "Lista skorowidza nie jest pusta");
    if ( ! nazwaPliku)
        ExitPrint(ARGUMENT_PUSTY, "Pusta nazwa pliku");
    if ( ! plik )
        ExitPrint(PLIK_NIEOTWARTY, "Problem z plikiem");

    while ( fscanf(plik, "%s", &bufor[0]) != EOF ) {
//        printf("%s\n", &bufor[0]);
        DodajZagadnienie(skorowidz, &bufor[0]);

    }

    fclose(plik);
}

/** Dodaje nową pozycję/rekord do listy-skorowidza. */
void DodajZagadnienie(Skorowidz* skorowidz, const char zagadnienie[]) {

    if ( ! zagadnienie )
        ExitPrint(ARGUMENT_PUSTY, "Pusta nazwa rekordu skorowidza");

    RekordSkorowidza* nowyRekord = malloc(sizeof(RekordSkorowidza));
    strcpy( nowyRekord->Zagadnienie , zagadnienie );
    nowyRekord->Strony = NULL; // na razie bez stron
    nowyRekord->nast = *skorowidz;
    *skorowidz = nowyRekord;
}


/** Usuwa wszystkie elementy. Zwalnia pamięć. */
void WyczyscSkorowidz(Skorowidz* skorowidz) {

    while ( *skorowidz ) {
        RekordSkorowidza *doZwolnienia = *skorowidz;

        WyczyscListeStron(&(doZwolnienia->Strony));

        *skorowidz = (*skorowidz)->nast;
        free(doZwolnienia);
    }
}

/** Wyświetla dany rekord Skorowidza. */
void WyswietlRekord( RekordSkorowidza rekord ) {
    printf("%-12s" , rekord.Zagadnienie);
    WyswietlListeStronZakresy(rekord.Strony);
    printf("\n");
//    WyswietlListeStron(rekord.Strony);
//    printf("\n");
}

/** Wyświetla wszystkie rekordy skorowidza. */
void WyswietlSkorowidz(Skorowidz skorowidz) {
    while (skorowidz) {
        WyswietlRekord(*skorowidz);
        skorowidz = skorowidz->nast;
    }
}

/** Wyświetla wszystkie rekordy skorowidza.
 * Bierze elementy listy od końca.
 * Rekurencyjnie.*/
void WyswietlSkorowidzOdwrotnie(Skorowidz skorowidz) {
    if (!skorowidz)
        return;

    WyswietlSkorowidzOdwrotnie(skorowidz->nast);
    WyswietlRekord(*skorowidz);

}

/*! Uzupełnia skorowidz stronami dla posiadanych zagadnień.
 * Czyta plik i szuka wystąpień zagadnień do skorowidza.
 * Zapisuje odpowiednie strony w skorowidzu.
 *
 * @param skorowidz Skorowidz do uzupełnienia.
 * @param nazwaPliku Plik, dla którego należy stworzyć skorowidz.
 */
void UzupelnijSkorowidz(Skorowidz skorowidz, const char nazwaPliku[]) {

    int znak;
    int i; // Licznik znaku w słowie.
    int licznikZnakow = 0; // Licznik znaku na danej stronie.
    int numerStrony = 0; // Licznik numeru strony.
    RekordSkorowidza* rekord = NULL;
    char slowo[BUFOR_ZAGADNIENIE] = {0};
    FILE* plik = fopen(nazwaPliku, "r");

    if (!skorowidz)
        ExitPrint(LISTA_PUSTA, "Pusty skorowidz");
    if (!nazwaPliku)
        ExitPrint(ARGUMENT_PUSTY, "Pusta nazwa pliku");
    if (!plik)
        ExitPrint(PLIK_NIEOTWARTY, "Problem z plikiem");

    i = 0;
    licznikZnakow = 0;
    numerStrony = 1;
    while ( (znak = getc(plik)) != EOF ) {
        if( (++licznikZnakow) > STRONA_DLUGOSC ) {
            ++numerStrony;
            licznikZnakow = 1; // przeczytaliśmy właśnie 1. znak na kolejnej stronie
        }

        if ( (znak >= 65 && znak <= 90) || (znak >= 96 && znak <= 122) ) {
            slowo[i] = (char)znak;
            slowo[i + 1] = 0; // zakończenie zerem
            ++i;
        }
        else {
            if ( (rekord = ZnajdzRekord(skorowidz, slowo)) )
                DodajStrone(&(rekord->Strony), numerStrony);

            i = 0;
            slowo[0] = 0;
        }
    }

    fclose(plik);
}

/*! Wyszukiwanie wartości.
 * Zwraca adres rekordu o zadanej wartości pola Zagadnienie.
 *
 * @param skorowidz Lista reprezentująca skorowidz.
 * @param zagadnienie Nazwa pozycji w skorowidzu.
 * @return Wskaźnik na odnaleziony rekord lub NULL gdy nie znaleziono.
 */
RekordSkorowidza* ZnajdzRekord(Skorowidz skorowidz, const char zagadnienie[]) {
    while ( skorowidz ) {
        if ( ! strcmp(skorowidz->Zagadnienie , zagadnienie) ) // jeżeli są równe
            return skorowidz; // znaleziono
        skorowidz = skorowidz->nast;
    }

    return NULL; // == skorowidz // nie znaleziono
}
/*!
 * Usuwa powtorzenia oraz odwraca listy stron.
 *
 * @param skorowidz Lista ze skorowidzem.
 */
void PrzetworzSkorowidz(Skorowidz* skorowidz) {

    RekordSkorowidza* r = *skorowidz;

    while (r) {
        UsunPowtorzeniaStron( &(r)->Strony );
        r->Strony = OdwrocListeStron(r->Strony);
        r = r->nast;
    }

}















