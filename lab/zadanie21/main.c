#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10000
#define M 1000

struct dane_wydajnosci {
    unsigned long int podstawienia;
    unsigned long int porownania;
    unsigned long int historia_podstawienia[M];
    unsigned long int historia_porownania[M];
} dw_babelkowe, dw_shella, dw_szybkie ;

//** deklaracje **//

void babelkowe_sortowanie(int tab[], int rozmiar);
void shella_sortowanie(int tab[], int rozmiar, int h);
void szybkie_sortowanie(int tab[], int rozmiar);

int* kopia_tablicy(int const tab[], int rozmiar);

unsigned long int minimum(const unsigned long int tab[], int rozmiar);
unsigned long int maksimum(const unsigned long int tab[], int rozmiar);
unsigned long int srednia(const unsigned long int tab[], int rozmiar);
void aktualizuj_dane_wydajnosci(struct dane_wydajnosci* dw, int m);
void wyswietl_tabele_danych();

//** definicje **//

void wyswietl_tabele_danych() {
    printf("%-13s%-30s%-30s\n", "", "LICZBA POROWNAN", "LICZBA PODSTAWIEN");
    printf("%-13s%-10s%-10s%-10s", "MET. SORT.", "minimum", "maksimum", "srednia");
    printf("%-10s%-10s%-10s\n", "minimum", "maksimum", "srednia");

    printf("%-10s%10lu%10lu%10lu",
           "BABELKOWE",
           minimum(dw_babelkowe.historia_porownania, M),
           maksimum(dw_babelkowe.historia_porownania, M),
           srednia(dw_babelkowe.historia_porownania, M));
    printf("%10lu%10lu%10lu\n",
           minimum(dw_babelkowe.historia_podstawienia, M),
           maksimum(dw_babelkowe.historia_podstawienia, M),
           srednia(dw_babelkowe.historia_podstawienia, M));

    printf("%-10s%10lu%10lu%10lu",
           "SHELLA",
           minimum(dw_shella.historia_porownania, M),
           maksimum(dw_shella.historia_porownania, M),
           srednia(dw_shella.historia_porownania, M));
    printf("%10lu%10lu%10lu\n",
           minimum(dw_shella.historia_podstawienia, M),
           maksimum(dw_shella.historia_podstawienia, M),
           srednia(dw_shella.historia_podstawienia, M));

    printf("%-10s%10lu%10lu%10lu",
           "SZYBKIE",
           minimum(dw_szybkie.historia_porownania, M),
           maksimum(dw_szybkie.historia_porownania, M),
           srednia(dw_szybkie.historia_porownania, M));
    printf("%10lu%10lu%10lu\n",
           minimum(dw_szybkie.historia_podstawienia, M),
           maksimum(dw_szybkie.historia_podstawienia, M),
           srednia(dw_szybkie.historia_podstawienia, M));

}

unsigned long int minimum(const unsigned long  int tab[], int rozmiar) {
    unsigned long int min = tab[0];
    int i;
    for (i=1; i<rozmiar; i++)
        if (tab[i] < min)
            min = tab[i];

    return min;
}


unsigned long int maksimum(const unsigned long int tab[], int rozmiar) {
    unsigned long int max = tab[0];
    int i;
    for (i=1; i<rozmiar; i++)
        if (tab[i] > max)
            max = tab[i];

    return max;
}

unsigned long int srednia(const unsigned long int tab[], int rozmiar) {
    unsigned long long int suma = 0;
    int i;
    for (i=0; i<rozmiar; i++)
        suma += tab[i];

    return suma / rozmiar;
}

void aktualizuj_dane_wydajnosci(struct dane_wydajnosci* dw, int m) {
    dw->historia_podstawienia[m] = dw->podstawienia;
    dw->podstawienia = 0;

    dw->historia_porownania[m] = dw->porownania;
    dw->porownania = 0;
}

int* kopia_tablicy(int const tab[], const int rozmiar) {
    int i;

    int* kopia = malloc(rozmiar*sizeof(int));
    for (i=0; i<rozmiar; i++)
        kopia[i] = tab[i];

    return kopia;
}

void babelkowe_sortowanie(int tab[], int rozmiar) {
    int i, j;
    int tymczasowa;
    for (i=0; i<rozmiar; i++) {
        for (j=0; j<rozmiar-1-i; j++) {
            if (((dw_babelkowe.porownania++)), tab[j]>tab[j+1]) {
                tymczasowa = tab[j];
                dw_babelkowe.podstawienia++;
                tab[j] = tab[j+1];
                dw_babelkowe.podstawienia++;
                tab[j+1] = tymczasowa;
                dw_babelkowe.podstawienia++;
            }
        }
    }
}

void shella_sortowanie(int tab[], int rozmiar, int h) {
    int i, j;
    int tymczasowa;
    for (i=h; i<rozmiar; i++) {
        tymczasowa = tab[i];
        dw_shella.podstawienia++;
        for (j=i;  j>=h && (((dw_shella.porownania++)), tab[j-h])>tymczasowa; j -= h) {
            tab[j] = tab[j-h];
            dw_shella.podstawienia++;
        }

        tab[j] = tymczasowa;
        dw_shella.podstawienia++;
    }

    if (h > 1)
        shella_sortowanie(tab, rozmiar, h/2);
}

void szybkie_sortowanie(int tab[], int rozmiar) {
    if (rozmiar < 2)
        return; //gotowe

    int i;
    int indeks_podzialu = 0; // pozycja ostatniej liczby <= niż klucz (czyli pozycja klucza po przestawieniu)
    int tymczasowa;
    int klucz = tab[0];

    for (i=1; i<rozmiar; i++) {
        if (((dw_szybkie.porownania++)), tab[i] <= klucz) {

            tymczasowa = tab[i]; // zapisujemy przesuwaną liczbę
            dw_szybkie.podstawienia++;

            if (indeks_podzialu == 0) {
                indeks_podzialu=i;
                while (((dw_szybkie.porownania++)), tab[indeks_podzialu-1] > klucz)
                    indeks_podzialu--; // ustalenie j na pozycje do przesunięcia wartości

            }
            else
                indeks_podzialu++;

            tab[i] = tab[indeks_podzialu];
            dw_szybkie.podstawienia++;
            tab[indeks_podzialu] = tymczasowa; // przesuwanie do częsci tablicy z liczbami <= kluczowi
            dw_szybkie.podstawienia++;

        }
    }

    tymczasowa = tab[0];
    dw_szybkie.podstawienia++;

    tab[0] = tab[indeks_podzialu];
    dw_szybkie.podstawienia++;

    tab[indeks_podzialu] = tymczasowa; // przestawienie klucza na "środek"
    dw_szybkie.podstawienia++;

    szybkie_sortowanie(tab, indeks_podzialu); // dla < niż klucz
    szybkie_sortowanie(tab+indeks_podzialu+1, rozmiar - indeks_podzialu-1); // dla > niż klucz
}

int main() {
    srand(time(NULL));
    int i, powt;
    int *tab_sh;
    int *tab_sz;


    int *tab_b = malloc(N*sizeof(int));


    for (powt=0; powt<M; powt++) {

        for (i = 0; i < N; i++)
            tab_b[i] = rand() % ((N / 2) + 3);

        tab_sh = kopia_tablicy(tab_b, N);
        tab_sz = kopia_tablicy(tab_b, N);


        babelkowe_sortowanie(tab_b, N);
        aktualizuj_dane_wydajnosci(&dw_babelkowe, powt);

        shella_sortowanie(tab_sh, N, 4);
        aktualizuj_dane_wydajnosci(&dw_shella, powt);

        szybkie_sortowanie(tab_sz, N);
        aktualizuj_dane_wydajnosci(&dw_szybkie, powt);

    }

    wyswietl_tabele_danych();


    return 0;
}
