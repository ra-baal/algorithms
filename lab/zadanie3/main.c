// AlgoSD - laboratorium
// Rafał Balcerowski
// 289524

#include <stdio.h>
#include <stdlib.h>

#include "1k.h"

void wyswietl_menu_lista_1k() {
    printf("\n1 - dodaj element na poczatku listy\n");
    printf("2 - dodaj element na koncu listy\n");
    printf("3 - usun pierwszy element listy\n");
    printf("4 - usun ostatni element listy\n");
    printf("5 - odszukaj zadany element\n");
    printf("6 - dodaj nowy element listy przed lub za wskazanym\n");
    printf("7 - usun wskazany element\n");
    printf("8 - wczytaj zawartosc listy z pliku\n");
    printf("9 - zapisz zawartosc listy do pliku\n");
    printf("10 - wyswietl zawartosc listy\n");
    printf("11 - usun wszystkie wskazane elementy\n");
    printf("12 - odwroc liste\n");
    printf("13 - policz wystapienia\n");
    printf("14 - najczesciej wystepujaca wartosc (zadanie 3)\n");
    printf("0 - zakoncz dzialanie programu\n");

}

void lista_1k() {
    /// lista jednokierunkowa
    int poz; // pozycja menu
    int x, y; // zmienne pomocnicze do dodawania i wyszukiwania na liscie
    el* lista = NULL; // lista początkowo pusta
    char nazwa_pliku[50]; // wskaźnk na napis z nazwą pliku do odczytu/zapisu
    el* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    //for ( scanf("%i" , &poz) ; poz != 0 ; scanf("%i" , &poz) )

    do{
        wyswietl_menu_lista_1k();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                pdodaj( &lista , x );
                printf("OK\n");
                break;
            case 2:
                printf("Dodaj wartosc: ");
                scanf("%i" , &x);
                kdodaj( &lista , x );
                printf("OK\n");
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
                p = el_war(lista , x);
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
                break;
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
                if( wczytanie_listy( &lista , &nazwa_pliku[0] ) )
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
            case 11:
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
                break;
            case 12:
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
                break;
            case 13:
                printf("Policz wystapienia wartosci: ");
                scanf("%i", &x);
                printf("Wartosc %i wystepuje w liscie %i razy.\n", x, ile_wystapien(lista, x) );
                break;
            case 14:
                printf("Najczesciej wystepujaca wartoscia jest %i\n", max_powt(lista) );
                break;
            case 0:
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    while (lista) // zwolnienie listy przed zakończeniem programu
        pusun(&lista);
}


int main() {
    lista_1k();

    printf("KONIEC\n");
    return 0;
}
