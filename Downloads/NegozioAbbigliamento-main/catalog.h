#ifndef CATALOG_H
#define CATALOG_H

#include "catalog.h"
#include <stdio.h>
#include "interface.h"
#include "checksAndUtils.h"
#include "navigation.h"

#define CART_ITEMS 20
#define MAX_PRODUCT_NAME 50
#define MAX_PRODUCT_BRAND 30
#define MAX_PRODUCT_DESCRIPTION 500
#define MAX_PRODUCT_SIZE 10
#define MAX_CLOTHINGITEM_LENGTH (MAX_PRODUCT_NAME + MAX_PRODUCT_NAME + MAX_PRODUCT_SIZE + MAX_PRODUCT_SIZE)


void catalog (unsigned short int selection);
void cart (unsigned short int location);
void idCartExtract();
void cartManager();


typedef struct {
    unsigned short int code;
    char name[MAX_PRODUCT_NAME];
    char brand [MAX_PRODUCT_BRAND];
    char description[MAX_PRODUCT_DESCRIPTION];
    char size[MAX_PRODUCT_SIZE];
    double price;
    int quantity;
} ClothingItem;



#endif /* CATALOG_H */
