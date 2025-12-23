#ifndef CHECKSANDUTILS_H
#define CHECKSANDUTILS_H

#include <stdbool.h>
#include "config.h"


int checkEmailDomain(char email[]);
int checkEmailNameLength(const char *string);
int emptyString(const char* string);
int checkNameSurname(const char* string);
int isEmailTaken(const char* email);
int checkPassword(const char *password);
int checkAddress(const char *address);
int checkAddressNumber(const char *addressNumber);
int isLeapYear(unsigned short int year);
int isValidDate(unsigned short int day, unsigned short int month, unsigned short int year);
int isAgeValid(unsigned short int day, unsigned short int month, unsigned short int year);
int checkEmailFirstChar(const char* string);
int checkPhoneNumber(const char PhoneNumber[]);
int checkEmailNameDomain(char email[]);
int isNumber(const char* str);
void emptyFile(const char* filename);
int checkQuantity(const char *qty, const int itemQty);
int checkCardDate(const int month, const int year);
int cardNumberCheck(const char* str);
int checkCVV(const char* number);
int checkCAP(const char* CAP);
char* getStatus(unsigned short int status);
int checkAdmin (const char * email);
int checkPercentage(const char coupon);
int checkItemSize(const char size[]);
int isDouble(const char price[]);


#endif // CHECKSANDUTILS_H
