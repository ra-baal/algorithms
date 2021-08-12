
#include <string.h>
#include "funkcje.h"

int lewy(int i) {
    return 2*i+1;
}

int prawy(int i) {
    return 2*i+2;
}

void przywracanie_wlasnosci_kopca(char* kopiec[], int i, int rozmiar) {
    int i_lewy = lewy(i);
    int i_prawy = prawy(i);
    int i_wiekszy;
    char* tymcz;

    if (i_lewy < rozmiar && strcmp(kopiec[i_lewy], kopiec[i]) > 0)
        i_wiekszy = i_lewy;
    else
        i_wiekszy = i;

    if (i_prawy < rozmiar && strcmp(kopiec[i_prawy], kopiec[i_wiekszy]) > 0 )
        i_wiekszy = i_prawy;

    if (i_wiekszy != i) {
        tymcz = kopiec[i];
        kopiec[i] = kopiec[i_wiekszy];
        kopiec[i_wiekszy] = tymcz;
        przywracanie_wlasnosci_kopca(kopiec, i_wiekszy, rozmiar);
    }

}

void sortowanie_przez_kopcowanie(char* kopiec[], int rozmiar) {
    char* tymcz;

    int i;
    for (i=(rozmiar-1)/2; i>=0; i--) {
        przywracanie_wlasnosci_kopca(kopiec, i, rozmiar);
    }

    while (rozmiar>1) {
        tymcz = kopiec[0];
        kopiec[0] = kopiec[rozmiar-1];
        kopiec[rozmiar-1] = tymcz;

        rozmiar--;
        przywracanie_wlasnosci_kopca(kopiec, 0, rozmiar);
    }
}
