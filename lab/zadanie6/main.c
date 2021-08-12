// AlgoSD - laboratorium
// Rafał Balcerowski
// 289524

#include <stdio.h>
#include <stdlib.h>

#include "lista_jednokierunkowa.h"

void wyswietl_menu_lista_1k_sort() {
    printf("LISTA JEDNOKIERUNKOWA POSORTOWANA\n");
    printf("1 - dodaj element do listy posortowanej\n"); /// 1k sort
    printf("2 - usun odszukany element\n"); /// 1k sort
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n"); /// 1k sort
//    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
//    printf("11 - usun wszystkie wskazane elementy\n");
//    printf("12 - odwroc liste\n");
    printf("13 - pobierz pierwszy element\n"); /// 1k sort
    printf("14 - pobierz ostatni element\n"); /// 1k sort
    printf("0 - zakoncz dzialanie programu\n");
}

void wyswietl_menu_lista_1k_sort_wartow() {
    printf("LISTA JEDNOKIERUNKOWA POSORTOWANA Z WARTOWNIKIEM\n");
    printf("1 - dodaj element do listy posortowanej\n"); /// 1k sort
    printf("2 - usun odszukany element\n"); /// 1k sort
//    printf("3 - usun pierwszy element listy\n");
//    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n"); /// 1k sort
//    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
//    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
//    printf("11 - usun wszystkie wskazane elementy\n");
//    printf("12 - odwroc liste\n");
    printf("13 - pobierz pierwszy element\n"); /// 1k sort
    printf("14 - pobierz ostatni element\n"); /// 1k sort
    printf("0 - zakoncz dzialanie programu\n");
}

void lista_1k_sort() {
    /// LISTA JEDNOKIERUNKOWA POSORTOWANA ///
    int poz; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do{
        wyswietl_menu_lista_1k_sort();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_sort(&lista, x);
                printf("OK\n");
                break;
            case 2:
                printf("Podaj wartosc do usuniecia: ");
                scanf("%i" , &x);
                if ( usun_wyszukaj(&lista, x) )
                    printf("OK\n");
                else
                    printf("Brak takiej wartosci\n");
                break;
            case 3:
                pusun(&lista);
                printf("OK\n");
                break;
            case 4:
                kusun(&lista);
                printf("OK\n");
                break;
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj(lista, x);
                if (p)
                    printf("Znaleziono pod adresem: %p\n" , p );
                else
                    printf("Brak wartosci\n");

                printf("OK\n");
                break;
           /* case 6:
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

                            if ( dodaj_przed( &lista, x , el_war(lista , y) ) == EXIT_SUCCESS )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC ZA %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Za wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_za( &lista, x , el_war(lista , y) ) == EXIT_SUCCESS )
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
                usun_dany( &lista , el_war(lista, x) );
                printf("OK\n");
                break;
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_sort( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_lista(lista);
                break;
            /*case 11:
                printf("\t0 - powrot\n");
                printf("\t1 - funkcja iteracyjna\n");
                printf("\t2 - funkcja rekurencyjna\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            printf("Usun iteracyjnie elementy o wartosci: ");
                            scanf("%i" , &x);

                            usun_wsz( &lista , x );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Usun rekurencyjnie elementy o wartosci: ");
                            scanf("%i" , &x);

                            usun_wsz_rek( &lista , x );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 11; // powrót do wartości nadrzędnego menu
                break;*/
            /*case 12:
                printf("\t0 - powrot\n");
                printf("\t1 - funkcja iteracyjna\n");
                printf("\t2 - funkcja rekurencyjna\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            odwroc_liste( &lista );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            lista = odwroc_liste_rek( lista );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 12; // powrót do wartości nadrzędnego menu
                break;*/
            case 13:
                if (lista)
                    printf("Pierwszy element to: %i\n", pobierz_pierwszy(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 14:
                if (lista)
                    printf("Pierwszy element to: %i\n", pobierz_ostatni(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 0:
                // zakończenie programu - pętla while zostanie przerwana
                break;
            case -1:
                // test
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        pusun(&lista);

}

void lista_1k_sort_wartow() {
    /// LISTA JEDNOKIERUNKOWA POSORTOWANA Z WARTOWNIKIEM ///
    int poz; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el* lista = konstruktor_wartow(); // utworzenie wartownika (lista pusta)
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do{
        wyswietl_menu_lista_1k_sort_wartow();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                dodaj_sort_wartow(&lista, x);
                printf("OK\n");
                break;
            case 2:
                printf("Podaj wartosc do usuniecia: ");
                scanf("%i" , &x);
                if ( usun_wyszukaj_wartow(&lista, x) )
                    printf("OK\n");
                else
                    printf("Brak takiej wartosci\n");
                break;
            /*case 3:
                pusun(&lista);
                printf("OK\n");
                break;
            case 4:
                kusun(&lista);
                printf("OK\n");
                break;*/
            case 5:
                printf("Szukaj wartosc: ");
                scanf("%i" , &x);
                p = wyszukaj_wartow(lista, x);
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

                            if ( dodaj_przed( &lista, x , el_war(lista , y) ) == EXIT_SUCCESS )
                                printf("OK\n");
                            else
                                printf("NIE MOZNA DODAC ZA %i\n", y);

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Za wartosc: ");
                            scanf("%i" , &y);
                            printf("Dodaj wartosc: ");
                            scanf("%i" , &x);

                            if ( dodaj_za( &lista, x , el_war(lista , y) ) == EXIT_SUCCESS )
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
            /*case 7:
                printf("Usun wartosc: ");
                scanf("%i" , &x);
                usun_dany( &lista , el_war(lista, x) );
                printf("OK\n");
                break;*/
            case 8:
                printf("Wczytana lista zostanie dodana do obecnej.\n");
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", &nazwa_pliku[0]);
                if( wczytanie_listy_sort_wartow( &lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", &nazwa_pliku[0]);
                if( zapis_listy_wartow( lista , &nazwa_pliku[0] ) )
                    printf("OK\n");
                else
                    printf("NIEPOWODZENIE\n");
                break;
            case 10:
                wyswietl_lista_wartow(lista);
                break;
            /*case 11:
                printf("\t0 - powrot\n");
                printf("\t1 - funkcja iteracyjna\n");
                printf("\t2 - funkcja rekurencyjna\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            printf("Usun iteracyjnie elementy o wartosci: ");
                            scanf("%i" , &x);

                            usun_wsz( &lista , x );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            printf("Usun rekurencyjnie elementy o wartosci: ");
                            scanf("%i" , &x);

                            usun_wsz_rek( &lista , x );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 11; // powrót do wartości nadrzędnego menu
                break;*/
            /*case 12:
                printf("\t0 - powrot\n");
                printf("\t1 - funkcja iteracyjna\n");
                printf("\t2 - funkcja rekurencyjna\n");

                do {
                    scanf("%i", &poz);
                    switch (poz) {
                        case 0:
                            printf("POWROT\n");
                            break;
                        case 1:
                            odwroc_liste( &lista );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        case 2:
                            lista = odwroc_liste_rek( lista );
                            printf("OK\n");

                            poz = 0; // aby wyjść z do-while
                            break;
                        default:
                            printf("Brak takiej opcji\n");
                            break;
                    }
                } while ( poz );

                poz = 12; // powrót do wartości nadrzędnego menu
                break;*/
            case 13:
                if (! jest_pusta_wartow(lista))
                    printf("Pierwszy element to: %i\n", pobierz_pierwszy_wartow(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 14:
                if (! jest_pusta_wartow(lista))
                    printf("Pierwszy element to: %i\n", pobierz_ostatni_wartow(lista));
                else
                    printf("Lista jest pusta!\n");
                break;
            case 0:
                // zakończenie programu - pętla while zostanie przerwana
                break;
            case -1:
                // test
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);

    destruktor_wartow(&lista); // zniszczenie struktury przed zakończeniem programu

}


int main() {

    int poz = 0;

    printf("1 - Lista jednokierunkowa posortowana (zadanie 6b)\n");
    printf("2 - Lista jednokierunkowa posortowana z wartownikiem (zadanie 6a)\n");
    printf("Wybierz typ listy: ");

    scanf("%i", &poz);

    switch (poz) {
        case 1:
            lista_1k_sort();
            break;
        case 2:
            lista_1k_sort_wartow();
            break;
    }

    printf("KONIEC\n");
    return 0;
}
