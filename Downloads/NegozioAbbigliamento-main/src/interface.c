#include "interface.h"
#include "checksAndUtils.h"
#include <stdio.h>
#include <stdlib.h>
#include "catalog.h"
#include <string.h>
#include <windows.h>
#include "ui.h"

#define LOAD_TIME 20

void loading() {
    printf("\n\nCaricamento in corso... ");
    for (int i = 0; i < LOAD_TIME; i++) {
        Sleep(LOAD_TIME);
        printf("%c", 219);
    }
    printf(" completato!\n");
}

void refreshPage() {
    system("cls");
}
