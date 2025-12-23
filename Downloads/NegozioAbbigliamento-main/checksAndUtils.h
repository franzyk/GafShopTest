#ifndef CHECKSANDUTILS_H
#define CHECKSANDUTILS_H

#include <stdbool.h>

#define MAX_EMAIL_LENGTH 51
#define MIN_EMAIL_LENGHT 1
#define MAX_NAME_SURNAME_LENGTH 40
#define MAX_PASSWORD_LENGTH 22
#define MAX_PHONENUMBER_LENGTH 12
#define MAX_ADDRESS_LENGTH 80
#define MAX_ADDRESSNUMBER_LENGTH 10
#define MAX_GG_MM_LENGTH 4
#define MAX_AAAA_LENGTH 6
#define MAX_STATUS_WORD_LENGTH 20

#define MAX_LINE_LENGTH (MAX_EMAIL_LENGTH + MAX_PASSWORD_LENGTH + 2 * MAX_NAME_SURNAME_LENGTH + MAX_PHONENUMBER_LENGTH + MAX_ADDRESS_LENGTH + MAX_ADDRESSNUMBER_LENGTH + 2 * MAX_GG_MM_LENGTH + MAX_AAAA_LENGTH + 12)


void loading();
void refreshPage();
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
