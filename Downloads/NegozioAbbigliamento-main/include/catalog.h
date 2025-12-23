#ifndef CATALOG_H
#define CATALOG_H

#include "catalog.h"
#include <stdio.h>
#include "interface.h"
#include "checksAndUtils.h"
#include "navigation.h"
#include "config.h"


void catalog (unsigned short int selection);
void cart (unsigned short int location);
void idCartExtract();
void cartManager();


typedef struct {
    unsigned short int code;
    char name[MAX_PRODUCT_NAME];
    char brand[MAX_PRODUCT_BRAND];
    char description[MAX_PRODUCT_DESCRIPTION];
    char size[MAX_PRODUCT_SIZE];
    double price;
    int quantity;
} Product;



#endif /* CATALOG_H */
