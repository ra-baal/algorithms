#include <stdlib.h>
#include <stdio.h>
#include "fifo.h"

void wloz(fifo** kolejka, int numer) {
    fifo *nowy = malloc(sizeof(fifo)); // pamiec
    nowy->numer = numer; // zawartosc

    nowy->next = *kolejka;

    *kolejka = nowy;
}

/*! Usuwa z kolejki i zwraca wartość. */
int wez(fifo** kolejka) {
    int numer;

    if (!(*kolejka))
        return -1; // niepowodzenie

    fifo* przedostatni = NULL;
    fifo* ostatni = *kolejka;
    while (ostatni->next) {
        przedostatni = ostatni;
        ostatni = ostatni->next;
    }

    numer = ostatni->numer;
    free(ostatni);
    if (przedostatni)
        przedostatni->next = NULL;
    else
        *kolejka = NULL;

    return numer;
}

/*! Zwraca wartość. */
int zobacz(fifo* kolejka) {

    if (!kolejka)
        return -1; // niepowodzenie

    while (kolejka->next)
        kolejka = kolejka->next; // będzie wskazywać na ostatniego (albo jedynego)

    return kolejka->numer;
}

int wielkosc(fifo* kolejka) {
    int licznik = 0;
    while( kolejka )
    {
        ++licznik;
        kolejka = kolejka->next;
    }

    return licznik;
}

void wyczysc(fifo** kolejka) {
    while(wielkosc(*kolejka) > 0)
        wez(kolejka);
}

void wyswietlKolejke(fifo* kolejka) {
//    printf("FIFO: ");
    while (kolejka) {
        printf("%i ", kolejka->numer);
        kolejka = kolejka->next;
    }

    printf("\n");
}

