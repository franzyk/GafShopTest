#include "catalog.h"
#include <stdio.h>
#include "checksAndUtils.h"
#include "navigation.h"
#include "stdlib.h"
#include "admin.h"
#include <string.h>

#define NUMBER_OF_LOCATION 30
#define NUMBER_OF_CHOICE 2
#define MAX_ORDER_QUANTITY 5  // MASSIME CIFRE DELLA QUANTITA DI UN PRODOTTO INSERITA DELL'UTENTE
unsigned short int clothesCheck[CART_ITEMS] = {0};  // serve a controllare che non vengano messo più di un prodotto dello stesso tipo nel carrello
unsigned short int cartItems = 0;  // numero di oggetti nel carrelo
unsigned short int tempQty[CART_ITEMS] = {0};  // vengono messe le quantita temporanee che l'utente inserisce
double finalPrice; //prezzo finale dello scontrino
extern bool logged;  // si vede se l'utente è loggato
extern char tempEmail[]; // email dell'utente loggato
extern const unsigned short int global_location[NUMBER_OF_LOCATION][NUMBER_OF_CHOICE];


/** passata la selezione dell'utente gestisce l'interfaccia dei vestiti*/

void catalog(unsigned short int selection) {
    loading();
    refreshPage();
    switch (selection) {
        case 0:
            puts("ESPLORA");
            control(global_location[7][0]); // tutti i vestiti
            break;
        case 1:
            puts("MAGLIE");
            control(global_location[2][0]);
            break;
        case 2:
            puts("VESTITI");
            control(global_location[3][0]);
            break;
        case 3:
            puts("OCCHIALI");
            control(global_location[4][0]);
            break;
        case 4:
            puts("PANTALONI");
            control(global_location[5][0]);
            break;
        case 5:
            puts("CAPPELLI");
            control(global_location[6][0]);
            break;
        case 6:
            if(logged == 0){  // se si è loggati o meno torna in menu diversi
                control(global_location[0][0]);  // menu non loggato
            }else{
                control(global_location[23][0]); // menu loggato
            }
            break;
    }
}

/**
La funzione cart() gestisce l'aggiunta di un articolo al carrello dell'utente.*/

void cart (unsigned short int location) {

    for(int i = 0; i <= cartItems; i++){ // se è già presente nel carrello non lo rimette
        if(clothesCheck[i] == location){
            return;
        }else{
            clothesCheck[i] = location;
            printf("\nClothesCheck: %d",clothesCheck[i]);
        }
    }
    cartItems++; // aumenta i prodotti nel carrello
    FILE* file = fopen("clothes.csv", "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
    }
    FILE* fCart = fopen("cart.csv", "a");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, MAX_CLOTHINGITEM_LENGTH, file) != NULL) {
        Product item;
        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand, item.description, item.size, &item.price, &item.quantity);
        if (item.code == location) {
            fprintf(fCart, "%hu,%s,%s,%s,%s,%.2lf,%d\n", item.code, item.name, item.brand, item.description, item.size, item.price, item.quantity);
        }
    }
    fclose(file);
    fclose(fCart);
}


/**

La funzione cartManager() gestisce il processo di gestione del carrello chiede la quantita di prodotti calcola il prezzo finale e chiede il coupon.*/

void cartManager(){
    char coupon[50]; // coupon da estrarre
    finalPrice = 0;
    unsigned short int qty;
    char quantity[MAX_ORDER_QUANTITY];
    int i  = 0;
    loading();

    FILE *fCart = fopen("cart.csv", "r");
    if (fCart == NULL) {
        printf("Errore nell'apertura del file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, MAX_CLOTHINGITEM_LENGTH, fCart) != NULL) {
        Product item;
        refreshPage();
        cartTophead(); //grafica

        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand, item.description, item.size, &item.price, &item.quantity);
        cloth(item.code); // stampa il vestito con l'id corrispondente
        printf("\nINSERIRE LA QUANTITA' DEL PRODOTTO DA ORDINARE: ");

        do {
            strcpy(quantity,"");
            fflush(stdin);
            scanf_s("%4[^\n]",quantity,MAX_ORDER_QUANTITY);
            quantity[strcspn(quantity, "\n")] = '\0';
            qty = atoi(quantity);
            if(qty < 1){
                puts("\n\t\t\tSeleziona almeno un prodotto");
            }
        } while(checkQuantity(quantity, item.quantity) == 0 || qty < 1);
            tempQty[i] = qty;
        finalPrice += item.price * (double) qty; // calcolo del prezzo finale senza coupon
        i++;
    }
    fclose(fCart);

    puts("INSERISCI UN COUPON (LASCIARE VUOTO SE NON SI HA UN COUPON ");
    printf("------------------------------------------------------------------------------------");
    fflush(stdin);
    printf("\n\n\t\tCOUPON: ");
    fgets(coupon, sizeof(coupon), stdin);     // COUPON DA INSERIRE A FINE TRANSAZIONE
    coupon[strcspn(coupon, "\n")] = '\0';
    readCoupon(coupon); // controllo del coupon


    control(global_location[26][0]); //scontrino finale
}

/**

La funzione idCartExtract() estrae gli ID degli articoli presenti nel carrello e visualizza i dettagli di ciascun articolo.*/

void idCartExtract() {

    FILE *fCart = fopen("cart.csv", "r");
    if (fCart == NULL) {
        printf("Errore nell'apertura del file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, MAX_CLOTHINGITEM_LENGTH, fCart) != NULL) {
        Product item;
        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand, item.description, item.size, &item.price, &item.quantity);
        cloth(item.code);
    }
}


