#include <stdio.h>

#include "3_drzewo.h"

int main() {
    elD* drzewo = NULL;
    dodajDoDrzewa(&drzewo, 0.2);
    dodajDoDrzewa(&drzewo, 0.1);
    dodajDoDrzewa(&drzewo, 0.5);
    dodajDoDrzewa(&drzewo, 0.9);
    dodajDoDrzewa(&drzewo, 0.95);
    dodajDoDrzewa(&drzewo, 0.93);


    wyswietlDrzewo(drzewo);
    printf("szukany: %x\n", szukaj(drzewo, 0.5));
    return 0;
}
