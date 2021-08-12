/*!
 * AlgoSD Laboratorium
 * Rafał Balcerowski
 */

#include <stdio.h>
#include "DrzewoBinarneLancuchowZnakowychUporzadkowane.h"


void wyswietlMenu() {
    printf("Drzewo Binarne Lancuchow Znakowych z Uporzadkowaniem\n");
    printf("1 - dodaj\n");
    printf("2 - usun\n");
    printf("3 - szukaj\n");
    printf("4 - minimum\n");
    printf("5 - maksimum\n");
    printf("6 - poprzednik\n");
    printf("7 - nastepnik\n");
    printf("8 - drukuj\n");
    printf("9 - zapisz do pliku\n");
    printf("10 - wczytaj z pliku\n");
    printf("0 - zakoncz dzialanie programu\n");
}


void drzewoBinarneLancuchow() {
    /// DRZEWO BINARNE ŁAŃCUCHÓW ZNAKOWYCH UPORZĄDKOWANE ///
    int poz; // pozycja menu
    char bufor[20*LANCUCH_MAX] = {0};
    drzewo d = NULL; // drzewo początkowo puste
    elD* p = NULL; // pomocniczy wskaźnik (użyto w : menu - wyszukiwanie)

    do{
        wyswietlMenu();
        scanf("%i" , &poz);

        switch (poz) {
            case 1:
                printf("Lancuchy dluzsze niz %i zostana obciete.\n", LANCUCH_MAX-1);
                printf("Wpisz znaki: ");
                scanf("%s" , bufor);
                dodaj(&d, bufor);
                printf("OK\n");
                break;
            case 2:
                printf("Lancuchy dluzsze niz %i zostana obciete.\n", LANCUCH_MAX-1);
                printf("Wpisz ciag znakow do usuniecia: ");
                scanf("%s" , bufor);
                if ( usun(&d, bufor) )
                    printf("OK\n");
                else
                    printf("Brak takiej wartosci\n");
                break;
            case 3:
                printf("Lancuchy dluzsze niz %i zostana obciete.\n", LANCUCH_MAX-1);
                printf("Wpisz ciag znakow do odszukania: ");
                scanf("%s" , bufor);
                if ( (p = szukaj(d, bufor)) ) {
                    printf("Znaleziono w: %x\n", p);
                    printf("OK\n");
                }
                else
                    printf("Brak takiej wartosci\n");
                break;
            case 4:
                if (minimum(d, bufor)) {
                    printf("Najmniejsza wartosc to: %s\n", bufor);
                    printf("OK\n");
                }
                else
                    printf("Drzewo puste\n");
                break;
            case 5:
                if (maksimum(d, bufor)) {
                    printf("Najwieksza wartosc to: %s\n", bufor);
                    printf("OK\n");
                }
                else
                    printf("Drzewo puste\n");
                break;
            case 6:
                printf("Lancuchy dluzsze niz %i zostana obciete.\n", LANCUCH_MAX-1);
                printf("Wpisz ciag znakow, aby odszukac jego poprzednik: ");
                scanf("%s" , bufor);
                if ( (p = poprzednik(szukaj(d,bufor))) ) {
                    printf("Poprzednikiem '%s' jest: %s\n",bufor, p->lancuch);
                    printf("OK\n");
                }
                else
                    printf("'%s' nie ma poprzednika albo nie istnieje\n", bufor);
                break;
            case 7:
                printf("Lancuchy dluzsze niz %i zostana obciete.\n", LANCUCH_MAX-1);
                printf("Wpisz ciag znakow, aby odszukac jego nastepnik: ");
                scanf("%s" , bufor);
                if ( (p = nastepnik(szukaj(d,bufor))) ) {
                    printf("Nastepnikiem '%s' jest: %s\n",bufor, p->lancuch);
                    printf("OK\n");
                }
                else
                    printf("'%s' nie ma nastepnika albo nie istnieje\n", bufor);
                break;
            case 8:
                drukuj(d);
                break;
            case 9:
                printf("Podaj nazwe pliku do zapisu: ");
                scanf("%s", bufor);
                bufor[20] = 0;
                if (zapis_drzewa(d, bufor))
                    printf("OK\n");
                else
                    printf("Niepowodzenie\n");
                break;
            case 10:
                printf("Podaj nazwe pliku do wczytania: ");
                scanf("%s", bufor);
                bufor[20] = 0;
                if (wczytanie_drzewa(&d, bufor))
                    printf("OK\n");
                else
                    printf("Niepowodzenie\n");
                break;
            case 0:
                // zakończenie programu - pętla while zostanie przerwana
                break;
            default:
                printf("Brak takiej pozycji w menu\n");
                break;

        }
    } while (poz);


    wyczysc(&d);
}



int main() {
    drzewoBinarneLancuchow();

    return 0;
}
