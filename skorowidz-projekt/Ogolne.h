/** Stałe i deklaracje funkcji pomocniczych. */

#ifndef SKOROWIDZ_OGOLNE_H
#define SKOROWIDZ_OGOLNE_H

//** Kody błedów **//

#define LISTA_PUSTA 10
#define LISTA_NIEPUSTA 11

#define PLIK_NIEOTWARTY 20

#define ARGUMENT_PUSTY 30

//** INNE **//

#define BUFOR_ZAGADNIENIE 20

#define STRONA_DLUGOSC 1800 // Długość strony w znakach.


//** funkcje **//

void ExitPrint(int kod, const char komunikat[]);

#endif //SKOROWIDZ_OGOLNE_H
