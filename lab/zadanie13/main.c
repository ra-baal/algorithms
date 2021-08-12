// AlgoSD Lab
// Rafał Balcerowski
// zadanie 13

#include <stdio.h>
#include <limits.h>
#include "kolejka_priorytetowa.h"


void wyswietl_menu_koleja_priorytetowa() {
    printf("KOLEJKA PRIORYTETOWA\n");
    printf("1 - dodaj nowy element\n");
    printf("2 - pobierz element o najwiekszym priorytecie\n");
    printf("3 - zmien priorytet wybranego elementu\n");
    printf("4 - sprawdz czy kolejka jest pusta\n");
    printf("10 - wyswietl kolejke\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void kolejka_priorytetowa() {
    int poz; // pozycja menu
    int x,y; // zmienne pomocnicze do dodawania i wyszukiwania
    el* kolejka = nowa_kolejka(); // utworzenie wartownikow (kolejka pusta)

    do{
        wyswietl_menu_koleja_priorytetowa();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc (klucz): ");
                scanf("%i" , &x);
                printf("O priorytecie: ");
                scanf("%i" , &y);
                dodaj(kolejka, x, y);
                printf("OK\n");
                break;
            case 2:
                x = pobierz(kolejka);
                if (x == INT_MIN)
                    printf("Brak elementow! Najpierw cos dodaj!\n");
                else
                    printf("Pobrano i usunieto element o kluczu %i\n", x);
                break;
            case 3:
                printf("Podaj klucz x: ");
                scanf("%i" , &x);
                printf("Podaj nowy priorytet: ");
                scanf("%i" , &y);
                if (zmien_priorytet(kolejka,x,y))
                    printf("Zmieniono priorytet.\n");
                else
                    printf("Niepoprawnie!\n");

                break;
            case 4:
                if( jest_pusta(kolejka) )
                    printf("TAK. Kolejka jest pusta.\n");
                else
                    printf("NIE. Kolejka posiada elementy.\n");
                break;
            case 10:
                wyswietl_kolejke(kolejka);
            case 0:
                // zakończenie programu - pętla while zostanie przerwana
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);

    zniszcz_kolejke(&kolejka); // zniszczenie struktury przed zakończeniem programu

}


int main() {
    kolejka_priorytetowa();
    return 0;
}
