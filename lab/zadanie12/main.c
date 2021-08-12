#include <stdio.h>
#include "1k_cykl.h"

void wyswietl_menu_zadanie12() {
    /// dwie listy cykliczne jednokierunkowe - usuwanie w A wartości z B
    printf("ZADANIE 12:\n");
    printf("1 - dodaj element na koniec listy A\n");
    printf("2 - dodaj element na koniec listy B\n");
    printf("3 - usun ostatni element listy A\n");
    printf("4 - usun ostatni element listy B\n");
    printf("5 - usun z listy A elementy wystepujace w liscie B\n");
    printf("6 - wczytaj zawartosc listy A z pliku\n");
    printf("7 - wczytaj zawartosc listy B z pliku\n");
    printf("8 - zapisz zawartosc listy A do pliku\n");
    printf("9 - zapisz zawartosc listy B do pliku\n");
    printf("10 - wyswietl zawartosc obu list\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void zadanie12() {
    /// dwie listy cykliczne jednokierunkowe - usuwanie w A wartości z B

    int poz; // pozycja menu
    int x; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el1k* A = NULL; // lista początkowo pusta
    el1k* B = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu

    do{
        wyswietl_menu_zadanie12();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc do A: ");
                scanf("%i" , &x);
                dodaj_k_1k_cykl( &A , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc B: ");
                scanf("%i" , &x);
                dodaj_k_1k_cykl( &B , x );
                printf("OK\n");
                break;
            case 3:
                usun_k_1k_cykl(&A);
                printf("OK\n");
                break;
            case 4:
                usun_k_1k_cykl(&B);
                printf("OK\n");
                break;
            case 5:
                usun_czesc_wspolna(&A, B);
                printf("OK\n");
                break;
            case 6:
                printf("Wczytana lista zostanie dodana do A.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytaj_1k_cykl( &A , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 7:
                printf("Wczytana lista zostanie dodana do obecnej do B.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytaj_1k_cykl( &B , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 8:
                printf("Podaj nazwe pliku do zapisu listy A: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapisz_1k_cykl( A , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu listy B: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapisz_1k_cykl( B , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                printf("A ");
                wyswietl_1k_cykl(A);
                printf("B ");
                wyswietl_1k_cykl(B);
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (A) // zwolnienie listy przed zakończeniem programu
        usun_p_1k_cykl(&A);

    while (B) // zwolnienie listy przed zakończeniem programu
        usun_p_1k_cykl(&B);

}


int main() {

    zadanie12();

    printf("KONIEC\n");
    return 0;
}
