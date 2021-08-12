// Skorowidz - plik nagłówkowy

#ifndef SKOROWIDZ_SKOROWIDZ_H
#define SKOROWIDZ_SKOROWIDZ_H

#include "ListaStron.h"
#include "Ogolne.h"

/** Element listy reprezentującej skorowidz.
 * Zagadnienie - ListaStron. */
typedef struct RekordSkorowidza {
    char Zagadnienie[BUFOR_ZAGADNIENIE]; // bufor
    ListaStron Strony;

    struct RekordSkorowidza* nast;
} RekordSkorowidza;

/** Lista reprezentująca skorowidz . */
typedef RekordSkorowidza* Skorowidz;


void WczytajZagadnienia(Skorowidz* skorowidz, const char nazwaPliku[]);
void DodajZagadnienie(Skorowidz* skorowidz, const char zagadnienie[]);
void UzupelnijSkorowidz(Skorowidz skorowidz, const char nazwaPliku[]);
RekordSkorowidza* ZnajdzRekord(Skorowidz skorowidz, const char zagadnienie[]);
void WyswietlRekord( RekordSkorowidza rekord );
void WyswietlSkorowidz(Skorowidz skorowidz);
void WyswietlSkorowidzOdwrotnie(Skorowidz skorowidz);
void ZapiszSkorowidzDoPliku(Skorowidz skorowidz, const char nazwaPliku[]);
void WyczyscSkorowidz(Skorowidz* skorowidz);
void PrzetworzSkorowidz(Skorowidz* skorowidz);

#endif //SKOROWIDZ_SKOROWIDZ_H


