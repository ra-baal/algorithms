/** Definicje funkcji pomocniczych. */

#include <stdlib.h>

void ExitPrint(int kod, const char komunikat[]) {
    perror(komunikat);
    exit(kod);
}

