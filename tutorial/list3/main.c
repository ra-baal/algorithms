/* AlgoSD ćwiczenia
 * lista 3
 * Rafał Balcerowski */

#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

void sortowanie() {

    int i;

//    int tab[] = {1,2,6,1,8,3,6,254,1,-2}; // tab1
    int tab[] = {7,9,7,8, 0, 6, 1, 9,9,7}; // tab2
//    int tab[] = {6, 1, 9,9,7}; // tab 3
//    int tab[] = {1,2,6,1,8,3,6,254,1,-2, 7,9,7,8, 0, 6, 1, 9,9,7, 6, 1, 9,9,7}; // tab 4

    int rozmiar = sizeof(tab) / sizeof(int);
    for (i=0; i<rozmiar; i++)
        printf("%i ", tab[i]);
    printf("\n");

//    sortowanie_przez_kopcowanie(tab, rozmiar);
//    sort3(tab, rozmiar);
//    sort3a(tab, rozmiar); // najlepszy
//    sort3b(tab, rozmiar);
//    sort3c(tab, rozmiar);
//      sort3d(tab, rozmiar); // prawdopodobnie dobry na dużych zbiorach

    shella_sortowanie(tab, rozmiar);

    for (i=0; i<rozmiar; i++)
        printf("%i ", tab[i]);
    printf("\n");

}

void graf_dijkstra() {
    int v, u;

    const rozm = 6; // 6 wierzchołków
    int ** graf = graf = malloc(rozm*sizeof(int*));
    for (v=0; v<rozm; v++)
        graf[v] = malloc(rozm*sizeof(int));

    for (v=0; v<rozm; v++)
        for (u=0; u<rozm; u++)
            graf[v][u] = 0; // brak połączenia na początku u wszystkich

    // krawędzie z [v] do [u] //
    graf[0][1] = 2;
    graf[1][2] = 3;
    graf[2][3] = 1;
    graf[3][4] = 5;
    graf[3][5] = 5;
    //
    graf[5][3] = 7;
    graf[4][5] = 4;
    graf[5][2] = 3;

    printf("D: Macierz grafu skierowanego o wierzcholkach: ");
    for (v=0; v<rozm; v++)
        printf("%i ", v);
    printf("\n");

    // wyświetlanie macierzy
    for (v=0; v<rozm; v++) {
        for (u = 0; u < rozm; u++) {
            printf("%i ", graf[v][u]);
        }
        printf("\n");
    }

    int zrodlo=5;
    int cel=3;
    int d[rozm]; // odległości ze źródła
    int p[rozm]; // poprzednik - ostatni wierzchołek, z którego dotarto do celu
    dijkstra(graf, rozm, zrodlo, d, p);

    for (v=0; v<rozm; ++v)
        printf("d[%i]=%-10i p[%i]=%-10i\n", v, d[v], v, p[v]); // -1 oznacza brak

    printf("Najkrotsza sciezka z %i do %i: ", zrodlo, cel);
    wyswietlSciezka(p, cel);
    printf("\n");

}

void graf_floyd_warshall() {
    int v, u;

    const rozm = 6; // 6 wierzchołków
    long long int ** graf = malloc(rozm*sizeof(long long int*));
    for (v=0; v<rozm; v++)
        graf[v] = malloc(rozm*sizeof(long long int));

    for (v=0; v<rozm; v++)
        for (u=0; u<rozm; u++)
            graf[v][u] = 0; // brak połączenia na początku u wszystkich

    // krawędzie z [v] do [u] //
    graf[0][1] = 2;
    graf[1][2] = 3;
    graf[2][3] = 1;
    graf[3][4] = 5;
    graf[3][5] = 5;
    //
    graf[5][3] = 7;
    graf[4][5] = 4;
    graf[5][2] = 3;

    printf("\nF-M: Macierz grafu skierowanego o wierzcholkach: ");
    for (v=0; v<rozm; v++)
        printf("%i ", v);
    printf("\n");

    // wyświetlanie macierzy
    for (v=0; v<rozm; v++) {
        for (u = 0; u < rozm; u++) {
            printf("%2lli ", graf[v][u]);
        }
        printf("\n");
    }

    int zrodlo=5;
    int cel=3;

    // odległości między wszystkimi parami wierzchołków [v][u] //
    long long int ** d = malloc(rozm*sizeof(long long int*));
    for (v=0; v<rozm; v++)
        d[v] = malloc(rozm*sizeof(long long int));

    // poprzedniki - ostatni wierzchołek, z którego dotarto do celu idąc z [v] do [u] //
    int ** p = malloc(rozm*sizeof(int*));
    for (v=0; v<rozm; v++)
        p[v] = malloc(rozm*sizeof(int));

    floyd_warshall(graf, d, p, rozm);

    printf("Wyswietlanie wszsytkich odleglosci:\n");
    for (v=0; v<rozm; ++v)
        for (u=0; u<rozm; ++u)
            printf("d[%i][%i]=%-10lli p[%i][%i]=%-10i\n", v, u, d[v][u], v, u, p[v][u]); // -1 oznacza brak

    printf("Najkrotsza sciezka z %i do %i: ", zrodlo, cel);
    wyswietlSciezka_floyd_warshall(p, zrodlo, cel);
    printf("\n");

    // wyświetlanie macierzy domknięcia grafu
    printf("Macierz domkniecia grafu:\n");
    for (v=0; v<rozm; v++) {
        for (u = 0; u < rozm; u++) {
            printf("%2lli ", (d[v][u]==INT_MAX) ? 0 : d[v][u] );
        }
        printf(" \n");
    }
}

void graf_dfs() {
    const int rozm = 5; // rozmiar grafu
    lista graf[rozm];
    int v;
    for (v=0; v<rozm; ++v)
        graf[v] = NULL;

    pdodaj(&graf[0], 1); // krawędź (0,1)
    pdodaj(&graf[1], 0); // krawędź (1,0)

    pdodaj(&graf[1], 4); // krawędź (1,4)
    pdodaj(&graf[4], 1); // krawędź (4,1)

    pdodaj(&graf[1], 2); // krawędź (1,2)
    pdodaj(&graf[2], 1); // krawędź (2,1)

    pdodaj(&graf[4], 1); // krawędź (4,1)
    pdodaj(&graf[1], 4); // krawędź (1,4)

    pdodaj(&graf[3], 1); // krawędź (3,1)
    pdodaj(&graf[1], 3); // krawędź (1,3)

    pdodaj(&graf[2], 3); // krawędź (2,3)
    pdodaj(&graf[3], 2); // krawędź (3,2)

    dfs(graf, rozm);

}

int main() {
    graf_dfs();
    return 0;
}








