#ifndef GRAFY_GRAF_H
#define GRAFY_GRAF_H

#include "fifo.h"


// liczba wierzchołków
#define ROZMIAR 6



// nieodwiedzony, odwiedzany, odwiedzony
typedef enum kolor {bialy, czerwony, niebieski} kolor;



int najkrotszaSciezkaBFS(int macierz[ROZMIAR][ROZMIAR], int wierzchStart, int wierzchCel, fifo** sciezka);




#endif //GRAFY_GRAF_H
