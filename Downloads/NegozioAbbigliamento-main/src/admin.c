#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "admin.h"
#include "checksAndUtils.h"
#include "authentication.h"
#include <string.h>
#include "paymentDelivery.h"

#define COUPON_LENGTH 8 // lunghezza del coupon
#define COUPON_PERCENTAGE_LENGTH 5 // Lunghezza per la percentuale di sconto
#define NUM_CHARACTERS 62 //Il numero totale di caratteri consentiti (26 maiuscole + 26 minuscole + 10 cifre) è 62.

extern double finalPrice;

/**
La funzione generate_coupon genera un coupon casuale utilizzando caratteri maiuscoli, minuscoli e cifre.  */

void generate_coupon(int percentage) {
    char coupon[COUPON_LENGTH];
    for (int i = 0; i < COUPON_LENGTH; i++) {
        int random_num = rand() % NUM_CHARACTERS;
        int ascii_code;

        if (random_num < 26) {
            // Carattere maiuscolo casuale (codici ASCII 65-90)
            ascii_code = random_num + 65;
        } else if (random_num < 52) {
            // Carattere minuscolo casuale (codici ASCII 97-122)
            ascii_code = random_num + 71;
        } else {
            // Cifra casuale (codici ASCII 48-57)
            ascii_code = random_num - 4;
        }

        coupon[i] = (char) ascii_code;
    }

    coupon[COUPON_LENGTH-1] = '\0'; // Aggiungi terminatore nullo per creare una stringa valida
    saveCoupon(coupon, percentage); // chiama la funzione che salva su file dei coupon
}

/**
La funzione saveCoupon salva il coupon generato insieme alla percentuale di sconto associata in un file CSV chiamato "coupon.csv". */
void saveCoupon(const char* coupon, int percentage) {
    FILE* file = fopen(COUPON_FILE, "a");
    if (file == NULL) {
        printf("Error opening the file.");
        return;
    }
    fprintf(file, "%s,%d\n", coupon, percentage);
    fclose(file);
    printf("\n COUPON GENERATO CORRETTAMENTE\n");
    system("pause");
}


/**
La funzione readCoupon legge il file CSV "coupon.csv" e cerca un coupon corrispondente al coupon fornito dall'utente. */

void readCoupon(const char userCoupon[]) {
    FILE* file = fopen(COUPON_FILE, "r");
    if (file == NULL) {
        printf("Error opening the file.");
    }
    char coupon[COUPON_LENGTH + 1];
    int percentage;
    char line[COUPON_LENGTH + 4];
    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%[^,],%d" , coupon, &percentage);
        if(strcmp(userCoupon, coupon) == 0){
            finalPrice = finalPrice - (finalPrice*((double)percentage/100)) ; // se lo sconto inviato dall'utente è esistente allora viene applicato al prezzo finale
            break; // perchè abbiamo trovato il coupon
        }
    }
    fclose(file);
}


/**

La funzione addCoupon gestisce l'aggiunta di un nuovo coupon nel sistema */

void addCoupon(){
    topheadAdmin(); // interfaccia grafica
    char percentage[COUPON_PERCENTAGE_LENGTH];
    int convertedPercentage;
    do {
        do {
            printf("\n++=========================================================================================++\n");
            printf("    \nGenerazione Coupon\n");
            printf("\n++=========================================================================================++\n");
            printf("     Inserire sconto del coupon (5%% a 100%%): ");
            fflush(stdin); //svuoto il buffer
            scanf_s("%4[^\n]", percentage, COUPON_PERCENTAGE_LENGTH);
        } while (emptyString(percentage) == 0 || isNumber(percentage) == 0);
        convertedPercentage = atoi(percentage);  // converto la percentuale in int
    } while (checkPercentage(convertedPercentage) == 0);
    srand(time(NULL));
    generate_coupon(convertedPercentage); // ora genero il cuopon
}



/**

La funzione showAllProfiles visualizza tutti i profili utente presenti nel file "users.csv". */

void showAllProfiles(){
    topheadAdmin(); // interfaccia grafica
    FILE* file = fopen(USERS_FILE, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];     // Dichiarazione di una variabile per contenere una riga letta dal file
    tophead(); // grafica
    fgets(line, sizeof(line), file);    //salto la prima linea dei nomi delle colonne
    while (fgets(line, sizeof(line), file) != NULL) {   // Legge ogni riga del file finché non raggiunge la fine
        User userData; // Dichiarazione di una variabile di tipo User per memorizzare i dati utente

        int result = sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
                            userData.email, userData.password, userData.name, userData.surname, userData.phoneNumber,
                            userData.address, userData.addressNumber, userData.dob.day, userData.dob.month, userData.dob.year);

        if (result == 10) {
            printf("----------------------------------------\n");
            printf("| Dati del Profilo \n");
            printf("----------------------------------------\n");
            printf("| Email: %s\n", userData.email);
            puts("|");
            printf("| Password: %s\n", userData.password);
            puts("|");
            printf("| Nome: %s\n", userData.name);
            puts("|");
            printf("| Cognome: %s\n", userData.surname);
            puts("|");
            printf("| Numero di Telefono: %s\n", userData.phoneNumber);
            puts("|");
            printf("| Indirizzo: %s\n", userData.address);
            puts("|");
            printf("| Numero Civico: %s\n", userData.addressNumber);
            puts("|");
            printf("| Data di Nascita: %s/%s/%s\n", userData.dob.day, userData.dob.month, userData.dob.year);
            puts("|");
            printf("----------------------------------------\n\n\n\n\n\n");
        }
    }
    system("pause");
    fclose(file); // Chiude il file
}




/**

La funzione editClothInfo consente di modificare le informazioni di un indumento nel file "clothes.csv" utilizzando un ID specifico. */

void editClothInfo(const unsigned short int idCloth){
    loading(); // grafica
    refreshPage();
    topheadAdmin(); // grafica
    cloth(idCloth); // stampa il vestito corrispondente all'id
    Product item[2]; // item[0] viene salvato la riga attuale nell [1] la riga modificata

    char price[MAX_PRODUCT_SIZE], quantity[MAX_PRODUCT_SIZE];
    FILE *inputFile = fopen(CLOTHES_FILE, "r");
    FILE *outputFile = fopen(CLOTHES_TEMP_FILE, "w");

    strcpy(item[1].name, "");
    strcpy(item[1].brand, "");
    strcpy(item[1].description, "");
    strcpy(item[1].size, "");               // metto tutto a null per controlli più avanti nella funzione
    strcpy(price, "");
    strcpy(quantity, "");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Errore nell'apertura del file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, sizeof(line), inputFile) != NULL) {

        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item[0].code, item[0].name, item[0].brand, // prendo la riga
               item[0].description, item[0].size, &item[0].price, &item[0].quantity);

        if(item[0].code == idCloth){
            item[1].code = item[0].code;   // salvo il codice della riga da modificare
            printf("\n++=========================================================================================++\n");
            printf("    \nModifica il contenuto dell'indumento\n");
            printf("\n++=========================================================================================++\n");

            printf("     Inserire un nuovo nome per il prodotto \n(lasciare vuoto per mantenere quello precedente): \n");
            fflush(stdin);
            scanf_s("%49[^\n]", item[1].name, MAX_PRODUCT_NAME);
            if(strcmp(item[1].name,"") == 0){           // se viene lasciato il campo vuoto allora vengono mantenuti i dati precedenti
                strcpy(item[1].name, item[0].name);
                printf("\t\t\n%s\n",item[1].name);
            }

            printf("     Inserire un nuovo brand per il prodotto \n(lasciare vuoto per mantenere quello precedente): \n");
            fflush(stdin);
            scanf_s("%29[^\n]", item[1].brand, MAX_PRODUCT_BRAND);
            if(strcmp(item[1].brand,"") == 0){
                strcpy(item[1].brand, item[0].brand);
                printf("\t\t\n%s\n",item[1].brand);
            }

            printf("     Inserire una nuova descrizione per il prodotto \n(lasciare vuoto per mantenere quello precedente): \n");
            fflush(stdin);
            scanf_s("%499[^\n]", item[1].description, MAX_PRODUCT_DESCRIPTION);
            if(strcmp(item[1].description,"") == 0){
                strcpy(item[1].description, item[0].description);
                printf("\t\t\n%s\n",item[1].description);
            }
            do {
                printf("     Inserire una nuova taglia per il prodotto \n(lasciare vuoto  per mantenere quello precedente): \n");
                fflush(stdin);
                scanf_s("%5[^\n]", item[1].size, MAX_PRODUCT_SIZE);
                if(strcmp(item[1].size,"") == 0){
                    strcpy(item[1].size, item[0].size);
                    printf("\t\t\n%s\n",item[1].size);
                }
            }while(checkItemSize(item[1].size) == 0);


            do {
                printf("     Inserire un nuovo prezzo per il prodotto \n(lasciare vuoto per mantenere quello precedente): \n");
                fflush(stdin);
                scanf_s("%9[^\n]", price, MAX_PRODUCT_SIZE);
                if(strcmp(price,"") == 0){
                    item[1].price = item[0].price;
                    printf("\t\t\n%.2lf\n",item[1].price);
                }else{
                    item[1].price = atof(price);   // conversione  in double
                }

            } while (isDouble(price) == 0);

            do {
                printf("     Inserire una nuova quantita' per il prodotto \n(lasciare vuoto per mantenere quello precedente): \n");
                fflush(stdin);
                scanf_s("%9[^\n]", quantity, MAX_PRODUCT_SIZE);
                if(strcmp(quantity,"") == 0){
                    item[1].quantity = item[0].quantity;
                    printf("\t\t\n%d\n",item[1].quantity);
                }else{
                    item[1].quantity = atoi(quantity);  // conversione in int
                }
            } while (isNumber(quantity) == 0);
        }else{
                    fprintf(outputFile, "%d,%s,%s,%s,%s,%.2lf,%d\n", item[0].code, item[0].name, item[0].brand,
                    item[0].description, item[0].size, item[0].price, item[0].quantity);            // se la riga non corrisponde a quella dell'id viene semplicemente riscritta
        }
        if(item[0].code == idCloth){
                    fprintf(outputFile, "%d,%s,%s,%s,%s,%.2lf,%d\n", item[1].code, item[1].name, item[1].brand,  // riga modificata e riscritta
                    item[1].description, item[1].size, item[1].price,item[1].quantity);
        }
    }
    fclose(inputFile);
    fclose(outputFile);

    remove(CLOTHES_FILE);
    rename(CLOTHES_TEMP_FILE, CLOTHES_FILE);

    puts("\n\n\t\tPRODOTTO MODIFICATO");
    system("pause");
}



/**La funzione showAllUserOrders() legge il file "orders.csv" e mostra gli ordini di tutti gli utenti. */


void showAllUserOrders(){
    topheadAdmin();
    Order order;
    FILE* file = fopen(ORDERS_FILE, "r");
    if (file == NULL) {
        printf("Impossibile aprire il file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];  // Dimensione massima della riga
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf( line, "%hu,%[^,],%hu,%hu,%hu\n", &order.idOrder, order.email, &order.status, &order.idProduct, &order.productQuantity);
            printf("\t-----------------------------------------------\n");
            printf("\n\t\tEMAIL DELL'UTENTE: %s\n",order.email);
            printf("\t-----------------------------------------------\n");
            showUserOrdersMenu(order.idOrder, order.status, order.idProduct, order.productQuantity);
    }
    fclose(file);
    system("pause");
}