// AlgoSD - laboratorium
// Rafał Balcerowski
// 289524

#include <stdio.h>

#include "2k.h"
#include "2k_sort.h"
#include "2k_sort_wartow.h"

void wyswietl_menu_lista_2k() {
    printf("LISTA DWUKIERUNKOWA\n");
    printf("1 - dodaj element na poczatku listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy od konca\n");
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_2k() {
    /// LISTA DWUKIERUNKOWA ///
    int poz = 0; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el2* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el2* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do {
        printf("Lista: ");
        wyswietl_lista_2k(lista);

        wyswietl_menu_lista_2k();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_p_2k( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_k_2k( &lista , x );
                printf("OK\n");
                break;
            case 3:
                usun_p_2k(&lista);
                printf("OK\n");
                break;
            case 4:
                usun_k_2k(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_2k(lista , x);
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

                            if ( dodaj_przed_2k( &lista, y , x ) )
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

                            if ( dodaj_za_2k( &lista, y , x ) )
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
                y = usun_wyszukaj_2k( &lista , x );
                if (y)
                    printf("OK\n");
                else
                    printf("Nie ma takiej wartosci\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_2k( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy_2k( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_lista_odwr_2k(lista);
                printf("\n");
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;
        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        usun_p_2k(&lista);

}

void wyswietl_menu_lista_2k_sort() {
    printf("LISTA DWUKIERUNKOWA POSORTOWANA\n");
    printf("1 - dodaj element do listy posortowanej\n"); //
    printf("2 - usun wyszukany\n"); //
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n"); //
//    printf("6 - dodaj nowy element listy przed lub za wskazanym\n"); // bez sensu na liście posortowanej
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("11 - pobierz pierwszy\n"); //
    printf("12 - pobierz ostatni\n"); //
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_2k_sort() {
    /// LISTA DWUKIERUNKOWA POSORTOWANA///
    int poz = 0; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el2* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el2* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do {
        printf("Lista: ");
        wyswietl_lista_2k(lista);

        wyswietl_menu_lista_2k_sort();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_2k_sort( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                y = usun_wyszukaj_2k_sort( &lista , x );
                if (y)
                    printf("OK\n");
                else
                    printf("Nie ma takiej wartosci\n");
                break;
            case 3:
                usun_p_2k(&lista);
                printf("OK\n");
                break;
            case 4:
                usun_k_2k(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_2k_sort(lista , x);
                if (p)
                    printf("Znaleziono pod adresem: %p\n" , p );
                else
                    printf("Brak wartosci\n");

                printf("OK\n");
                break;
            /*case 6:
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

                            if ( dodaj_przed_2k( &lista, y , x ) )
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

                            if ( dodaj_za_2k( &lista, y , x ) )
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
                break;*/
            case 7:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                y = usun_wyszukaj_2k_sort( &lista , x );
                if (y)
                    printf("OK\n");
                else
                    printf("Nie ma takiej wartosci\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_2k_sort( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy_2k( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_lista_odwr_2k(lista);
                printf("\n");
                break;
            case 11:
                if (lista)
                    printf("Pierwszy element to: %i\n", pobierz_pierwszy_2k_sort(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 12:
                if (lista)
                    printf("Ostatni element to: %i\n", pobierz_ostatni_2k_sort(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;
        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        usun_p_2k(&lista);

}

void wyswietl_menu_lista_2k_sort_wartow() {
    printf("LISTA DWUKIERUNKOWA POSORTOWANA Z WARTOWNIKIEM\n");
    printf("1 - dodaj element do listy posortowanej\n"); //
    printf("2 - usun wyszukany\n"); //
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n"); //
//    printf("6 - dodaj nowy element listy przed lub za wskazanym\n"); // bez sensu na liście posortowanej
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy od konca\n");
    printf("11 - pobierz pierwszy\n"); //
    printf("12 - pobierz ostatni\n"); //
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_2k_sort_wartow() {
    /// LISTA DWUKIERUNKOWA POSORTOWANA Z WARTOWNIKIEM ///
    int poz = 0; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el2* lista = konstruktor_wartow(); // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el2* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do {
        printf("Lista: ");
        wyswietl_lista_2k_wartow(lista);

        wyswietl_menu_lista_2k_sort_wartow();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_2k_sort_wartow( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                y = usun_wyszukaj_2k_sort_wartow( &lista , x );
                if (y)
                    printf("OK\n");
                else
                    printf("Nie ma takiej wartosci\n");
                break;
            case 3:
                usun_p_2k_wartow(&lista);
                printf("OK\n");
                break;
            case 4:
                usun_k_2k_wartow(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_2k_sort_wartow(lista , x);
                if (p)
                    printf("Znaleziono pod adresem: %p\n" , p );
                else
                    printf("Brak wartosci\n");

                printf("OK\n");
                break;
                /*case 6:
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

                                if ( dodaj_przed_2k( &lista, y , x ) )
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

                                if ( dodaj_za_2k( &lista, y , x ) )
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
                    break;*/
            case 7:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                y = usun_wyszukaj_2k_sort_wartow( &lista , x );
                if (y)
                    printf("OK\n");
                else
                    printf("Nie ma takiej wartosci\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_2k_sort_wartow( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy_2k_wartow( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_lista_odwr_2k_wartow(lista);
                printf("\n");
                break;
            case 11:
                if (lista)
                    printf("Pierwszy element to: %i\n", pobierz_pierwszy_2k_sort_wartow(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 12:
                if (lista)
                    printf("Ostatni element to: %i\n", pobierz_ostatni_2k_sort_wartow(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;
        }
    } while (poz);

   destruktor_wartow(&lista); // zniszczenie struktury przed zakończeniem

}


int main() {

    int poz = 0;

    printf("1 - Lista dwukierunkowa\n"); // zadanie 9 (1 dla dwukierunkowej)
    printf("2 - Lista dwukierunkowa posortowana\n"); // zadanie 9 (6b dla dwukierunkowej)
    printf("3 - Lista dwukierunkowa posortowana z wartownikiem\n"); // zadanie 9 (6a dla dwukierunkowej)
    printf("Wybierz typ listy: ");

    scanf("%i", &poz);

    switch (poz) {
        case 1:
            lista_2k();
            break;
        case 2:
            lista_2k_sort();
            break;
        case 3:
            lista_2k_sort_wartow();
            break;
    }

    printf("KONIEC\n");
    return 0;
}
