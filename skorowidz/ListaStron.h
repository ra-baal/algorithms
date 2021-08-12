// Lista stron - plik nagłówkowy

#ifndef SKOROWIDZ_LISTASTRON_H
#define SKOROWIDZ_LISTASTRON_H

/** Element listy stron. */
typedef struct NumerStrony {
    int Numer;

    struct NumerStrony* nast;
} NumerStrony;

/** Wskaźnik na listę, tzn. na jej (pierwszy) element.*/
typedef NumerStrony* ListaStron;


void DodajStrone( ListaStron* lista, int numer );
void WyswietlListeStron(ListaStron lista);
void WyswietlListeStronZakresy(ListaStron lista);
NumerStrony* KolejneStrony(NumerStrony* strona, int minimalnyZakres);
void WyczyscListeStron( ListaStron* lista );
void UsunPowtorzeniaStron(ListaStron* l);
ListaStron OdwrocListeStron( ListaStron lista );


#endif //SKOROWIDZ_LISTASTRON_H
