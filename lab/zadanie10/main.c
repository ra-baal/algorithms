#include <stdio.h>
#include "1k_cykl.h"
#include "2k_cykl.h"

void wyswietl_menu_1k_cykl() {
    /// lista cykliczna jednokierunkowa
    printf("\nLISTA JEDNOKIERUNKOWA CYKLICZNA\n");
    printf("1 - dodaj element na poczatku listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("11 - wyswietl zawartosc listy odwrotnie\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_1k_cykl() {
    /// lista cykliczna jednokierunkowa

    int poz; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el1k* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el1k* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)


    do{
        wyswietl_menu_1k_cykl();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_p_1k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_k_1k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 3:
                usun_p_1k_cykl(&lista);
                printf("OK\n");
                break;
            case 4:
                usun_k_1k_cykl(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_1k_cykl(lista , x);
                if (p)
                    printf("Znaleziono pod adresem: %p\n" , p );
                else
                    printf("Brak wartosci\n");

                printf("OK\n");
                break;
            case 6:
                printf("\t0 - powrot\n");
                printf("\t1 - dodaj przed\n");
                printf("\t2 - dodaj za\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            printf("Przed wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_przed_1k_cykl( &lista, y , x ) )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC PRZED %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Za wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_za_1k_cykl( &lista, y , x ) )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC ZA %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 6; // powrót do wartości
                break;
            case 7:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                usun_wyszukaj_1k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytaj_1k_cykl( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapisz_1k_cykl( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_1k_cykl(lista);
                break;
            case 11:
                wyswietl_odwr_1k_cykl(lista, NULL);
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        usun_p_1k_cykl(&lista);

}



void wyswietl_menu_2k_cykl() {
    /// lista cykliczna dwukierunkowa
    printf("\nLISTA DWUKIERUNKOWA CYKLICZNA\n");
    printf("1 - dodaj element na poczatku listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("11 - wyswietl zawartosc listy odwrotnie\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_2k_cykl() {
    /// lista cykliczna dwukierunkowa

    int poz; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el2k* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el2k* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)


    do{
        wyswietl_menu_2k_cykl();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_p_2k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_k_2k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 3:
                usun_p_2k_cykl(&lista);
                printf("OK\n");
                break;
            case 4:
                usun_k_2k_cykl(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_2k_cykl(lista , x);
                if (p)
                    printf("Znaleziono pod adresem: %p\n" , p );
                else
                    printf("Brak wartosci\n");

                printf("OK\n");
                break;
            case 6:
                printf("\t0 - powrot\n");
                printf("\t1 - dodaj przed\n");
                printf("\t2 - dodaj za\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            printf("Przed wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_przed_2k_cykl( &lista, y , x ) )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC PRZED %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Za wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_za_2k_cykl( &lista, y , x ) )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC ZA %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 6; // powrót do wartości
                break;
            case 7:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                usun_wyszukaj_2k_cykl( &lista , x );
                printf("OK\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytaj_2k_cykl( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapisz_2k_cykl( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_2k_cykl(lista);
                break;
            case 11:
                wyswietl_odwr_2k_cykl(lista);
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        usun_p_2k_cykl(&lista);

}



int main() {

    int poz = 0;

    printf("1 - Lista jednokierunkowa cykliczna\n");
    printf("2 - Lista dwukierunkowa cykliczna\n");
    printf("Wybierz typ listy: ");

    scanf("%i", &poz);

    switch (poz) {
        case 1:
            lista_1k_cykl();
            break;
        case 2:
            lista_2k_cykl();
            break;
    }

    printf("KONIEC\n");
    return 0;
}
