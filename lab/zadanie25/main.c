#include <stdio.h>
#include "graf.h"

void zerujMacierz(int macierz[ROZMIAR][ROZMIAR]) {
    int i, j;
    for (i=0; i<ROZMIAR; i++)
        for (j=0; j<ROZMIAR; j++)
            macierz[i][j] = 0;

}

void wyswietlMacierz(int macierz[ROZMIAR][ROZMIAR]) {
    int i, j;
    for (i=0; i<ROZMIAR; i++) {

        for (j = 0; j < ROZMIAR; j++)
            printf("%i ", macierz[i][j]);

        printf("\n");
    }
}

void dodajKrawedz(int macierz[ROZMIAR][ROZMIAR], int wierzcholekA, int wierzcholekB) {
    macierz[wierzcholekA][wierzcholekB] = 1;
    macierz[wierzcholekB][wierzcholekA] = 1;
}

void macierzSasiedztwa() {
    int macierz[ROZMIAR][ROZMIAR]; // macierz sąsiedztwa grafu
    int wierzchStart, wierzchCel;
    fifo* sciezka = NULL;
    int i;

    printf("Graf o wierzcholkach: ");
    for (i=0; i<ROZMIAR; i++)
        printf("%i ", i);

    printf("\n");

    zerujMacierz(macierz);

    // ustalanie sąsiedztwa
    dodajKrawedz(macierz, 0, 1);
    dodajKrawedz(macierz, 0, 4);
    dodajKrawedz(macierz, 1, 4);
    dodajKrawedz(macierz, 1, 2);
    dodajKrawedz(macierz, 2, 3);
    dodajKrawedz(macierz, 3, 4);
    dodajKrawedz(macierz, 3, 5);
//    dodajKrawedz(macierz, 5, 2);

    printf("\n");
    wyswietlMacierz(macierz);

    sciezka = NULL;
    wierzchStart = 5;
    wierzchCel = 1;
    printf("\n");
    printf("Najkrotsza sciezka z wierzcholka %i do %i\n", wierzchStart, wierzchCel);
    printf("Dlugosc: %i\n", najkrotszaSciezkaBFS(macierz, wierzchStart, wierzchCel, &sciezka));
    printf("Przebieg: ");
    wyswietlKolejke(sciezka);
    printf("\n");

    wyczysc(&sciezka);
}

int main() {
    macierzSasiedztwa();
    return 0;
}
