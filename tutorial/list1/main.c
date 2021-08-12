/* AlgoSD - ćwiczenia
 * Lista 1 - plik główny - main.c
 * Rafał Balcerowski - 289524 */

#include <stdio.h>
#include "lista1.h"

void test_zad6() {
    el* lista = NULL;
    wyswietl_lista( lista );

    lista = dodaj_sort_rek(lista, 0);
    wyswietl_lista( lista );

    lista = dodaj_sort_rek(lista, 0);
    wyswietl_lista( lista );

    lista = dodaj_sort_rek(lista, 1);
    wyswietl_lista( lista );

    pdodaj(&lista, 6);
    wyswietl_lista( lista );

    kdodaj(&lista, 1);
    wyswietl_lista( lista );

    pdodaj(&lista, 6);
    wyswietl_lista( lista );

    lista = dodaj_sort_rek(lista, 6);
    wyswietl_lista( lista );

    lista = dodaj_sort_rek(lista, 6);
    wyswietl_lista( lista );

    pdodaj(&lista, 100);
    wyswietl_lista( lista );

    usun_powt_rek(&lista);
    wyswietl_lista( lista );

}

void test_zad7() {
    el* lista;
    konstruktor_wartow_v2(&lista);
    wyswietl_lista_wartow( lista );

    lista = dodaj_sort_wartow_bez_powt_v2(lista, 4);
    wyswietl_lista_wartow( lista );

    lista = dodaj_sort_wartow_bez_powt_v2(lista, 4);
    wyswietl_lista_wartow( lista );

    lista = dodaj_sort_wartow_bez_powt_v2(lista, 5);
    wyswietl_lista_wartow( lista );

    lista = dodaj_sort_wartow_bez_powt_v2(lista, 4);
    wyswietl_lista_wartow( lista );

    dodaj_sort_wartow_bez_powt(&lista, 4);
    wyswietl_lista_wartow( lista );

    dodaj_sort_wartow_bez_powt(&lista, 5);
    wyswietl_lista_wartow( lista );

    lista = destruktor_wartow_v2(&lista);
    wyswietl_lista_wartow( lista );
}

void test_sortuj_elementy() {
    el* lista = NULL;

    pdodaj( &lista , 8 );
//    pdodaj( &lista , 8 );
//    pdodaj( &lista , -100 );
    pdodaj( &lista , 100 );
    pdodaj( &lista , -100 );
//    pdodaj( &lista , -100 );
    kdodaj(&lista, -1000);
    wyswietl_lista( lista );

    sortuj_elementy_eliminuj_powt(&lista);
    wyswietl_lista(lista);

    while (lista){
        pusun( &lista );
    }

    wyswietl_lista( lista );
}

void test_zadanie11() {
    /* lista dwukiernkowa */

    el2* lista = NULL;

//    dodaj_p_lista2(&lista , 0);
//    dodaj_p_lista2(&lista , 1);

    dodaj_k_lista2(&lista, -100);
    dodaj_p_lista2(&lista , 10);
    dodaj_k_lista2(&lista, 99);
    wyswietl_lista2( lista);

   // dodaj_przed_danym_lista2(&lista, el_n(lista, 2), 666);

    wyswietl_lista2(lista);

}

void test_cykliczna() {
    el* lista = NULL;
    wyswietl_lista_cykliczna(lista);

    dodaj_za_cykliczna(&lista, 1);
    dodaj_za_cykliczna(&lista, 1);
    dodaj_za_cykliczna(&lista, 1);
    dodaj_za_cykliczna(&lista, 3);
    dodaj_za_cykliczna(&lista, 3);
//    dodaj_za_cykliczna(&lista, 12);
//    dodaj_za_cykliczna(&lista, 10);
//    dodaj_za_cykliczna(&lista, 4);
//    dodaj_za_cykliczna(&lista, 3);
//    dodaj_za_cykliczna(&lista, 3234);

    wyswietl_lista_cykliczna(lista);

    printf("usun powtorzenia rek\n");
    //usun_co_k_cykliczna_rek(&lista, NULL, 11);
    //delete_repeat(&lista);
    usun_powt_cykliczna_rek(&lista);
    wyswietl_lista_cykliczna(lista);

//    usun_dany_cykliczna( &lista, el_war_cykliczna(lista, 1) );
//    usun_dany_cykliczna_rek( &lista, lista, -15 );
    //wyswietl_lista_cykliczna(lista);


//    dodaj_za_cykliczna(&lista, 0);
//    wyswietl_lista_cykliczna(lista);

//    dodaj_za_cykliczna(&lista, 2);
//    wyswietl_lista_cykliczna(lista);
//
//    dodaj_za_cykliczna(&lista, 0);
//    wyswietl_lista_cykliczna(lista);
//
//    dodaj_za_cykliczna(&lista, 1);
//    wyswietl_lista_cykliczna(lista);


//    printf("\nIle -1: %i\n", ile_wystapien_cykliczna_rek(lista,lista,-1));
//    printf("\nIle 0: %i\n", ile_wystapien_cykliczna_rek(lista,lista,0));
//    printf("\nIle 1: %i\n", ile_wystapien_cykliczna_rek(lista,lista,1));
//    printf("\nIle 2: %i\n", ile_wystapien_cykliczna_rek(lista,lista,2));
//    printf("\nIle 3: %i\n", ile_wystapien_cykliczna_rek(lista,lista,3));
//
//    wyswietl_lista_cykliczna(lista);
//    printf("\nNajwiecej powtorzen ma: %i\n", max_powt_cykliczna_rek(lista, lista, 0, 0));

    //usun_powt_cykliczna_rek(&lista, NULL);


//    dodaj_przed_cykliczna(&lista, 10);
//    printf("%p\n", el_war_cykliczna_rek(lista,lista,-1));
//    printf("%p\n", el_war_cykliczna_rek(lista,lista,0));
//    printf("%p\n", el_war_cykliczna_rek(lista,lista,1));
//    printf("%p\n", el_war_cykliczna_rek(lista,lista,10));

 //   wyswietl_lista_cykliczna(lista);

    //printf("\nNajwiecej powtorzen ma: %i\n", max_powt_cykliczna(lista));

    while(lista) {
        usun_dany_cykliczna( &lista, lista );
    }

    wyswietl_lista_cykliczna(lista);
}

int main() {

    test_zad6();
    //test_zad7();
    //test_sortuj_elementy();
    //test_zadanie11();
    //test_cykliczna();

    return 0;
}
