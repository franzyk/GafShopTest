#include "paymentDelivery.h"
#include "checksAndUtils.h"
#include "interface.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "authentication.h"
#include <time.h>


extern char tempEmail[];  //email dell'utente loggato
extern unsigned short int  tempQty[]; // quantità temporanea salvata
extern unsigned short int cartItems ; // numero di oggetti nel carrello


/**La funzione inputCreditCard() è utilizzata per acquisire i dettagli della carta di credito da parte dell'utente. */

void inputCreditCard() {
    Card card;
    int mm, yyyy;
    do {
        printf("\nNUMERO CARTA DI CREDITO(16): ");
        fflush(stdin);                                        //numero carta
        scanf_s("%17[^\n]", card.cardNumber, MAX_CARDNUMBER_LENGTH);
    }while(cardNumberCheck(card.cardNumber) == 0 || emptyString(card.cardNumber) == 0);

    do{
        printf("\nNOME TITOLARE CARTA: ");
        fflush(stdin);                      // NOME TITOLARE
        scanf_s("%49[^\n]", card.cardHolderName, MAX_CARDHOLDER_LENGTH);
    }while(checkNameSurname(card.cardHolderName) == 0);

    do{
        printf("\nCOGNOME TITOLARE CARTA: ");
        fflush(stdin);
        scanf_s("%49[^\n]", card.cardHolderSurname, MAX_CARDHOLDER_LENGTH);
    }while(checkNameSurname(card.cardHolderSurname) == 0);

    do{
        printf("\nCVV CARTA: ");
        fflush(stdin);
        scanf_s("%4[^\n]", card.cardCVV, MAX_CARDCVV_LENGTH);
    }while(checkCVV(card.cardCVV) == 0);

    do {
        do {
            printf("\nMESE DI SCADENZA CARTA: ");
            fflush(stdin);
            scanf_s("%3[^\n]", card.cardExpirationMM, MAX_GG_MM_LENGTH);
        } while (emptyString(card.cardExpirationMM)  == 0 || isNumber(card.cardExpirationMM) == 0);
        mm = atoi(card.cardExpirationMM);

        do {
            printf("\nANNO DI SCADENZA CARTA: ");
            fflush(stdin);
            scanf_s("%5[^\n]", card.cardExpirationYYYY, MAX_AAAA_LENGTH);
        } while (emptyString(card.cardExpirationYYYY)  == 0 || isNumber(card.cardExpirationYYYY) == 0);
        yyyy = atoi(card.cardExpirationYYYY);
    }while(checkCardDate(mm,yyyy) == 0 );

}

/**La funzione inputDeliveryAddress() viene utilizzata per acquisire l'indirizzo di consegna dall'utente. */


void inputDeliveryAddress() {
    AddressDelivery address;
    refreshPage();

    shippingAddressMenu(); //grafica

    do {
        printf("\nVIA: ");
        fflush(stdin);
        scanf_s("%79[^\n]", address.street, MAX_ADDRESS_LENGTH);
        address.street[strcspn( address.street, "\n")] = '\0';
    }while(checkAddress(address.street) == 0);

    do {
        printf("\nNUMERO CIVICO: ");
        fflush(stdin);
        scanf_s("%9[^\n]",address.addressNumber,MAX_ADDRESSNUMBER_LENGTH);             //ADDRESS NUMBER
        address.addressNumber[strcspn(address.addressNumber, "\n")] = '\0';
    } while(emptyString(address.addressNumber) == 0 || checkAddressNumber(address.addressNumber) == 0);

    do {
        printf("\nCITTA': ");
        fflush(stdin);
        scanf_s("%79[^\n]", address.city, MAX_CITY_LENGTH);
        address.city[strcspn( address.city, "\n")] = '\0';
    }while(checkAddress(address.city) == 0);

    do {
        printf("\nCAP: ");
        fflush(stdin);
        scanf_s("%9[^\n]", address.zipCode, MAX_ZIPCODE_LENGTH);
        address.zipCode[strcspn( address.zipCode, "\n")] = '\0';
    }while(checkCAP(address.zipCode) == 0);

    do {
        printf("\nPROVINCIA: ");
        fflush(stdin);
        scanf_s("%79[^\n]", address.province, MAX_PROVINCE_LENGTH);
        address.province[strcspn( address.province, "\n")] = '\0';
    }while (checkAddress(address.province) == 0);
}

/**La funzione createOrder() viene utilizzata per creare un ordine a partire dai prodotti presenti nel carrello. */


void createOrder() {
    unsigned short int idOrder;
    // Apri il file in modalità append
    unsigned short int status;
    idOrder = findLargestIdOrder() + 1;
    FILE* file = fopen(ORDERS_FILE, "a");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }
    FILE* fCart = fopen(CART_FILE, "r");
    if (file == NULL) {
        printf("Errore nell'apertura del file\n");
        return;
    }
    status = generateStatus();
    int i = 0;
    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, MAX_CLOTHINGITEM_LENGTH, fCart) != NULL) {
        Product item;
        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d", &item.code, item.name, item.brand, item.description, item.size, &item.price, &item.quantity);
        fprintf(file, "%hu,%s,%hu,%hu,%hu\n", idOrder, tempEmail, status, item.code, tempQty[i]);
        decrease_quantity(item.code, tempQty[i]);
        i++;
    }

    // Chiudi il file
    fclose(file);
    fclose(fCart);

    // Incrementa l'id per la prossima volta
    idOrder++;
    cartItems = 0;
}

/**La funzione findLargestIdOrder() viene utilizzata per trovare l'ID dell'ordine più grande nel file "orders.csv". */


int findLargestIdOrder() {
    FILE* file = fopen(ORDERS_FILE, "r");
    if (file == NULL) {
        printf("Impossibile aprire il file\n");
    }

    int largestIdOrder = 0;
    char line[MAX_CLOTHINGITEM_LENGTH];  // Dimensione massima della riga
    fgets(line, sizeof(line), file);
    while (fgets(line, sizeof(line), file) != NULL) {
        int currentIdOrder;
        sscanf(line, "%d", &currentIdOrder);

        if (currentIdOrder > largestIdOrder) { // se l'id corrente è piu grande allora diventa il più grande
            largestIdOrder = currentIdOrder;
        }
    }
    fclose(file);
    return largestIdOrder;
}


/**La funzione generateStatus() genera un numero casuale compreso tra 1 e 3 e lo restituisce come valore di stato dell'ordine. */


int generateStatus() {
    unsigned short int status;
    // Inizializzazione del generatore di numeri casuali
    srand(time(NULL));
    // Generazione del numero casuale compreso tra 1 e 3
    status = (rand() % 3) + 1;

    return status;
}

/**La funzione showUserOrders() legge il file "orders.csv" e mostra gli ordini dell'utente corrispondenti all'indirizzo email specificato. */


void showUserOrders(char email[]){
    Order order;
    FILE* file = fopen(ORDERS_FILE, "r");
    if (file == NULL) {
        printf("Impossibile aprire il file\n");
    }

    char line[MAX_CLOTHINGITEM_LENGTH];  // Dimensione massima della riga
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf( line, "%hu,%[^,],%hu,%hu,%hu\n", &order.idOrder, order.email, &order.status, &order.idProduct, &order.productQuantity);
        if(strcmp(order.email, email) == 0){
            showUserOrdersMenu(order.idOrder, order.status, order.idProduct, order.productQuantity);
        }
   }
    fclose(file);
}

/**La funzione decrease_quantity() diminuisce la quantità di un determinato prodotto nel file "clothes.csv". */


void decrease_quantity(int id, int quantity) {

    FILE *inputFile = fopen(CLOTHES_FILE, "r");
    FILE *outputFile = fopen(CLOTHES_TEMP_FILE, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("ERRORE NEL APERTURA DEL FILE\n");
        return;
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    while (fgets(line, sizeof(line), inputFile)) {
        Product product;
        sscanf(line, "%hu,%[^,],%[^,],%[^,],%[^,],%lf,%d",
               &product.code, product.name, product.brand, product.description,
               product.size, &product.price, &product.quantity);

        if (product.code == id) {
            product.quantity -= quantity;
        }

        fprintf(outputFile, "%hu,%s,%s,%s,%s,%.2lf,%d\n",
                product.code, product.name, product.brand, product.description,
                product.size, product.price, product.quantity);
    }

    fclose(inputFile);
    fclose(outputFile);

    remove(CLOTHES_FILE);
    rename(CLOTHES_TEMP_FILE, CLOTHES_FILE);
}

/**La funzione refundUserOrders() fa fare i rimborsi agli utenti e rimuove gli ordini dal file "orders.csv" */


void refundUserOrders(char email[]) {
    char refundId[MAX_CLOTHINGITEM_LENGTH];
    Order order;
    FILE* inputFile = fopen(ORDERS_FILE, "r");
    FILE* outputFile = fopen(ORDERS_TEMP_FILE, "w");
    bool  idOrderFlag = 0;

    strcpy(refundId, "");

    if (inputFile == NULL || outputFile == NULL) {
        printf("ERRORE NELL'APERTURA DEL FILE\n");
        return;
    }

    char line[MAX_CLOTHINGITEM_LENGTH];
    fgets(line, sizeof(line), inputFile);
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        sscanf( line, "%hu,%[^,],%hu,%hu,%hu\n", &order.idOrder, order.email, &order.status, &order.idProduct, &order.productQuantity);
        if(strcmp(order.email, email) == 0){
            showUserOrdersMenu(order.idOrder, order.status, order.idProduct, order.productQuantity);
        }
    }

    do {
        printf("\nINSERIRE L'ID DEL PRODOTTO DI CUI SI VUOLE IL RIMBORSO\n(Lasciare vuoto per tornare al menu): ");
        fflush(stdin);
        scanf("%499[^\n]", refundId);
        if (strcmp(refundId, "") == 0) {
            fclose(inputFile);
            fclose(outputFile);
            return;
        }
    } while (isNumber(refundId) == 0);


    int refundProductId = atoi(refundId); //  refundId in un intero
    // Riavvolgi il file di input all'inizio
    rewind(inputFile);

    // Processa ogni riga del file di input
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        sscanf(line, "%hu,%[^,],%hu,%hu,%hu\n", &order.idOrder, order.email, &order.status, &order.idProduct, &order.productQuantity);
        if (strcmp(order.email, email) == 0) {
            // Verifica se l'ordine corrente corrisponde a refundProductId
            if (order.idOrder == refundProductId) {
                // Salta la scrittura di questa riga nel file di output (eliminando effettivamente l'ordine)
                idOrderFlag = 1;
               continue;
            }
        }
        // Scrivi la riga nel file di output
            fputs(line, outputFile);
    }
    // Chiudi i file di input e output
    fclose(inputFile);
    fclose(outputFile);

    remove(ORDERS_FILE);
    rename(ORDERS_TEMP_FILE, ORDERS_FILE);

    if(idOrderFlag == 1) {
        loading();
        refreshPage();
        printf("\n\n\n\n\n\n\n++=========================================================================================++\n");
        printf("    \nRIMBORSO CONFERMATO CI DISPIACE CHE NON TI SIA PIACIUTO\n");
        printf("\n++=========================================================================================++\n");
        system("pause");
    }else{
        loading();
        refreshPage();
        printf("\n\n\n\n\n\n\n++=========================================================================================++\n");
        printf("    \nRIMBORSO NON RIUSCITO NESSUN ORDINE CON ID: %d\n",refundProductId);
        printf("\n++=========================================================================================++\n");
        system("pause");
    }
}