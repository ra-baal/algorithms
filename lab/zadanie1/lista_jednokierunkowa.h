//
// lista_jednokierunkowa.h
//

#ifndef ZADANIE1_LISTA_JEDNOKIERUNKOWA_H
#define ZADANIE1_LISTA_JEDNOKIERUNKOWA_H


typedef struct elem {
    int x;
    struct elem *nast;
} el;

void wyswietl_el( el* e );
void pdodaj ( el** lista , int x );
el* ostatni( el* lista );
el* el_n (el* lista , int n );
void kdodaj ( el** lista , int x );
el* el_war ( el* lista , int x );
void pusun ( el** lista );
void kusun ( el** lista );
void usun_dany( el** lista , el* cel );
int dodaj_przed( el** lista , int x , el* cel );
int dodaj_za( el** lista , int x , el* cel );
void wyswietl_lista ( el* lista );

int zapis_listy( el* lista , char* nazwa_pliku );
int wczytanie_listy( el** lista , char* nazwa_pliku );

void test(void);

#endif //ZADANIE1_LISTA_JEDNOKIERUNKOWA_H
