// AlgoSD - laboratorium
// Rafał Balcerowski
// 289524

#include <stdio.h>

#include "1k.h"
#include "1k_sort.h"

void wyswietl_menu_zadanie8() {
    printf("POROWNYWANIE DWOCH JEDNOKIERUNKOWYCH LIST POSORTOWANYCHI(zad8)\n");
    printf("1 - dodaj element na koniec listy A\n");
    printf("2 - dodaj element na koniec listy B\n");
    printf("3 - usun ostatni element listy A\n");
    printf("4 - usun ostatni element listy B\n");
    printf("5 - porownanie: A -> A\\B | B -> B\\A (zadanie 8)\n");
    printf("6 - wczytaj zawartosc listy A z pliku\n");
    printf("7 - wczytaj zawartosc listy B z pliku\n");
    printf("8 - zapisz zawartosc listy A do pliku\n");
    printf("9 - zapisz zawartosc listy B do pliku\n");
    printf("10 - wyswietl zawartosc obu list\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void zadanie8() {
    /// dwie listy posortowane jednokierunkowe - porownywanie
    /// A -> A\B
    /// B -> B\A

    int poz; // pozycja menu
    int x; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el* A = NULL; // lista początkowo pusta
    el* B = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu

    do{
        wyswietl_menu_zadanie8();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc do A: ");
                scanf("%i" , &x);
                dodaj_sort(&A , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc do B: ");
                scanf("%i" , &x);
                dodaj_sort( &B , x );
                printf("OK\n");
                break;
            case 3:
                kusun(&A);
                printf("OK\n");
                break;
            case 4:
                kusun(&B);
                printf("OK\n");
                break;
            case 5:
                porownaj_sort(&A, &B);
                printf("OK\n");
                break;
            case 6:
                printf("Wczytana lista zostanie dodana do A.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_sort( &A , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 7:
                printf("Wczytana lista zostanie dodana do obecnej do B.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_sort( &B , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 8:
                printf("Podaj nazwe pliku do zapisu listy A: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy( A , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu listy B: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy( B , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                printf("A ");
                wyswietl_lista(A);
                printf("B ");
                wyswietl_lista(B);
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (A) // zwolnienie listy przed zakończeniem programu
        pusun(&A);

    while (B) // zwolnienie listy przed zakończeniem programu
        pusun(&B);

}

int main() {

    zadanie8();


    printf("KONIEC\n");
    return 0;
}
