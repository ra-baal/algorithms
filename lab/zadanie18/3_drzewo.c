
#include <stdlib.h>
#include <stdio.h>
#include "3_drzewo.h"

elD* nowyWezel(double l, double p, double wartosc) {
    elD* nowy = malloc(sizeof(elD));
    nowy->l = l;
    nowy->p = p;
    nowy->wartosc = wartosc;
    nowy->dzieci[0] = NULL;
    nowy->dzieci[1] = NULL;
    nowy->dzieci[2] = NULL;
    return nowy;
}

/*! Dodaje element do drzewa dla poziomów > 0 */
void dodajDoDrzewa_rek(elD* rodzic, double wartosc) {
    double wlkPrzedzDzieci = (rodzic->p - rodzic->l) / 3;

    double lewGrDz[3];
    lewGrDz[0] = rodzic->l + 0 * wlkPrzedzDzieci;
    lewGrDz[1] = rodzic->l + 1 * wlkPrzedzDzieci;
    lewGrDz[2] = rodzic->l + 2 * wlkPrzedzDzieci;

    if (wartosc < lewGrDz[1]) {
        // wchodzimy do dziecka 0
        if (rodzic->dzieci[0])
            dodajDoDrzewa_rek(rodzic->dzieci[0], wartosc);
        else
            rodzic->dzieci[0] = nowyWezel(lewGrDz[0], lewGrDz[0] + wlkPrzedzDzieci, wartosc);

    }
    else if (wartosc < lewGrDz[2]) {
        // wchodzimy do dziecka 1
        if (rodzic->dzieci[1])
            dodajDoDrzewa_rek(rodzic->dzieci[1], wartosc);
        else
            rodzic->dzieci[1] = nowyWezel(lewGrDz[1], lewGrDz[1] + wlkPrzedzDzieci, wartosc);

    }
    else {
        // wchodzimy do dziecka 2
        if (rodzic->dzieci[2])
            dodajDoDrzewa_rek(rodzic->dzieci[2], wartosc);
        else
            rodzic->dzieci[2] = nowyWezel(lewGrDz[2], lewGrDz[2] + wlkPrzedzDzieci, wartosc);
    }

}

/*! Interfejs */
void dodajDoDrzewa(elD** drzewo, double wartosc) {
    if (wartosc < 0 || wartosc >= 1) {
        fprintf(stderr, "Niepoprawna wartosc.");
        return;
    }

    if (!(*drzewo))
        *drzewo = nowyWezel(0,1,wartosc);
    else
        dodajDoDrzewa_rek(*drzewo, wartosc);
}

/*! Wyświetlanie. Rekurencyjnie. */
void wyswietlDrzewo(elD* wezel) {
    if (!wezel)
        return;

    printf("%x\n", wezel);
    printf("war: %f\n", wezel->wartosc);
    printf("[%f,%f)\n", wezel->l, wezel->p);
    printf("%x %x %x\n", wezel->dzieci[0], wezel->dzieci[1], wezel->dzieci[2]); // adresy dzieci
    printf("\n");
    wyswietlDrzewo(wezel->dzieci[0]);
    wyswietlDrzewo(wezel->dzieci[1]);
    wyswietlDrzewo(wezel->dzieci[2]);

}

elD* szukaj(elD* wezel, double wartosc) {
    if (!wezel)
        return NULL;

    if (wezel->wartosc == wartosc)
        return wezel;

    double wlkPrzedzDzieci = (wezel->p - wezel->l) / 3;

    double lewGrDz[3];
    lewGrDz[0] = wezel->l + 0 * wlkPrzedzDzieci;
    lewGrDz[1] = wezel->l + 1 * wlkPrzedzDzieci;
    lewGrDz[2] = wezel->l + 2 * wlkPrzedzDzieci;

    if (wartosc < lewGrDz[1]) {
        // wchodzimy do dziecka 0
        return szukaj(wezel->dzieci[0], wartosc);
    }
    else if (wartosc < lewGrDz[2]) {
        // wchodzimy do dziecka 1
        return szukaj(wezel->dzieci[1], wartosc);
    }
    else {
        // wchodzimy do dziecka 2
        return szukaj(wezel->dzieci[2], wartosc);
    }
}

