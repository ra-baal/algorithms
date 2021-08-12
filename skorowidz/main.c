/** projekt: Skorowidz
 * autor: Rafał Balcerowski
 * Dla zagadnień wczytanych z pliku tworzy skorowidz dla tekstu (inny plik) i zapisuje go do podanego pliku. */

#include <stdio.h>

#include "ListaStron.h"
#include "Skorowidz.h"

#define KSIAZKA "Iliada.txt"
#define ZAGADNIENIA "skorowidz-zagadnienia.txt"


int main() {

    Skorowidz skorowidz = NULL; // pusty skorowidz
    WczytajZagadnienia(&skorowidz, ZAGADNIENIA); // wczytanie listy słów, które mają znaleźć się w skorowidzu

    UzupelnijSkorowidz(skorowidz, KSIAZKA); // szukanie stron z wystąpieniami (tworzenie skorowidza)
    PrzetworzSkorowidz(&skorowidz); // odwrócenie list stron i usunięcie w nich powtórzeń
    WyswietlSkorowidzOdwrotnie(skorowidz); // wyświetlenie gotowego skorowidza

    WyczyscSkorowidz(&skorowidz); // zwolnienie pamięci
    return 0;
}

