
#ifndef SORTOWANIE_KOPCOWANIE_LANCUCHY_ZNAKOWE_FUNKCJE_H
#define SORTOWANIE_KOPCOWANIE_LANCUCHY_ZNAKOWE_FUNKCJE_H

// funkcja główna
void sortowanie_przez_kopcowanie(char* kopiec[], int rozmiar);

// funkjce pomocnicze
void przywracanie_wlasnosci_kopca(char* kopiec[], int i, int rozmiar);
int lewy(int i);
int prawy(int i);

#endif //SORTOWANIE_KOPCOWANIE_LANCUCHY_ZNAKOWE_FUNKCJE_H
