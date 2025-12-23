
#ifndef NEGOZIOABBIGLIAMENTO_PAYMENTDELIVERY_H
#define NEGOZIOABBIGLIAMENTO_PAYMENTDELIVERY_H

#define MAX_CARDNUMBER_LENGTH 18
#define MAX_CARDHOLDER_LENGTH 50
#define MAX_CARDCVV_LENGTH 5
#define MAX_CITY_LENGTH 80
#define MAX_ZIPCODE_LENGTH 10
#define MAX_PROVINCE_LENGTH 80
#include "checksAndUtils.h"

typedef struct {
    unsigned short int idOrder;
    char email[MAX_EMAIL_LENGTH];
    unsigned short int status;    // DATI DELL'ORDINE
    char address[MAX_ADDRESS_LENGTH];
    unsigned short int idProduct;
    unsigned short int productQuantity;
}Order;

typedef struct {
    char cardNumber[MAX_CARDNUMBER_LENGTH];
    char cardHolderName[MAX_CARDNUMBER_LENGTH];
    char cardHolderSurname[MAX_CARDNUMBER_LENGTH];
    char cardExpirationMM[MAX_GG_MM_LENGTH];    //DATI DELLA CARTA
    char cardExpirationYYYY[MAX_AAAA_LENGTH];
    char cardCVV[MAX_CARDCVV_LENGTH];
}Card;

typedef struct {
    char street[MAX_ADDRESS_LENGTH];
    char addressNumber[MAX_ADDRESSNUMBER_LENGTH];
    char city[MAX_CITY_LENGTH];   //DATI DELL' INDIRIZZO DI CONSEGNA
    char zipCode[MAX_ZIPCODE_LENGTH];
    char province[MAX_PROVINCE_LENGTH];
} AddressDelivery;


void inputCreditCard();
void inputDeliveryAddress();
void createOrder();
int findLargestIdOrder();
int generateStatus();
void showUserOrders(char email[]);
void decrease_quantity(int id, int quantity);
void refundUserOrders(char email[]);

#endif //NEGOZIOABBIGLIAMENTO_PAYMENTDELIVERY_H
