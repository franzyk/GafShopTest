#include "app_state.h"

void initAppState(AppState* state) {
    state->loggedIn = false;
    unsigned short int map[NUMBER_OF_LOCATIONS][NUMBER_OF_CHOICES] = {
        {1,3}, //PRIMO MENU
        {2,7}, //SECONDO MENU
        {3,4}, // DA 3 A 7 SONO I MENU DEI VARI CAPI VISTI IN CATEGORIA.
        {4,4}, //
        {5,4}, //
        {6,4}, //
        {7,4}, // FINO A QUI
        {8,2}, // Caso in cui si voglia vedere tutto oppure se si vuole modificare i capi dal menu gestione dell'admin
        {9,2}, // Prima maglia
        {10,2}, //seconda maglia
        {11,2}, //terza maglia
        {12,2}, //Primo Vestito
        {13,2}, //Secondo Vestito
        {14,2}, //Terzo Vestito
        {15,2}, //Primi occhiali
        {16,2}, //Secondo paio di occhiali
        {17,2}, //terzo paio
        {18,2}, // Primo jeans
        {19,2}, // secondo jeans
        {20,2}, // terzo jeans
        {21,2}, // primo cappello
        {22,2}, // secondo cappello
        {23,2}, // terzo cappello
        {24,6}, // MENU DA LOGGATO
        {25,1}, // MENU DEL PROFILO
        {26,3}, // MENU DEL CARRELLO
        {27,2}, // SCONTRINO FINALE
        {28,2}, // CARTA DI CREDITO O PAGAMENTO ALLA CONSEGNA
        {29,5} // MENU DELL' ADMIN
    };
    for (int i = 0; i < NUMBER_OF_LOCATIONS; i++) {
        for (int j = 0; j < NUMBER_OF_CHOICES; j++) {
            state->navigationMap[i][j] = map[i][j];
        }
    }
}
