#ifndef DRZEWO_KATALOGOW_H
#define DRZEWO_KATALOGOW_H

#define LANCUCH_MAX 8 // maksymalny rozmiar nazwy katalogu (o jeden mniej, ostatni na zero)
#define BUFOR 200

typedef struct katalog {
    char nazwa[LANCUCH_MAX];
    struct katalog* rodzic; // katalog nadrzedny
    struct katalog* nast; // "bracia" - następny element listy podkatalogów katalogu nadrzędnego
    struct katalog* lista; // dzieci - lista podkatalogów
} kat;

// system //
kat* utworz_katalog(kat* rodzic, const char nazwa[]);
kat* utworz_system(const char nazwa_katalogu_glownego[]);
void usun_katalog(kat* katalog);
void dolacz_do_listy ( kat** lista, kat* katalog);
kat* odlacz_z_listy(kat* katalog);
kat* szukaj_w_liscie(kat* lista, char nazwa[]);
kat* usun_system(kat* root);

// konsola //
void path_rek(kat* katalog);
void path(kat* katalog);
void mkdir(kat* katalog, char nazwa[]);
void infodir(kat* katalog);
void help();
void ls(kat* lista);
void cd(kat** roboczy, char nazwa[]);
void find(kat* roboczy, char nazwa[]);
void rm(kat* roboczy, char nazwa[]);
void parsuj(char bufor[BUFOR], char args[BUFOR]);

#endif
