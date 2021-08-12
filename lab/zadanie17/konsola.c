
#include <stdio.h>
#include <string.h>
#include "definicje.h"


void help() {
    const int rezerwacja = 11;
    printf("%-*s %s", rezerwacja, "help" , "Wyswietla opis polecen.\n");
    printf("%-*s %s", rezerwacja, "pwd", "Wyswietla katalog roboczy.\n");
    printf("%-*s %s", rezerwacja, "ls", "Wyswietla zawartosc katalogu roboczego.\n");
    printf("%-*s %s", rezerwacja, "cd NAZWA", "Zmienia katalog roboczy.\n");
    printf("%-*s %s", rezerwacja, "", "Jako argument podaj podkatalog katalogu roboczego\n");
    printf("%-*s %s", rezerwacja, "", "albo .. (dwie kropki), aby przejsc do katalogu nadrzednego.\n");
    printf("%-*s %s", rezerwacja, "mkdir NAZWA", "Tworzy katalog.\n");
    printf("%-*s %s", rezerwacja, "rm NAZWA", "Usuwa katalog wraz z podkatalogami.\n");
    printf("%-*s %s", rezerwacja, "find NAZWA", "Szuka w calym systemie katalogu o danej nazwie.\n");
//    printf("%-*s %s", rezerwacja, "mv", "Przenosi katalog w inne miejsce.\n");
//    printf("%-*s %s", rezerwacja, "cp", "Kopiuje katalog w inne miejsce.\n");
//    printf("%-*s %s", rezerwacja, "path", "Wyswietla sciezke podanego katalogu\n");
    printf("%-*s %s", rezerwacja, "exit", "Konczy dzialanie programu.\n");
}

void ls(kat* lista) {
    printf(". "); // obecny
    printf(".. "); // powrót do nadrzędnego (rodzica)

    if (lista) {
        kat *poczatek = lista;
        do {
            printf("%s ", lista->nazwa);
            lista = lista->nast;
        }
        while (lista != poczatek);
    }
    printf("\n");
}

void path_rek(kat* katalog) {
    if (!katalog)
        return;
    path_rek(katalog->rodzic);
    if (katalog->rodzic)
        printf("%s/", katalog->nazwa);
    else
        printf("%s", katalog->nazwa); // <=> printf("/")

}

/*! interfejs path_rek */
void path(kat* katalog) {
    path_rek(katalog);
    printf("\n");
}

void infodir(kat* katalog) {
    printf("Sciezka: "); path(katalog); printf("\n");

    printf("Adres w pamieci: %x\n", katalog);
    printf("Katalog nadrzedny: %s | %x\n",
           katalog->rodzic ? katalog->rodzic->nazwa : "Brak. To jest katalog glowny.",
           katalog->rodzic);
//    ls nast;
//    ls lista;
    printf("%x\n", katalog->nast);
    printf("%x\n", katalog->lista);

}

void rm(kat* roboczy, char nazwa[]) {
    if (nazwa[0]==0)
        printf("Podaj nazwe jako parametr\n");

    kat* szukany = szukaj_w_liscie(roboczy->lista, nazwa);
    if (szukany)
        usun_katalog(szukany);
    else
        printf("Nie ma takiego katalogu.\n");
}

/*!
 * Zostawia w napisie tylko pierwsze słowo, a resztę przenosi do drugiego łańcucha.
 */
void parsuj(char bufor[BUFOR], char arg[BUFOR]) {
    int i=0;

    for (i=0; i<BUFOR && bufor[i]!='\n' && bufor[i]!=' '; ++i);

    bufor[i]=0; // koniec na spacji lub znaku nowej linii

    i++; // i dalej kopiujemy do args
    strncpy(arg, bufor+i, BUFOR-i);

    for (i=0; i<BUFOR && arg[i]!='\n' && arg[i]!=' '; ++i);

    arg[i]=0; // koniec na spacji lub nowej linii
}

/*!
 * Komenda tworząca katalog.
 * @param katalog W tym katalogu powstanie nowy katalog.
 * @param nazwa Nazwa nowego katalogu.
 */
void mkdir(kat* katalog, char nazwa[]) {
    if (nazwa[0]==0)
        printf("Podaj nazwe jako parametr\n");
    else {
        if ( szukaj_w_liscie(katalog->lista, nazwa) == NULL )
            utworz_katalog(katalog, nazwa);
        else
            printf("Taki katalog juz istnieje.\n");
    }
}

void cd(kat** roboczy, char nazwa[]) {
    kat* szukany = NULL;

    if (nazwa[0]==0) {
        printf("Podaj nazwe jako parametr\n");
        return;
    }
    else if (strncmp(nazwa, "..", LANCUCH_MAX)==0) {
        if ( (*roboczy)->rodzic )
            *roboczy = (*roboczy)->rodzic;
        else
            printf("Katalog glowny nie ma katalogu nadrzednego.\n");
    }
    else {
        szukany = szukaj_w_liscie((*roboczy)->lista, nazwa);

        if (szukany)
            *roboczy = szukany;
        else
            printf("Nie ma takiego katalogu.\n");
    }
}

/*! W całym systemie szuka danego katalogu */
void find(kat* katalog, char nazwa[]) {
    if (nazwa[0]==0) {
        printf("Podaj nazwe jako parametr\n");
        return;
    }

    if (!katalog)
        return;

    kat* s = szukaj_w_liscie(katalog->lista, nazwa);
    if (s)
        path(s);

    if (katalog->lista) {
        s = katalog->lista; // teraz szukamy w podkatalogach
        do {
            find(s, nazwa);
            s = s->nast;
        } while (s != katalog->lista);
    }

}

