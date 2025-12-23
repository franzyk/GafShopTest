#include "navigation.h"
#include "interface.h"
#include "checksAndUtils.h"

#define NUMBER_OF_LOCATION 30
#define NUMBER_OF_CHOICE 2

extern bool logged;
const unsigned short int global_location[NUMBER_OF_LOCATION][NUMBER_OF_CHOICE] =
        {1,3, //PRIMO MENU
         2,7, //SECONDO MENU
         3,4, // DA 3 A 7 SONO I MENU DEI VARI CAPI VISTI IN CATEGORIA.
         4,4, //
         5,4, //
         6,4, //
         7,4, // FINO A QUI
         8,2, // Caso in cui si voglia vedere tutto oppure se si vuole modificare i capi dal menu gestione dell'admin
         9,2, // Prima maglia
         10,2, //seconda maglia
         11,2, //terza maglia
         12,2, //Primo Vestito
         13,2, //Secondo Vestito
         14,2, //Terzo Vestito
         15,2, //Primi occhiali
         16,2, //Secondo paio di occhiali
         17,2, //terzo paio
         18,2, // Primo jeans
         19,2, // secondo jeans
         20,2, // terzo jeans
         21,2, // primo cappello
         22,2, // secondo cappello
         23,2, // terzo cappello
         24,6, // MENU DA LOGGATO
         25,1, // MENU DEL PROFILO
         26,3, // MENU DEL CARRELLO
         27,2, // SCONTRINO FINALE
         28,2, // CARTA DI CREDITO O PAGAMENTO ALLA CONSEGNA
         29,5 // MENU DELL' ADMIN
        };

/** la prima colonna ci da la posizione del menu perchè in base al menu in cui ci troviamo la scelta fatta
in base a quale menu ci troviamo ci risponde in maniera diversa. invece la seconda colonna rappresenta il numero
di tasti premibili all'interno del menu e quindi il numero di possibili scelte.*/


int main() {
    emptyFile("cart.csv"); // svuota il carrello all'inizio della run.
    logged = 0; // variabile globale che segna se un utente è loggato o no.
    logo(); // interfaccia
    loading(); // caricamento finto solo estetico
    refreshPage();
    control(global_location[0][0]); //Primo menu
    return 0;
}