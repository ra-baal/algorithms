/* AlgoSD ćwiczenia
 * lista 3
 * Rafał Balcerowski */

#ifndef LISTA3_FUNKCJE_H
#define LISTA3_FUNKCJE_H

#include "lista.h"

// zad 1
int min_index(const int tab[], int rozmiar);
void sort1(int tab[], int rozmiar);

// zad 2
void sort2(int tab[], int rozmiar);

// zad 3
void sort2b(int tab[], int rozmiar);

// zad 4
void sort3(int tab[], int rozmiar);
void sort3a(int tab[], int rozmiar);
void sort3b(int tab[], int rozmiar);
void sort3c(int tab[], int rozmiar);
void sort3d(int tab[], int rozmiar);

// zad 5
void shella_sortowanie(int tab[], int rozmiar);

// zad 6
void dijkstra(int **graf, int rozm, int zrodlo, int d[], int p[]);
void wyswietlSciezka(int p[], int cel);

// zad 7
void floyd_warshall(long long int** graf, long long int** d, int** p, int rozm);
void wyswietlSciezka_floyd_warshall(int** p, int zrodlo, int cel);

//zad 8
enum kolor {bialy, czerwony, niebieski}; // nieodwiedzony, odwiedzony, przetworzony
void dfs(lista graf[], int rozm);
void dfs_rek(int u, enum kolor kolory[], int * czas, lista graf[], int czasy_odwiedz[], int czasy_przetw[], int p[]);


// inne
void sortowanie_przez_kopcowanie(int kopiec[], int rozmiar);


#endif //LISTA3_FUNKCJE_H
