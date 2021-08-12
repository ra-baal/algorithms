/* 3-drzewo
 * drzewo,które przechowuje punkty na odcinku [0,1) */

#ifndef INC_3_DRZEWO_3_DRZEWO_H
#define INC_3_DRZEWO_3_DRZEWO_H


typedef struct elementDrzewa {
    double l; // lewa granica przedziału (zamkniętego)
    double p; // prawa granica przedziału (otwartego)
    double wartosc;
    struct elementDrzewa* dzieci[3];
} elD; // węzeł drzewa

// 3_drzewo //
elD* nowyWezel(double l, double p, double wartosc);
void dodajDoDrzewa_rek(elD* rodzic, double wartosc);
void dodajDoDrzewa(elD** drzewo, double wartosc);
void wyswietlDrzewo(elD* wezel);
elD* szukaj(elD* wezel, double wartosc);


#endif //INC_3_DRZEWO_3_DRZEWO_H
