// AlgoSD ćwiczenia
// Rafał Balcerowski
// lista 2: drzewa
//
// deklaracje dodatkowych funkcji
//
// DRZEWO BINARNE

#ifndef LISTA2_DODATKOWE_H
#define LISTA2_DODATKOWE_H

#include "funkcje.h"

void wyswietl_elD(elD* element);
void wyswietl_RLP_rek(elD* drzewo);

void DrukujDrzewo0(elD* d, int glebokosc);

elD* nowy_element(int klucz, int licznik, elD* rodzic, elD* lewy, elD* prawy);

void zwolnij_rek(elD** T);

#endif //LISTA2_DODATKOWE_H
