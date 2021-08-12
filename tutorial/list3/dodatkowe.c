/* AlgoSD ćwiczenia
 * lista 3
 * Rafał Balcerowski */


//#include <stdio.h>

// /////////////////////////// //
// Sortowanie przez kopcowanie //
// /////////////////////////// //

/*! @return Zwraca index rodzica i-tego elementu
 * w tablicowej reprezentacji kopca.*/
int rodzic(int i) {
    return (i-1)/2;
}

/*! @return Zwraca index lewgo dziecka i-tego elementu
 * w tablicowej reprezentacji kopca.*/
int lewy(int i) {
    return 2*i+1;
}

/*! @return Zwraca index prawego dziecka i-tego elementu
 * w tablicowej reprezentacji kopca.*/
int prawy(int i) {
    return 2*i+2;
}

/* Sortowanie tablicy przez kopcowanie. (min od max). */

void przywracanie_wlasnosci_kopca(int kopiec[], int i, int rozmiar) {
    int i_lewy = lewy(i);
    int i_prawy = prawy(i);
    int i_wiekszy;
    int tymcz;

    if (i_lewy < rozmiar && kopiec[i_lewy] > kopiec[i])
        i_wiekszy = i_lewy;
    else
        i_wiekszy = i;

    if (i_prawy < rozmiar && kopiec[i_prawy]>kopiec[i_wiekszy])
        i_wiekszy = i_prawy;

    if (i_wiekszy != i) {
        tymcz = kopiec[i];
        kopiec[i] = kopiec[i_wiekszy];
        kopiec[i_wiekszy] = tymcz;
        przywracanie_wlasnosci_kopca(kopiec, i_wiekszy, rozmiar);
    }

}

void utworz_kopiec(int kopiec[], int rozmiar)
{
    int i;
    for (i=(rozmiar-1)/2; i>=0; i--)
        przywracanie_wlasnosci_kopca(kopiec, i, rozmiar);
}

void sortowanie_przez_kopcowanie(int kopiec[], int rozmiar)
{
    int i;
    int tymcz;
    utworz_kopiec(kopiec,rozmiar);
    for (i = rozmiar-1; i>0 ; i--) {
        tymcz = kopiec[0];
        kopiec[0] = kopiec[i];
        kopiec[i] = tymcz;

        rozmiar--;
        przywracanie_wlasnosci_kopca(kopiec, 0, rozmiar);
    }
}

