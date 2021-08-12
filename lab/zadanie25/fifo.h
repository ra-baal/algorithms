//
// Kolejka FIFO
//

#ifndef GRAFY_FIFO_H
#define GRAFY_FIFO_H


typedef struct elKolejkiFIFO {
    int numer;
    struct elKolejkiFIFO *next;
} fifo;


void wloz(fifo** kolejka, int numer);
int wez(fifo** kolejka);
int zobacz(fifo* kolejka);
int wielkosc(fifo* kolejka);
void wyczysc(fifo** kolejka);
void wyswietlKolejke(fifo* kolejka);


#endif //GRAFY_FIFO_H
