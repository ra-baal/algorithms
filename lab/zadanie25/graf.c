#include <stdlib.h>
#include "graf.h"


void kopiujSasiadow(int S[ROZMIAR], const int sasiedzi[ROZMIAR]) {
    int i;
    for (i=0; i<ROZMIAR; ++i)
        S[i] = sasiedzi[i];
}

int najkrotszaSciezkaBFS(int macierz[ROZMIAR][ROZMIAR], int wierzchStart, int wierzchCel, fifo** sciezka) {
    int u, v; // iteratory wskazujące na numer wierzchołka
    int S[ROZMIAR]; // lista sąsiadów wierzchołka u
    fifo* Q = NULL; // pusta kolejka fifo
    kolor kolory[ROZMIAR]; // kolory kolejnych wierzchołków


    int d[ROZMIAR]; // odległość z wierzchołka startowego do u-tego
    int p[ROZMIAR]; // poprzednik u-tego wierzchołka w drzewie przeszukiwania wszerz
    for (u=0; u<ROZMIAR; ++u) {
        if (u==wierzchStart) // zbędne ??
            continue;
        kolory[u] = bialy; // nieodwiedzony
        d[u] = INT_MAX; // "nieskończoność"
        p[u] = -1; // brak poprzednika
    }

    kolory[wierzchStart] = czerwony; // startowy jest pierwszym odwiedzanym
    d[wierzchStart] = 0; // dystans do samego siebie jest równy 0
    p[wierzchStart] = -1; // brak poprzednika na początku

    wloz(&Q, wierzchStart); // wkładamy do kolejki wierzchołek startowy

    while (wielkosc(Q)) {
        // dopóki Q ma elementy

        u = zobacz(Q); // pobiera wartość, ale nie usuwa z kolejki
        kopiujSasiadow(S, macierz[u]); // wierzchołek v-ty jest sąsiadem u-tego wtw S[v]==1

        for(v=0; v<ROZMIAR; v++) { // dla wszystkich sąsiadów (S)
            if ( S[v] == 1 ) {
                // sąsiadami są tylko te v, dla których S[v] == 1

                if (kolory[v] == bialy) { // jeśli nieodwiedzony

                    kolory[v] = czerwony; // odwiedzany
                    d[v] = d[u] + 1; // długość do v-tego jest o 1 dłuższa niżdo u-tego

                    p[v] = u; // poprzednikiem v-tego jest u-ty
                    wloz(&Q, v);
                }
            }
        }
        wez(&Q); // usun u-ty wierzchołek z kolejki Q
        kolory[u] = niebieski; // odwiedzony
    }


    // zapamiętywanie ścieżki do wierzchCel
    for (u = wierzchCel; u != -1 ; u = p[u] )
        wloz(sciezka, u);

    wyczysc(&Q);
    return d[wierzchCel];
}





