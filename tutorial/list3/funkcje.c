/* AlgoSD ćwiczenia
 * lista 3
 * Rafał Balcerowski
 *
 * Rozwiązania zadań. */

#include <stdio.h>
#include <stdlib.h>
#include "kolejka.h"
#include "funkcje.h"
#include "lista.h"

int licznik_porownan = 0; // licznik porównań
int zamiany_elementow = 0; // licznik zamian elementow

/* ************ Zadanie 1 ************ */

/*! @return Zwraca index najmniejszego elementu tablicy. */
int min_index(const int tab[], int rozmiar) {
    int min = tab[0];
    int min_i = 0;
    int i;
    for (i=1; i<rozmiar; ++i)
        if (tab[i]<min) {
            min_i = i;
            min = tab[i];
        }
    return min_i;
}

/*! Sortuje tablicę przez zamianę. */
void sort1(int tab[], int rozmiar) {
    int i;
    for (i=0; i<rozmiar; ++i) {
        int index = min_index(tab+i, rozmiar-i) + i;
        int min = tab[index];
        tab[index] = tab[i];
        tab[i] = min;
    }
}


/* ************ Zadanie 2 ************ */

/*! Sortuje tablice przez wstawianie. */
void sort2(int tab[], int rozmiar) {
    int i;

    for (i=1; i<rozmiar; ++i) {
        int p = tab[i]; // pobieranie wartości

        int j;
        for (j=i-1; j>=0 && tab[j]>p; --j)
            tab[j + 1] = tab[j]; // przesuwanie wartości w prawo

        tab[j + 1] = p; // wstawianie wartości
    }
}


/* ************ Zadanie 3 ************ */

/*! Sortuje tablicę przez wstawianie. Wykorzystuje przeszukiwanie połówkowe. */
void sort2b(int tab[], int rozmiar) {
    int i;
    for ( i=1; i<rozmiar; ++i ) {
        int p = tab[i]; // zapamiętujemy

        int lk = 0; // lewy koniec
        int pk = i-1; // prawy koniec
        while (lk <= pk) {
            int m = (lk+pk)/2; // obeceny indeks w przedziale
            if(p < tab[m])
                pk = m-1;
            else
                lk = m+1;
        }

        int j;
        for(j=i-1; j>=lk; --j)
            tab[j+1] = tab[j]; // przestawianie w prawo

        tab[lk] = p; //wstawiamy
    }
}


/* ************ Zadanie 4 ************ */

/*! Sortuje metodą bąbelkową. */
void sort3(int tab[], int rozmiar) {
    int i;
    int j;
    int tmp;

    for (i = 1; i<rozmiar; i++) {
        for (j=rozmiar-1; j>=i; j--) {

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;
            }
        }
    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}


/*! Sortuje metodą bąbelkową.
 * Wykorzystanie zapamiętanej w poprzednim przebiegu pozycji j ostatniej wykonanej zamiany. */
void sort3a(int tab[], int rozmiar) {
    int i;
    int j;
    int tmp;
    int poz_ost_zmiany = -1; // j

    for (i = 1; i<rozmiar; i++) {
        for (j=rozmiar-1; j>=i; j--) {

            if (j == poz_ost_zmiany) {
                printf("porownania: %i\n", licznik_porownan);
                printf("zamiany: %i\n", zamiany_elementow);
                return;
            }

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

                poz_ost_zmiany = j;
            }
        }
    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}


/*! Sortuje metodą bąbelkową.
 * Wykorzystujące zapamiętaną w poprzednim przebiegu pozycję pierwszej zamiany */
void sort3b(int tab[], int rozmiar) {
    int i;
    int j;
    int tmp;
    int poz_pierw_zamiany = -1; // j

    for (i = 1; i<rozmiar; i++) {
        for (j=rozmiar-1, poz_pierw_zamiany=-1  ; j>=i; j--) {

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {

                zamiany_elementow++;
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

                if (poz_pierw_zamiany == -1)
                    poz_pierw_zamiany = j;
            }
        }

        if (poz_pierw_zamiany == -1) {
            printf("porownania: %i\n", licznik_porownan);
            printf("zamiany: %i\n", zamiany_elementow);
            return; // nie nastąpiła żadna zamiana, zatem kończymy
        }
    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}

/*! Sortuje metodą bąbelkową.
 * Zmienia w kolejnych przebiegach kierunek przeglądania tablicy. */
void sort3c(int tab[], int rozmiar) {
    int i;
    int j;
    int tmp;

    for (i = 1; i<rozmiar; i++) {

        for (j=rozmiar-1 ; j>=i; j--) {

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;

                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

            }
        }

        for (j=i+1; j<rozmiar; j++) {

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

            }
        }

    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}

/*! Sortuje metodą bąbelkową.
 * Połączenie ulepszeń a, b i c. */
void sort3d(int tab[], int rozmiar) {
    int i;
    int j;
    int tmp;
    int poz_pierw_zamiany = -1; // j
    int poz_ost_zmiany = -1; // j

    for (i = 1; i<rozmiar; i++) {

        for (j=rozmiar-1, poz_pierw_zamiany=-1  ; j>=i; j--) {

            if (j == poz_ost_zmiany) {
                printf("porownania: %i\n", licznik_porownan);
                printf("zamiany: %i\n", zamiany_elementow);
                return;
            }

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;

                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

                if (poz_pierw_zamiany == -1)
                    poz_pierw_zamiany = j;

                poz_ost_zmiany = j;
            }

        }

        if (poz_pierw_zamiany == -1) {
            printf("porownania: %i\n", licznik_porownan);
            printf("zamiany: %i\n", zamiany_elementow);
            return; // nie nastąpiła żadna zamiana, zatem kończymy
        }
        for (j=i+1, poz_pierw_zamiany=-1;  j<rozmiar; j++) {

            licznik_porownan++;
            if (tab[j] < tab[j-1]) {
                zamiany_elementow++;
                tmp = tab[j];
                tab[j] = tab[j-1];
                tab[j-1] = tmp;

                if (poz_pierw_zamiany == -1)
                    poz_pierw_zamiany = j;
            }
        }

        if (poz_pierw_zamiany == -1) {
            printf("porownania: %i\n", licznik_porownan);
            printf("zamiany: %i\n", zamiany_elementow);
            return; // nie nastąpiła żadna zamiana, zatem kończymy
        }
    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}


/* ************ Zadanie 5 ************ */

void shella_sortowanie(int tab[], int rozmiar) {
    int i, j, k;
    int h;
    int tymczasowa;
    int ht[] = {1, 4, 13, 40};

    k=0;
    while (ht[k] < rozmiar/3 && k<4)
        k++;

    for ((k==0)?(k):(--k), h=ht[k]; k>=0; --k, h=ht[k]) {
//        printf("k=%i h=%i\n",k, h);
        for (i = h; i < rozmiar; i++) {
            tymczasowa = tab[i];
            for (j = i; j >= h && (tab[j - h]) > tymczasowa; j -= h) {
                tab[j] = tab[j - h];
            }

            tab[j] = tymczasowa;
        }
    }

    printf("porownania: %i\n", licznik_porownan);
    printf("zamiany: %i\n", zamiany_elementow);
}


/* ************ Zadanie 6 ************ */

void inicjalizacja(int d[], int p[], int rozm, int zrodlo) {
    int v;
    for (v=0; v<rozm; ++v) {
        d[v] = INT_MAX/2; // nieskończoność // INT_MAX jest wartością zastrzeżoną przez kolejkę
        p[v] = -1; // brak poprzednia
    }

    d[zrodlo] = 0;
}

void relaksacja(int** graf, int u, int v, int d[], int p[]) {
    if (d[v] > d[u] + graf[u][v]) { // graf[u][v] oznacza wagę krawędzi z u do v
        d[v] = d[u] + graf[u][v];
        p[v] = u;
    }
}

void dodaj_wierzcholki_do_kolejki_wg_d(kolejka_priorytetowa Q, int d[], int rozm) {
    int v;
    for (v=0; v<rozm; ++v)
        dodaj(Q, v, d[v]);
}

void dijkstra(int ** graf, int rozm, int zrodlo, int d[], int p[]) {
    int v;
    int u;

    inicjalizacja(d, p, rozm, zrodlo);

    kolejka_priorytetowa Q = nowa_kolejka();
    dodaj_wierzcholki_do_kolejki_wg_d(Q, d, rozm);
    while (!jest_pusta(Q)) {
        u = pobierz(Q); // bierze wierzchołek o najmniejszym d z kolejki

        for (v=0; v<rozm; ++v)
            if (graf[u][v] > 0) // jest krawędź z u do v
                relaksacja(graf, u, v, d, p);

    }

}

void wyswietlSciezka(int p[], int cel) {
    if (p[cel] != -1) {
        wyswietlSciezka(p, p[cel]);
        printf("%i ", cel);
    }
}


/* ************ Zadanie 7 ************ */

#define BRAK -1

/*! Funkcja wyznaczająca najkrótsze ścieżki między wszystkimi wierzchołkami grafu skierowanego.
 *
 * @param graf Tablica 2D jako macierz sąsiedztwa grafu.
 * @param d Odległości między wszystkimi parami wierzchołków [v][u].
 * Można również potraktować jako macierz sąsiedztwa domknięcia wejściowego grafu
 * zamieniając wartości INT_MAX na 0;
 * @param p Poprzedniki - ostatni wierzchołek, z którego dotarto do celu idąc z [v] do [u].
 * @param rozm Liczba wierzchołków.
 */
void floyd_warshall(long long int** graf, long long int** d, int** p, int rozm) {
    int v1, v2, u;
    for (v1=0; v1<rozm; ++v1) {
        for (v2=0; v2 < rozm; ++v2) { // dla wszystkich kombinacji par wierzchołków
            d[v1][v2] = INT_MAX; // ustawimy odległość między nimi na "nieskończoność"
            p[v1][v2] = BRAK; // a poprzednika na brak
        }
        d[v1][v1] = 0; // odl do samego siebie równa zero
    }

    for (v1=0; v1<rozm; ++v1) {
        for (v2=0; v2<rozm; ++v2) {
            if (graf[v1][v2] != 0) {
                // dla wszystkich krawędzi wychodzących z v1
                d[v1][v2] = graf[v1][v2]; // odl. to po prostu waga krawędzi
                p[v1][v2] = v1;
            }
        }
    }


    for (u=0; u<rozm; ++u) {
        for (v1=0; v1<rozm; ++v1) {
            for (v2 = 0; v2<rozm; ++v2) {
                if ( d[v1][v2] > d[v1][u] + d[u][v2] ) {
                    d[v1][v2] = d[v1][u] + d[u][v2];
                    p[v1][v2] = p[u][v2];
                }
            }
        }
    }

}

void wyswietlSciezka_floyd_warshall(int** p, int zrodlo, int cel) {
    if (p[zrodlo][cel] != BRAK) {
        wyswietlSciezka_floyd_warshall(p, zrodlo, p[zrodlo][cel]);
        printf("%i ", cel);
    }
}


/* ************ Zadanie 8 ************ */

void dfs_rek(int u, enum kolor kolory[], int * czas, lista graf[], int czasy_odwiedz[], int czasy_przetw[], int p[]) {
    kolory[u] = czerwony; // odwiedzony
    czasy_odwiedz[u] = ++(*czas);
    printf("czas: %2i | czerwony  wierzcholek %i | p[%i]=%2i\n", *czas, u, u, p[u]);

    ell* wsk_v = graf[u];
    while (wsk_v) {
        if (kolory[wsk_v->x] == bialy) {
            p[wsk_v->x] = u;
            dfs_rek(wsk_v->x, kolory, czas, graf, czasy_odwiedz, czasy_przetw, p);
        }
        wsk_v = wsk_v->nast;
    }

    kolory[u] = niebieski; // przetworzony
    czasy_przetw[u] = ++(*czas);
    printf("czas: %2i | niebieski wierzcholek %i | p[%i]=%2i\n", *czas, u, u, p[u]);
}

/*! depth-first search */
void dfs(lista graf[], int rozm) {
    int u;
    enum kolor kolory[rozm];
    int p[rozm];
    for (u=0; u<rozm; ++u) {
        kolory[u] = bialy; // nieodwiedzony
        p[u] = BRAK;
    }

    int czas = 0;
    int czasy_odwiedzenia[rozm];
    int czasy_przetworzenia[rozm];

    for (u=0; u<rozm; ++u)
        if (kolory[u] == bialy)
            dfs_rek(u, kolory, &czas, graf, czasy_odwiedzenia, czasy_przetworzenia, p);
}

