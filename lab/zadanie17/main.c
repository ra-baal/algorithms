/*!
 * AlgoSD Laboratorium
 */

#include <stdio.h>
#include <string.h>
#include "definicje.h"

void system() {
    char bufor[BUFOR] = {0};
    char argument[BUFOR] = {0};
    kat * root = utworz_system("/");
    kat * roboczy = root; // początkowy katalog roboczy

    printf("Polecenia: help, pwd, ls, cd, mkdir, rm, find, exit\n");

    while (1) {
        printf("user@system:%s$ ",roboczy->nazwa);
        fgets(bufor, BUFOR, stdin);
        parsuj(bufor, argument);

        if (strncmp(bufor, "help", BUFOR) == 0 )
            help();
        else if (strncmp(bufor, "pwd", BUFOR) == 0)
            path(roboczy);
        else if (strncmp(bufor, "ls", BUFOR) == 0)
            ls(roboczy->lista);
        else if (strncmp(bufor, "cd", BUFOR) == 0)
            cd(&roboczy, argument);
        else if (strncmp(bufor, "mkdir", BUFOR) == 0)
            mkdir(roboczy, argument);
        else if (strncmp(bufor, "rm", BUFOR) == 0)
            rm(roboczy, argument);
        else if (strncmp(bufor, "find", BUFOR) == 0)
            find(root, argument);
        else if (strncmp(bufor, "exit", BUFOR) == 0)
            break;
        else
            printf("Nieznana komenda.\n");
    }

    root = usun_system(root);
}

int main() {
    system();
    return 0;
}
