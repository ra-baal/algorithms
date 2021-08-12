#include <stdio.h>
#include "funkcje.h"

int main() {
    int i;

    char* napisy[] = {
            "malina",
            "czekolada",
            "ananas",
            "cukierek",
            "zupa",
            "gruszka",
            "stek",
            "makaron",
            "deser"
    };

    int rozmiar = sizeof(napisy)/sizeof(char*);


    printf("PRZED SORTOWANIEM:\n");
    for (i=0; i<rozmiar; i++)
        printf("%s\n", napisy[i]);

    sortowanie_przez_kopcowanie(napisy, rozmiar);

    printf("\nPO SORTOWANIU:\n");
    for (i=0; i<rozmiar; i++)
        printf("%s\n", napisy[i]);

    return 0;
}
